#pragma once

#include "interfaces/system.hpp"

namespace dls::math::systems {
	template <typename Decimal, glm::length_t Size>
	class simulation : public system<> {
		public:
			void save(os& file) const override {

			}

			void load(is& file) override {

			}
	};
}
