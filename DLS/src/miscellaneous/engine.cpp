#include "miscellaneous/engine.hpp"

#include "miscellaneous/game.hpp"

#include "systems/systems.hpp"
#include "type templates/type_templates.hpp"
#include "modules/modules.hpp"

#include "types/core/project.hpp"
#include "types/core/scene.hpp"
#include "types/core/entity.hpp"
#include "types/core/module.hpp"

namespace dls::engine {
	int engine::execute(int argc, char* argv[]) {
		game::game game = game::game{ std::vector<system*>{ new debug::systems::debug{} } };

		asset<core::entity> ety{ "assets/entity1.entity.asset", core::entity{ input::modules::input{} } };
		asset<core::scene> scn{ "assets/scene1.scene.asset", core::scene{ std::vector<val<core::entity>>{ ety.value() }}};
		asset<core::project> prj{ "assets/project1.project.asset", core::project{ std::vector<val<core::scene>>{ scn.value() }}};

		std::cout << ety.value().properties().at("name") << std::endl;

		return 0;
	}
}
