#include "miscellaneous/game.hpp"

#include <algorithm>
#include <GLFW/glfw3.h>
#include "types/core/window.hpp"
#include "interfaces/systems/on_scene_load.hpp"
#include "interfaces/systems/on_scene_unload.hpp"
#include "interfaces/systems/on_entity_spawn.hpp"
#include "interfaces/systems/on_entity_despawn.hpp"

namespace dls::miscellaneous {
    void game::run() {
        initialize_all();

        load_scene(_project.value().value().scenes().value().at(0).value());

        for (auto* window : dls::core::types::window::_active_windows) {
            /*while (!glfwWindowShouldClose(window)) {
                tick_all();
                update_all();

                glfwSwapBuffers(window);
                glfwPollEvents();
            }*/
        }

        shutdown_all();
    }

    void game::load_scene(core::types::scene& scene) {
        _loaded_scenes.insert(&scene);

        for (auto& entity : scene.entities().value()) {
            spawn_entity(entity.value());
        }

        for (auto& system : core::interfaces::i_on_scene_load::instances()) {
            system->on_scene_load(*this, scene);
        }

        scene.window().create();
    }

    void game::unload_scene(core::types::scene& scene) {
        for (auto& entity : scene.entities().value()) {
            despawn_entity(entity.value());
        }

        auto systems = core::interfaces::i_on_scene_unload::instances();
        std::reverse(systems.begin(), systems.end());

        for (auto& system : systems) {
            system->on_scene_unload(*this, scene);
        }

        scene.window().destroy();

        _loaded_scenes.erase(&scene);
    }

    void game::spawn_entity(core::types::entity& entity) {
        _loaded_entities.insert(&entity);

        for (auto& system : core::interfaces::i_on_entity_spawn::instances()) {
            system->on_entity_spawn(*this, entity);
        }
    }

    void game::despawn_entity(core::types::entity& entity) {
        auto systems = core::interfaces::i_on_entity_despawn::instances();
        std::reverse(systems.begin(), systems.end());

        for (auto& system : systems) {
            system->on_entity_despawn(*this, entity);
        }

        _loaded_entities.erase(&entity);
    }

    void game::initialize_all() {
        for (auto& system : _project.value().value().systems()) {
            system->initialize(*this);
        }
    }

    void game::tick_all() {
        for (auto& system : _project.value().value().systems()) {
            system->tick(*this);
        }
    }

    void game::update_all() {
        for (auto& system : _project.value().value().systems()) {
            system->update();
        }
    }

    void game::shutdown_all() {
        auto systems = _project.value().value().systems();
        std::reverse(systems.begin(), systems.end());

        for (auto& system : systems) {
            system->shutdown(*this);
        }
    }
}
