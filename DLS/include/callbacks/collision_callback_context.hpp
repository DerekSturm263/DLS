#pragma once

#include "types/core/entity.hpp"

namespace dls::simulation::callbacks {
	template <typename Decimal, glm::length_t Size>
	class collision_callback_context {
		public:
			core::types::entity const& collider;
			core::types::entity const& collidee;
			const math::types::vector<Decimal, Size> contact_point;
	};
}
