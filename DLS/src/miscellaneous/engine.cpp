#include "miscellaneous/engine.hpp"

#include "systems/systems.hpp"
#include "modules/modules.hpp"

namespace dls::engine {
	game::game _game{};

	int engine::execute(int argc, char* argv[]) {
		if (initialize(argc, argv)) {

		}

		shutdown();
		return 0;
	}

	bool engine::initialize(int argc, char* argv[]) {
		_game = game::game(core::wrappers::asset<core::types::project>{ "assets/project1.project.asset", core::types::project{ std::vector<core::wrappers::ref<core::types::scene>>{},
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
		} });

		return _game.system_manager().initialize(_game);
	}

	void engine::tick() {
		_game.system_manager().on_tick(_game);
	}

	void engine::shutdown() {
		_game.system_manager().shutdown(_game);
	}
}
