#include "set_velocity.hpp"
#include "rigidbody.hpp"
#include "physics_system.hpp"
#include "vector.hpp"

namespace dls {
	void set_velocity::invoke(tick& tick, std::vector<void*> const& args) {
		rigidbody* rb = static_cast<rigidbody*>(args[0]);
		vector<fixed<32>, 3>* vel = static_cast<vector<fixed<32>, 3>*>(args[1]);

		physics_system::set_velocity(tick, *rb, *vel);
	}
}
