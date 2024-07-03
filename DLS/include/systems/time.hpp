#pragma once

#include "interfaces/system.hpp"

namespace dls {
	class time : public system {
        protected:
            void initialize() override;
            void on_scene_load() override;
            void on_tick(tick&) override;
            void on_scene_unload() override;
            void shutdown() override;
	};
}
