#include "set_velocity.hpp"
#include "rigidbody.hpp"
#include "physics_system.hpp"
#include "vector.hpp"
#include "fixed.hpp"

namespace dls {
	void set_velocity::invoke(tick& tick, std::vector<void*> const& input, std::vector<void*>* output) {
		rigidbody* rb = static_cast<rigidbody*>(input[0]);
		vector<fixed<32>, 3>* vel = static_cast<vector<fixed<32>, 3>*>(input[1]);

		physics_system::set_velocity(tick, *rb, *vel);
	}
}
