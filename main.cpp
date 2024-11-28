#include "miscellaneous/game.hpp"
#include "systems/debug.hpp"
#include "systems/graphics.hpp"
#include "systems/input.hpp"

int main(int argc, char** argv) {
    dls::core::types::entity ety1{ dls::miscellaneous::types::text{ "E1" }, dls::math::modules::transform_t{}, dls::graphics::modules::appearance{} };
    dls::core::wrappers::asset<dls::core::types::entity> ety1Asset{ "assets/entities/ety1.asset", std::move(ety1) };

    dls::core::types::entity ety2{ dls::miscellaneous::types::text{ "E2" }, dls::math::modules::transform_t{} };
    dls::core::wrappers::asset<dls::core::types::entity> ety2Asset{ "assets/entities/ety2.asset", std::move(ety2) };

    dls::core::types::entity ety3{ dls::miscellaneous::types::text{ "E3" }, dls::math::modules::transform_t{}, dls::graphics::modules::appearance{} };
    dls::core::wrappers::asset<dls::core::types::entity> ety3Asset{ "assets/entities/ety3.asset", std::move(ety3) };

    dls::core::types::entity ety4{ dls::miscellaneous::types::text{ "E4" }, dls::math::modules::transform_t{} };
    dls::core::wrappers::asset<dls::core::types::entity> ety4Asset{ "assets/entities/ety4.asset", std::move(ety4) };

    dls::collections::types::list<dls::core::wrappers::ref<dls::core::types::entity>> etys{
        dls::core::wrappers::ref<dls::core::types::entity>{ ety1Asset.value() },
        dls::core::wrappers::ref<dls::core::types::entity>{ ety2Asset.value() },
        dls::core::wrappers::ref<dls::core::types::entity>{ ety3Asset.value() },
        dls::core::wrappers::ref<dls::core::types::entity>{ ety4Asset.value() }
    };
    dls::core::types::scene scn{ etys, dls::core::types::window{ dls::miscellaneous::types::text{ "DLS Engine" }, dls::math::types::vector<dls::math::types::integer, 2>{ { 1920, 1080 } }, dls::graphics::types::color<float>{ 1, 1, 1, 1 } } };
    dls::core::wrappers::asset<dls::core::types::scene> scnAsset{ "assets/scenes/scene1.asset", std::move(scn) };
    
    dls::collections::types::list<dls::core::wrappers::ref<dls::core::types::scene>> scns{ dls::core::wrappers::ref<dls::core::types::scene>{ scnAsset.value() } };
    dls::core::types::project proj{ scns, dls::debug::systems::debug{ "build/debug_log.txt" }, dls::graphics::systems::graphics_t{}, dls::input::systems::input{} };  
    dls::core::wrappers::asset<dls::core::types::project> projAsset{ "assets/projects/proj1.asset", std::move(proj) };

    dls::miscellaneous::game game{ std::move(projAsset) };
    game.run();
}
