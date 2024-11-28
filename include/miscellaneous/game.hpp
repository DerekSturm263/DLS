#pragma once

#include "wrappers/asset.hpp"
#include "types/core/project.hpp"

namespace dls::miscellaneous {
	class game {
        private:
            core::wrappers::asset<core::types::project> _project;

            std::set<core::types::scene*> _loaded_scenes;
            std::set<core::types::entity*> _loaded_entities;

		public:
        	game(core::wrappers::asset<core::types::project> const& project) = delete;
			game(core::wrappers::asset<core::types::project>&& project) : _project(std::move(project)), _loaded_scenes(), _loaded_entities() { }

            void run();
            
            void load_scene(core::wrappers::ref<core::types::scene>& scene);
            void unload_scene(core::wrappers::ref<core::types::scene>& scene);

            void spawn_entity(core::wrappers::ref<core::types::entity>& entity);
            void despawn_entity(core::wrappers::ref<core::types::entity>& entity);

            template <typename... Ts>
            std::vector<std::tuple<core::types::entity const&, Ts& ...>> filter() {
                using tuple_type = std::tuple<core::types::entity const&, Ts& ...>;
                using ret_type = std::vector<tuple_type>;

                ret_type ret{};

                for (auto& entity : _loaded_entities) {
                    auto module = entity->get_modules<Ts...>();

                    /*if (module.has_value()) {
                        ret.push_back(module.value());
                    }*/
                }

                return ret;
            }

        private:
            void initialize_all();
            void tick_all();
            void update_all();
            void shutdown_all();
	};
}
