#include "engine.hpp"
#include "data holders/save_data.hpp"
#include "type templates/type_templates.hpp"
#include "modules/modules.hpp"
#include "types/project.hpp"
#include "types/scene.hpp"
#include "types/entity.hpp"
#include "types/module.hpp"

namespace dls {
	int engine::execute(int argc, char* argv[]) {
		asset<entity> ety{ "assets/entity1.entity.asset", entity{ appearance{}, emitter{}, input{}, layout{}, physics{}, receiver{}, sender{}, state_machine_resolver{}, structure{}, timer{}, transformer{}, ui_element{} } };
		asset<scene> scn{ "assets/scene1.scene.asset", scene{ std::vector<val<entity>>{ ety.value() }}};
		asset<project> prj{ "assets/project1.project.asset", project{ std::vector<val<scene>>{ scn.value() }}};

		instance<entity> inst{ ety };

		auto& props = inst.value().properties();
		props.value()->at("name") = "Neko";
		props.value()->at("age") = 21;

		std::cout << ety.value() << std::endl;
		std::cout << scn.value() << std::endl;
		std::cout << prj.value() << std::endl;

		return 0;
	}
}
