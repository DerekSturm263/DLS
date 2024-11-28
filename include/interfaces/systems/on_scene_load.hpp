#pragma once

#include <vector>
#include "wrappers/ref.hpp"

namespace dls::miscellaneous {
	class game;
}

namespace dls::core::types {
    class scene;
}

namespace dls::core::interfaces {
    class i_on_scene_load {
        private:
            static inline std::vector<i_on_scene_load*> _instances;

        public:
            i_on_scene_load() {
                _instances.push_back(this);
            }

            virtual void on_scene_load(miscellaneous::game& game, wrappers::ref<types::scene> const& scene) = 0;

            static std::vector<i_on_scene_load*> instances() {
                return _instances;
            }
    };
}
