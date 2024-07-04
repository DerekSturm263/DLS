#pragma once

#include "interfaces/system.hpp"
#include "modules/physics.hpp"
#include "miscellaneous/simulation_agent.hpp"
#include "types/math/vector.hpp"
#include "miscellaneous/tick.hpp"
#include "miscellaneous/math_defines.hpp"

namespace dls::math::systems {
    template <typename Vector>
    class simulation : public system {
        protected:
            void initialize() override;
            void on_scene_load() override;
            void on_tick(game::tick&) override;
            void on_scene_unload() override;
            void shutdown() override;

        public:
            static void set_velocity(game::tick& tick, simulation_agent& agent, Vector const& velocity) {

            }

            static void set_acceleration(game::tick& tick, simulation_agent& agent, Vector const& acceleration) {

            }
    };
}
