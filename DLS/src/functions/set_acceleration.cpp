#include "functions/set_acceleration.hpp"
#include "miscellaneous/simulation_agent.hpp"
#include "systems/simulation.hpp"
#include "types/vector.hpp"
#include "types/fixed.hpp"

namespace dls {
	void set_acceleration::invoke(tick& tick, std::vector<void*> const& input, std::vector<void*>* output) {
		simulation_agent* rb = static_cast<simulation_agent*>(input[0]);
		vector<fixed32, 3>* acc = static_cast<vector<fixed32, 3>*>(input[1]);

		simulation::set_acceleration(tick, *rb, *acc);
	}
}
