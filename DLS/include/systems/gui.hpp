#pragma once

#include "interfaces/system.hpp"

namespace dls {
	class gui : public system {
        private:
            void initialize() override;
            void on_scene_load() override;
            void on_tick(tick&) override;
            void on_scene_unload() override;
            void shutdown() override;
	};
}
