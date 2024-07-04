#pragma once

#include "interfaces/singleton.hpp"
#include "save_data.hpp"
#include "systems/system_manager.hpp"
#include "tick.hpp"

namespace dls::game {
	class game : public singleton<game> {
		private:
			systems::systems::system_manager _system_manager;
			save_data _save_data;

		public:
			game(std::vector<system*> const& systems) : singleton(*this), _system_manager(systems), _save_data() { }

			systems::systems::system_manager system_manager() {
				return _system_manager;
			}

			save_data& save_data() {
				return _save_data;
			}

			tick get_tick() {
				return tick{};
			}
	};
}
