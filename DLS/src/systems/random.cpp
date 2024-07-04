#include "systems/random.hpp"

namespace dls::math::systems {
	void random::initialize() {
		int seed = 0;
		_engine = std::default_random_engine(seed);
	}

	void random::shutdown() {

	}
}
