#pragma once

#include "interfaces/module_system.hpp"
#include "modules/physics.hpp"
#include "miscellaneous/simulation_agent.hpp"
#include "types/vector.hpp"
#include "miscellaneous/tick.hpp"

namespace dls {
    class physics_system : public module_system<physics> {
        protected:
            void on_scene_load(physics&) override;
            void on_enable(physics&) override;
            void on_start(physics&) override;
            void on_tick(tick&, physics&) override;
            void on_quit(physics&) override;
            void on_disable(physics&) override;
            void on_scene_unload(physics&) override;

        public:
            static void set_velocity(tick&, simulation_agent&, vector<fixed<32>, 3> const&);
            static void set_acceleration(tick&, simulation_agent&, vector<fixed<32>, 3> const&);
    };
}
