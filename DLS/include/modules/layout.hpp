#pragma once

#include "miscellaneous/math_defines.hpp"
#include "types/core/module.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::math::functions {
	class get_from_position : public core::interfaces::function<std::tuple<>, std::tuple<>> {
		public:
			void invoke(game::game& game, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};
}

namespace dls::math::modules {
	template <typename Decimal, glm::length_t Size>
	class layout : public core::types::module<functions::get_from_position> {
		private:
			core::wrappers::type<types::vector<int, Size>> _dimensions;
			core::wrappers::type<types::vector<Decimal, Size>> _spacing;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_dimensions));
			}

			void load(is& file) override {
				file(_dimensions);
			}

			void draw(std::string const& label) const override {
				_dimensions.draw("Dimensions");
				_spacing.draw("Spacing");
			}
	};

	using layout_t = layout<math::decimal, math::dimensions>;
}

REGISTER_MODULE("Layout", dls::math::modules::layout_t);
