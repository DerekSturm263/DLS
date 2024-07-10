#include "systems/random.hpp"

namespace dls::math::systems {
	void random::initialize() {
		_engine = std::default_random_engine(_seed.value());
	}

	void random::shutdown() {

	}
}
