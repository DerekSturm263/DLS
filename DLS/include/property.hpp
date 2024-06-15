#pragma once

#include <variant>
#include <tuple>
#include "serializable.hpp"
#include "type_templates.hpp"

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
#include "rect.hpp"
#include "state_machine.hpp"
#include "texture.hpp"
#include "variants.hpp"
#include "vector.hpp"

namespace dls {
	class property : public serializable {
		public:
			using any = std::variant<char, int, float, bool, std::string>;

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

			void save(os& file) const override {
				file(CEREAL_NVP(_value));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_value));
			}
			
		private:
			class stream_visitor {
				public:
					std::ostream& _os;

					stream_visitor(std::ostream& os) : _os(os) { }

					template <typename T>
					void operator()(T&& value) const {
						_os << value;
					}
			};

			friend std::ostream& operator<< (std::ostream& stream, const property& property) {
				std::visit(stream_visitor{stream}, property.value());
				return stream;
			}
	};
}
