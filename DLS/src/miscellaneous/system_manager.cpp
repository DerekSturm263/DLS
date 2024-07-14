#include "miscellaneous/system_manager.hpp"

namespace dls::systems {
	void system_manager::initialize(game::game& game) {
		for (auto& system : _systems) {
			system->initialize(game);
		}
	}

	void system_manager::on_scene_load(game::game& game) {
		for (auto& system : _systems) {
			system->on_scene_load(game);
		}
	}

	void system_manager::on_tick(game::game& game) {
		for (auto& system : _systems) {
			system->on_tick(game);
		}
	}

	void system_manager::on_scene_unload(game::game& game) {
		for (auto& system : _systems) {
			system->on_scene_unload(game);
		}
	}

	void system_manager::shutdown(game::game& game) {
		for (auto& system : _systems) {
			system->shutdown(game);
		}
	}
}
