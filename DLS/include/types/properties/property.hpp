#pragma once

#include <variant>
#include <tuple>
#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"

#include "../animation/animation.hpp"
#include "../audio/clip.hpp"
#include "../events/event.hpp"
#include "../math/fixed.hpp"
#include "../graphs/graph.hpp"
#include "../input/input_trigger.hpp"
#include "../input/input_event_group.hpp"
#include "../nodes/node_group.hpp"
#include "../shapes/polygon.hpp"
#include "../miscellaneous/mask.hpp"
#include "../miscellaneous/processor.hpp"
#include "../miscellaneous/variants.hpp"
#include "../graphics/color.hpp"
#include "../graphics/material.hpp"
#include "../graphics/mesh.hpp"
#include "../graphics/shader.hpp"
#include "../graphics/texture.hpp"
#include "../state machines/state_machine.hpp"
#include "../math/matrix.hpp"
#include "../math/quaternion.hpp"
#include "../math/range.hpp"
#include "../math/transform.hpp"
#include "../math/vector.hpp"

namespace dls::properties::types {
	class property : public core::interfaces::serializable<property> {
		public:
			using any = std::variant<animation::types::animation, audio::types::clip, input::types::input_trigger, graphics::types::material, graphics::types::mesh, graphics::types::texture, std::string, int, bool>;

		private:
			core::wrappers::val<any> _value;
			
		public:
			property() : _value() { }
			property(any const& value) : _value(value) { }

			any const& value() const {
				return _value.value();
			}

			any& value() {
				return _value.value();
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_value));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_value);
			}

			void draw(std::string const& label) const override {

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
			std::string to_string<long long>(long long const& t) const {
				return std::to_string(t);
			}

			template <>
			std::string to_string<float>(float const& t) const {
				return std::to_string(t);
			}

			template <>
			std::string to_string<double>(double const& t) const {
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
