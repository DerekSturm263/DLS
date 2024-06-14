#include "tick.hpp"

namespace dls {
	class engine_system {
        protected:
            virtual void initialize() = 0;
            virtual void update(tick&) = 0;
            virtual void shutdown() = 0;

            friend class engine_system_manager;
	};
}
