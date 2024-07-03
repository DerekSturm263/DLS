#pragma once

#include "interfaces/system.hpp"
#include "modules/physics.hpp"
#include "miscellaneous/simulation_agent.hpp"
#include "types/vector.hpp"
#include "miscellaneous/tick.hpp"

namespace dls {
    class simulation : public system {
        protected:
            void initialize() override;
            void on_scene_load() override;
            void on_tick(tick&) override;
            void on_scene_unload() override;
            void shutdown() override;

        public:
            static void set_velocity(tick&, simulation_agent&, vector<fixed32, 3> const&);
            static void set_acceleration(tick&, simulation_agent&, vector<fixed32, 3> const&);
    };
}
