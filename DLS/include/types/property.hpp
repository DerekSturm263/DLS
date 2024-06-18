#pragma once

#include <variant>
#include <tuple>
#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"

#include "animation.hpp"
#include "clip.hpp"
#include "color.hpp"
#include "entity.hpp"
#include "event.hpp"
#include "fixed.hpp"
#include "graph.hpp"
#include "input_button.hpp"
#include "mask.hpp"
#include "material.hpp"
#include "matrix.hpp"
#include "mesh.hpp"
#include "polygon.hpp"
#include "processor.hpp"
#include "quaternion.hpp"
#include "range.hpp"
#include "scene.hpp"
#include "state_machine.hpp"
#include "texture.hpp"
#include "transform.hpp"
#include "variants.hpp"
#include "vector.hpp"

namespace dls {
	class property : public serializable<property> {
		public:
			using any = std::variant<animation, clip, color, ref<entity>, fixed<32>, graph<fixed<32>>, input_button, material, mesh, ref<scene>, texture, std::string, int, bool>;

		private:
			val<any> _value;
			
		public:
			property() : _value() { }
			property(any const& value) : _value(value) { }

			any const& value() const {
				return _value.value();
			}

			any& value() {
				return _value.value();
			}

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_value));
			}

			void load(serializable_base::is& file) override {
				file(_value);
			}
			
		private:
			template <typename T>
			std::string to_string(T const& t) const {
				return t;
			}

			template <>
			std::string to_string<int>(int const& t) const {
				return std::to_string(t);
			}

			template <>
			std::string to_string<bool>(bool const& t) const {
				return std::to_string(t);
			}

		public:
			operator std::string() const override {
				std::string output = std::visit([&](auto&& arg) { return to_string(arg); }, value());
				return output;
			}

			template <typename T>
			property& operator= (T const& rhs) {
				_value.value() = rhs;
				return *this;
			}
	};
}
