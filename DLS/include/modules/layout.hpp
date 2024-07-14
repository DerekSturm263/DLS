#pragma once

#include "miscellaneous/math_defines.hpp"
#include "types/core/module.hpp"
#include "types/math/vector.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::math::functions {
	template <glm::length_t Size>
	class get_from_position : public core::interfaces::function<void(math::types::vector<int, Size>)> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<math::types::vector<int, Size>> const& args) const override {

			}
	};
}

namespace dls::math::modules {
	template <typename Decimal, glm::length_t Size>
	class layout : public core::types::module<functions::get_from_position<Size>> {
		private:
			core::wrappers::type<types::vector<int, Size>> _dimensions;
			core::wrappers::type<types::vector<Decimal, Size>> _spacing;

		public:
			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_dimensions));
				file(CEREAL_NVP(_spacing));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_dimensions);
				file(_spacing);
			}

			void draw(std::string const& label) const override {
				_dimensions.draw("Dimensions");
				_spacing.draw("Spacing");
			}
	};

	using layout_t = layout<math::decimal, math::dimensions>;
}

REGISTER_MODULE("Layout", dls::math::modules::layout_t);
