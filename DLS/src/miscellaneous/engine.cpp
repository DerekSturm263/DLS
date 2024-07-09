#include "miscellaneous/engine.hpp"

#include "miscellaneous/math_defines.hpp"
#include "systems/systems.hpp"
#include "modules/modules.hpp"

#include "types/core/project.hpp"

using aud = dls::audio::systems::audio<dls::math::decimal>;
REGISTER_SYSTEM(aud);

using sim = dls::math::systems::simulation<dls::math::decimal, dls::math::dimensions>;
REGISTER_SYSTEM(sim);

using tim = dls::time::systems::time<dls::math::decimal>;
REGISTER_SYSTEM(tim);

using phys = dls::math::modules::physics<dls::math::decimal, dls::math::dimensions>;
REGISTER_MODULE(phys);

using strct = dls::math::modules::structure<dls::math::decimal, dls::math::dimensions>;
REGISTER_MODULE(strct);

using trans = dls::math::modules::transform<dls::math::decimal, dls::math::dimensions>;
REGISTER_MODULE(trans);

namespace dls::engine {
	int engine::execute(int argc, char* argv[]) {
		asset<core::types::entity> ety{ "assets/entity1.entity.asset", core::types::entity{
			graphics::modules::appearance{},
			input::modules::input{},
			phys{},
			strct{},
			trans{}
		} };

		asset<core::types::scene> scn{ "assets/scene1.scene.asset", core::types::scene{ std::vector<val<core::types::entity>>{ ety.value() }}};

		asset<core::types::project> prj{ "assets/project1.project.asset", core::types::project{ std::vector<val<core::types::scene>>{ scn.value() },
			aud{},
			debug::systems::debug{},
			graphics::systems::graphics{},
			input::systems::input{},
			math::systems::random{},
			core::systems::scene{},
			sim{},
			tim{},
			graphics::systems::window{}
		} };

		std::cout << "Project:" << std::endl;
		std::cout << prj.value() << std::endl;

		std::cout << "Scene:" << std::endl;
		std::cout << prj.value().scenes().at(0).value() << std::endl;

		std::cout << "Entity:" << std::endl;
		std::cout << prj.value().scenes().at(0).value().entities().at(0).value() << std::endl;
		
		return 0;
	}
}
