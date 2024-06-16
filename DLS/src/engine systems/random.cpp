#include "engine systems/random.hpp"

namespace dls {
	void random::initialize() {
		int seed = 0;
		_engine = std::default_random_engine(seed);
	}

	void random::update(tick& tick) {

	}

	void random::shutdown() {

	}
}
