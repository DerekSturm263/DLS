#pragma once

#include "interfaces/system.hpp"

namespace dls::math::systems {
    template <typename Vector>
    class simulation : public system<simulation<Vector>> {

    };
}
