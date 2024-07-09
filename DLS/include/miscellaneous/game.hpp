#pragma once

#include "save_data.hpp"
#include "systems/system_manager.hpp"
#include "tick.hpp"

namespace dls::game {
	class game {
		private:
			systems::systems::system_manager _system_manager;
			save_data _save_data;
			tick _tick;

		public:
			game(std::vector<system_base*> const& systems) : _system_manager(systems), _save_data() { }

			systems::systems::system_manager system_manager() {
				return _system_manager;
			}

			save_data& save_data() {
				return _save_data;
			}

			tick& tick() {
				return _tick;
			}
	};
}
