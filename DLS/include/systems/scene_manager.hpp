#pragma once

#include "interfaces/system.hpp"

namespace dls::core::systems {
	class scene_manager : public system {
        protected:
            void initialize() override;
            void on_scene_load() override;
            void on_tick(game::tick&) override;
            void on_scene_unload() override;
            void shutdown() override;
	};
}
