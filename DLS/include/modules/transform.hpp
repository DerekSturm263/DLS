#pragma once

#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/math/transform.hpp"
#include "types/math/fixed.hpp"

namespace dls::math::functions {
	template <typename Decimal, glm::length_t Size>
	class set_position : public function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}
	};

	template <typename Decimal, glm::length_t Size>
	class set_rotation : public function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}
	};

	template <typename Decimal, glm::length_t Size>
	class set_scale : public function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}
	};
}

namespace dls::math::modules {
	template <typename Decimal, glm::length_t Size>
	class transform : public core::types::module<functions::set_position<Decimal, Size>, functions::set_rotation<Decimal, Size>, functions::set_scale<Decimal, Size>> {
		private:
			type<types::transform<Decimal, Size>> _transform;

		public:
			transform() : _transform() { }

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_transform));
			}

			void load(serializable_base::is& file) override {
				file(_transform);
			}
	};
}
