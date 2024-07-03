#include "functions/set_velocity.hpp"
#include "miscellaneous/simulation_agent.hpp"
#include "systems/simulation.hpp"
#include "types/vector.hpp"
#include "types/fixed.hpp"

namespace dls {
	void set_velocity::invoke(tick& tick, std::vector<void*> const& input, std::vector<void*>* output) {
		simulation_agent* rb = static_cast<simulation_agent*>(input[0]);
		vector<fixed32, 3>* vel = static_cast<vector<fixed32, 3>*>(input[1]);

		simulation::set_velocity(tick, *rb, *vel);
	}
}
