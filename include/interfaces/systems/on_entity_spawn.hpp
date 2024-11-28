#pragma once

#include <vector>
#include "wrappers/ref.hpp"

namespace dls::miscellaneous {
	class game;
}

namespace dls::core::types {
    class entity;
}

namespace dls::core::interfaces {
    class i_on_entity_spawn {
        private:
            static inline std::vector<i_on_entity_spawn*> _instances;

        public:
            i_on_entity_spawn() {
                _instances.push_back(this);
            }

            virtual void on_entity_spawn(miscellaneous::game& game, wrappers::ref<types::entity> const& entity) = 0;

            static std::vector<i_on_entity_spawn*> instances() {
                return _instances;
            }
    };
}
