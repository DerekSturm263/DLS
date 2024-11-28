#pragma once

#include "types/core/module.hpp"
#include "types/math/transformation.hpp"
#include "wrappers/type.hpp"

namespace dls::math::functions {
	template <typename Decimal, glm::length_t Size>
	class set_position {};

	template <typename Decimal, glm::length_t Size>
	class set_rotation {};

	template <typename Decimal, glm::length_t Size>
	class set_scale {};
}

namespace dls::math::modules {
	template <typename Decimal, glm::length_t Size>
	class transform : public core::types::module<functions::set_position<Decimal, Size>, functions::set_rotation<Decimal, Size>, functions::set_scale<Decimal, Size>> {
		private:
			core::wrappers::type<types::transformation<Decimal, Size>> _transformation;

		public:
			transform() : _transformation() { }
			transform(core::wrappers::type<types::transformation<Decimal, Size>> const& transformation) : _transformation(transformation) { }

			core::wrappers::type<types::transformation<Decimal, Size>> const& transformation() const {
				return _transformation;
			}

			core::wrappers::type<types::transformation<Decimal, Size>>& transformation() {
				return _transformation;
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_transformation));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_transformation);
			}
	};

	using transform_t = transform<float, 3>;
}

REGISTER_MODULE("Transform", dls::math::modules::transform_t);
