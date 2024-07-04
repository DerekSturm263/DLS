#pragma once

#include "types/core/entity.hpp"

namespace dls {
	template <typename Vector>
	class collision_callback_context {
		private:
			core::entity const& _collider;
			core::entity const& _collidee;
			const Vector _contact_point;
	};
}
