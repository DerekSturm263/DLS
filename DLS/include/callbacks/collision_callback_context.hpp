#pragma once

#include "types/core/entity.hpp"

namespace dls::math::callbacks {
	template <typename Decimal, glm::length_t Size>
	class collision_callback_context {
		private:
			core::types::entity const& _collider;
			core::types::entity const& _collidee;
			const types::vector<Decimal, Size> _contact_point;
	};
}
