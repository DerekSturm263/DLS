#include "set_velocity.hpp"
#include "rigidbody.hpp"
#include "physics_system.hpp"
#include "vector.hpp"

namespace dls {
	void set_velocity::invoke(tick& tick, std::vector<void*> const& args) {
		rigidbody* rigidbody = args[0];
		vector<fixed<32>, 3>* new_velocity = args[1];

		physics_system::set_velocity(tick, *rigidbody, *new_velocity);
	}
}
