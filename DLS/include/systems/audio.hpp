#pragma once

#include "interfaces/serializable.hpp"
#include "interfaces/system.hpp"

namespace dls::audio::systems {
	class audio : public system<audio>, public serializable<system<audio>> {

	};
}
