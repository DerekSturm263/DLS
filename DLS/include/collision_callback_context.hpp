#pragma once

#include "collision.hpp"
#include "vector.hpp"

namespace dls {
	class collision_callback_context {
		private:
			const collision& _collider;
			const collision& _collidee;
			const vector<fixed<32>, 3> _contact_point;
	};
}
