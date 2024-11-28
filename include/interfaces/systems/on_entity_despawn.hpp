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
    class i_on_entity_despawn {
        private:
            static inline std::vector<i_on_entity_despawn*> _instances;

        public:
            i_on_entity_despawn() {
                _instances.push_back(this);
            }

            virtual void on_entity_despawn(miscellaneous::game& game, wrappers::ref<types::entity> const& entity) = 0;

            static std::vector<i_on_entity_despawn*> instances() {
                return _instances;
            }
    };
}
