#pragma once

#include "types/entity.hpp"
#include "types/vector.hpp"

namespace dls {
	class collision_callback_context {
		private:
			entity const& _collider;
			entity const& _collidee;
			const vector<fixed32, 3> _contact_point;
	};
}
