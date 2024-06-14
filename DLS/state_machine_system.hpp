#pragma once

#include "module_system.hpp"
#include "state_machine_agent.hpp"

namespace dls {
	class state_machine_system : public module_system<state_machine_agent> {
		protected:
            void on_scene_load(state_machine_agent&) override;
            void on_enable(state_machine_agent&) override;
            void on_start(state_machine_agent&) override;
            void on_tick(tick&, state_machine_agent&) override;
            void on_quit(state_machine_agent&) override;
            void on_disable(state_machine_agent&) override;
            void on_scene_unload(state_machine_agent&) override;
	};
}
