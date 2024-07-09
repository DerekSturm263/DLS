#pragma once

#include "interfaces/serializable.hpp"
#include "interfaces/system.hpp"

namespace dls::audio::systems {
    template <typename Decimal>
	class audio : public system<> {
        private:
            Decimal _volume;

        public:
            void save(os& file) const override {
                file(CEREAL_NVP(_volume));
            }

            void load(is& file) override {
                file(_volume);
            }
	};
}
