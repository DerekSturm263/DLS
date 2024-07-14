#pragma once

#include "miscellaneous/math_defines.hpp"
#include "types/core/module.hpp"
#include "types/math/transform.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::math::functions {
	template <typename Decimal, glm::length_t Size>
	class set_position;

	template <typename Decimal, glm::length_t Size>
	class set_rotation;

	template <typename Decimal, glm::length_t Size>
	class set_scale;
}

namespace dls::math::modules {
	template <typename Decimal, glm::length_t Size>
	class transform : public core::types::module<functions::set_position<Decimal, Size>, functions::set_rotation<Decimal, Size>, functions::set_scale<Decimal, Size>> {
		private:
			core::wrappers::type<types::transform<Decimal, Size>> _transform;

		public:
			transform() : _transform() { }

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_transform));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_transform);
			}

			void draw(std::string const& label) const override {
				_transform.draw("Transform");
			}
	};

	using transform_t = transform<math::decimal, math::dimensions>;
}

namespace dls::math::functions {
	template <typename Decimal, glm::length_t Size>
	class set_position : public core::interfaces::function<void(math::types::vector<Decimal, Size>)> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<math::types::vector<Decimal, Size>> const& args) const override {

			}
	};

	template <typename Decimal, glm::length_t Size>
	class set_rotation : public core::interfaces::function<void(math::types::vector<Decimal, Size>)> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<math::types::vector<Decimal, Size>> const& args) const override {

			}
	};

	template <typename Decimal, glm::length_t Size>
	class set_scale : public core::interfaces::function<void(math::types::vector<Decimal, Size>)> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<math::types::vector<Decimal, Size>> const& args) const override {

			}
	};
}

REGISTER_MODULE("Transform", dls::math::modules::transform_t);
