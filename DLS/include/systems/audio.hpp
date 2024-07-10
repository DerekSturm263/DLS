#pragma once

#include "interfaces/system.hpp"

namespace dls::audio::functions {
    template <typename Decimal>
	class play : public function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}
	};
}

namespace dls::audio::systems {
    template <typename Decimal>
	class audio : public system<functions::play<Decimal>> {
        private:
            Decimal _volume;

        public:
            void save(serializable_base::os& file) const override {
                file(CEREAL_NVP(_volume));
            }

            void load(serializable_base::is& file) override {
                file(_volume);
            }
	};
}
