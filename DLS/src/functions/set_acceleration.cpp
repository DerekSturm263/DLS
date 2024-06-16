#include "functions/set_acceleration.hpp"
#include "miscellaneous/rigidbody.hpp"
#include "module systems/physics_system.hpp"
#include "types/vector.hpp"
#include "types/fixed.hpp"

namespace dls {
	void set_acceleration::invoke(tick& tick, std::vector<void*> const& input, std::vector<void*>* output) {
		rigidbody* rb = static_cast<rigidbody*>(input[0]);
		vector<fixed<32>, 3>* acc = static_cast<vector<fixed<32>, 3>*>(input[1]);

		physics_system::set_acceleration(tick, *rb, *acc);
	}
}
