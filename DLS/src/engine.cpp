#include "miscellaneous/engine.hpp"

#include "miscellaneous/game.hpp"
#include "type templates/type_templates.hpp"
#include "modules/modules.hpp"
#include "types/project.hpp"
#include "types/scene.hpp"
#include "types/entity.hpp"
#include "types/module.hpp"

namespace dls {
	int engine::execute(int argc, char* argv[]) {
		asset<entity> ety{ "assets/entity1.entity.asset", entity{ input{} } };
		asset<scene> scn{ "assets/scene1.scene.asset", scene{ std::vector<val<entity>>{ ety.value() }}};
		asset<project> prj{ "assets/project1.project.asset", project{ std::vector<val<scene>>{ scn.value() }}};

		return 0;
	}
}
