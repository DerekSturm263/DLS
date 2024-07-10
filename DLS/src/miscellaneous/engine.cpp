#include "miscellaneous/engine.hpp"

#include "systems/systems.hpp"
#include "modules/modules.hpp"

#include "types/core/project.hpp"

namespace dls::engine {
	int engine::execute(int argc, char* argv[]) {
		core::wrappers::asset<core::types::entity> ety{ "assets/entity1.entity.asset", core::types::entity{
			"My Entity",
			graphics::modules::appearance{},
			input::modules::input_t{},
			simulation::modules::physics_t{},
			simulation::modules::structure_t{},
			math::modules::transform_t{}
		} };

		core::wrappers::asset<core::types::scene> scn{ "assets/scene1.scene.asset", core::types::scene{ std::vector<core::wrappers::ref<core::types::entity>>{ ety.value() }}};

		core::wrappers::asset<core::types::project> prj{ "assets/project1.project.asset", core::types::project{ std::vector<core::wrappers::ref<core::types::scene>>{ scn.value() },
			audio::systems::audio_t{},
			debug::systems::debug{},
			graphics::systems::graphics{},
			input::systems::input{},
			math::systems::random{},
			core::systems::scene{},
			simulation::systems::simulation_t{},
			time::systems::time_t{},
			graphics::systems::window{}
		} };

#if 0

		std::cout << ety.value() << std::endl;
		std::cout << scn.value() << std::endl;
		std::cout << prj.value() << std::endl;

#endif

		return 0;
	}
}
