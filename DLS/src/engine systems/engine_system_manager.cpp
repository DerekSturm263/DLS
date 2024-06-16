#include "engine systems/engine_system_manager.hpp"

namespace dls {
	engine_system_manager::engine_system_manager(std::vector<engine_system*> const& systems) : _systems(systems) { }

	void engine_system_manager::initialize() {
		for (auto& system : _systems) {
			system->initialize();
		}
	}

	void engine_system_manager::update(tick& tick) {
		for (auto& system : _systems) {
			system->update(tick);
		}
	}

	void engine_system_manager::shutdown() {
		for (auto& system : _systems) {
			system->shutdown();
		}
	}
}
