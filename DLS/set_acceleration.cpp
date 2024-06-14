#include "set_velocity.hpp"
#include "rigidbody.hpp"
#include "physics_system.hpp"
#include "vector.hpp"

namespace dls {
	void set_acceleration::invoke(tick& tick, std::vector<void*> const& args) {
		rigidbody* rigidbody = args[0];
		vector<fixed<32>, 3>* new_acceleration = args[1];

		physics_system::set_acceleration(tick, *rigidbody, *new_acceleration);
	}
}
