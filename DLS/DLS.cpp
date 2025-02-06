#include "miscellaneous/game.hpp"
#include "systems/debug.hpp"
#include "systems/simulation.hpp"
#include "systems/graphics.hpp"
#include "systems/input.hpp"

int main(int argc, char** argv) {
    dls::core::types::entity ety1{ dls::miscellaneous::types::text{ "E1" },
        dls::math::modules::transform_t{},
        dls::graphics::modules::appearance{}
    };
    auto ety1Asset = dls::core::wrappers::asset_helper::make("assets/entities/ety1.asset", std::move(ety1));

    dls::core::types::entity ety2{ dls::miscellaneous::types::text{ "E2" } };
    auto ety2Asset = dls::core::wrappers::asset_helper::make("assets/entities/ety2.asset", std::move(ety2));

    dls::core::types::entity ety3{ dls::miscellaneous::types::text{ "E3" },
        dls::math::modules::transform_t{},
        dls::graphics::modules::appearance{}
    };
    auto ety3Asset = dls::core::wrappers::asset_helper::make("assets/entities/ety3.asset", std::move(ety3));

    dls::core::types::entity ety4{ dls::miscellaneous::types::text{ "E4" },
        dls::math::modules::transform_t{},
        dls::graphics::modules::appearance{},
        dls::simulation::modules::simulation_t{}
    };
    auto ety4Asset = dls::core::wrappers::asset_helper::make("assets/entities/ety4.asset", std::move(ety4));

    dls::collections::types::list<dls::core::wrappers::ref<dls::core::types::entity>> etys{
        dls::core::wrappers::ref_helper::make(ety1Asset.value()),
        dls::core::wrappers::ref_helper::make(ety2Asset.value()),
        dls::core::wrappers::ref_helper::make(ety3Asset.value()),
        dls::core::wrappers::ref_helper::make(ety4Asset.value())
    };
    dls::core::types::scene scn{ etys, dls::core::types::window{ dls::miscellaneous::types::text{ "DLS Engine" }, dls::math::types::vector<dls::math::types::integer, 2>{ { 1920, 1080 } }, dls::graphics::types::color<float>{ 1, 1, 1, 1 } } };
    auto scnAsset = dls::core::wrappers::asset_helper::make("assets/scenes/scene1.asset", std::move(scn));

    dls::collections::types::list<dls::core::wrappers::ref<dls::core::types::scene>> scns{
        dls::core::wrappers::ref_helper::make(scnAsset.value())
    };
    dls::core::types::project proj{ scns,
        dls::debug::systems::debug{ "build/debug_log.txt" },
        dls::simulation::systems::simulation_t{},
        dls::graphics::systems::graphics_t{},
        dls::input::systems::input{}
    };
    auto projAsset = dls::core::wrappers::asset_helper::make("assets/projects/proj1.asset", std::move(proj));

    dls::miscellaneous::game game{ std::move(projAsset) };
    game.run();
}
