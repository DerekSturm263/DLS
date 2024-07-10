#include "miscellaneous/engine.hpp"

#include "miscellaneous/math_defines.hpp"
#include "systems/systems.hpp"
#include "modules/modules.hpp"

#include "types/core/project.hpp"

using dec = dls::math::decimal;
const glm::length_t dim = dls::math::dimensions;

using aud = dls::audio::systems::audio<dec>;
REGISTER_SYSTEM(aud);

using sim = dls::math::systems::simulation<dec, dim>;
REGISTER_SYSTEM(sim);

using tim = dls::time::systems::time<dec>;
REGISTER_SYSTEM(tim);

using phys = dls::math::modules::physics<dec, dim>;
REGISTER_MODULE(phys);

using strct = dls::math::modules::structure<dec, dim>;
REGISTER_MODULE(strct);

using trans = dls::math::modules::transform<dec, dim>;
REGISTER_MODULE(trans);

using inp = dls::input::modules::input<dec>;
REGISTER_MODULE(inp);

namespace dls::engine {
	int engine::execute(int argc, char* argv[]) {
		asset<core::types::entity> ety{ "assets/entity1.entity.asset", core::types::entity{
			"My Entity",
			graphics::modules::appearance{},
			inp{},
			phys{},
			strct{},
			trans{}
		} };

		asset<core::types::scene> scn{ "assets/scene1.scene.asset", core::types::scene{ std::vector<ref<core::types::entity>>{ ety.value() }}};

		asset<core::types::project> prj{ "assets/project1.project.asset", core::types::project{ std::vector<ref<core::types::scene>>{ scn.value() },
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

		return 0;
	}
}
