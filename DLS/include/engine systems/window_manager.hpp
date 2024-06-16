#pragma once

#include "interfaces/engine_system.hpp"

namespace dls {
	class window_manager : public engine_system {
        protected:
            void initialize() override;
            void update(tick&) override;
            void shutdown() override;
	};
}
