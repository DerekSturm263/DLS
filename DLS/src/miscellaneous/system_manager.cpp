#include "miscellaneous/system_manager.hpp"

namespace dls::systems {
	bool system_manager::initialize() {
		for (auto& system : _systems) {
			if (!system->initialize())
				return false;
		}

		return true;
	}

	void system_manager::on_scene_load() {
		for (auto& system : _systems) {
			system->on_scene_load();
		}
	}

	void system_manager::on_tick(game::tick& tick) {
		for (auto& system : _systems) {
			system->on_tick(tick);
		}
	}

	void system_manager::on_scene_unload() {
		for (auto& system : _systems) {
			system->on_scene_unload();
		}
	}

	void system_manager::shutdown() {
		for (auto& system : _systems) {
			system->shutdown();
		}
	}
}
