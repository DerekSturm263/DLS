#include "systems/random.hpp"

namespace dls::math::systems {
	bool random::initialize() {
		_engine = std::default_random_engine{ _seed.value() };
		return true;
	}

	void random::shutdown() {

	}
}
