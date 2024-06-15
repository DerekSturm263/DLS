#pragma once

#include "engine_system.hpp"

namespace dls {
	class time : public engine_system {
        protected:
            void initialize() override;
            void update(tick&) override;
            void shutdown() override;
	};
}
