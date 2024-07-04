#pragma once

#include <vector>
#include <optional>
#include "interfaces/system.hpp"

namespace dls::systems::systems {
    class system_manager : public system {
        protected:
            void initialize() override;
            void on_scene_load() override;
            void on_tick(game::tick&) override;
            void on_scene_unload() override;
            void shutdown() override;

        private:
            std::vector<system*> _systems;

            friend class engine;

        public:
            system_manager(std::vector<system*> const& systems) : _systems(systems) { }

            template <typename T>
            std::optional<T*> get_system() {
                for (int i = 0; i < _systems.size(); ++i) {
                    T* ret = dynamic_cast<T*>(_systems[i]);

                    if (ret)
                        return std::optional<T*>(ret);
                }

                return std::optional<T*>();
            }
    };
}
