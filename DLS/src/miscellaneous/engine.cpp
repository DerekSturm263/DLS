#include "miscellaneous/engine.hpp"

#include "systems/systems.hpp"
#include "modules/modules.hpp"

#include "types/core/project.hpp"

namespace dls::engine {
	systems::system_manager engine::_manager{};

	int engine::execute(int argc, char* argv[]) {
		if (initialize(argc, argv)) {

		}

		shutdown();
		return 0;
	}

	bool engine::initialize(int argc, char* argv[]) {
		core::wrappers::asset<core::types::project> project{ "assets/project1.project.asset", core::types::project{ std::vector<core::wrappers::ref<core::types::scene>>{},
			audio::systems::audio_t{},
			debug::systems::debug{},
			graphics::systems::graphics_t{},
			input::systems::input{},
			math::systems::random{},
			serialization::systems::save_data{},
			core::systems::scene{},
			simulation::systems::simulation_t{},
			time::systems::time_t{},
			graphics::systems::window{}
		} };

		_manager = systems::system_manager{ project.value().value().systems() };

		return _manager.initialize();
	}

	void engine::tick(game::tick& tick) {
		_manager.on_tick(tick);
	}

	void engine::shutdown() {
		_manager.shutdown();
	}
}
