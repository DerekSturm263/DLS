#pragma once

#include "miscellaneous/math_defines.hpp"
#include "types/core/system.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::audio::functions {
    template <typename Decimal>
	class play : public core::interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

            void draw(std::string const& label) const override {

            }
	};
}

namespace dls::audio::systems {
    template <typename Decimal>
	class audio : public core::types::system<functions::play<Decimal>> {
        private:
            core::wrappers::type<Decimal> _volume;

        public:
            void save(core::interfaces::serializable_base::os& file) const override {
                file(CEREAL_NVP(_volume));
            }

            void load(core::interfaces::serializable_base::is& file) override {
                file(_volume);
            }

            void draw(std::string const& label) const override {
                _volume.draw("Volume");
            }
	};

    using audio_t = audio<math::decimal>;
}

REGISTER_SYSTEM("Audio", dls::audio::systems::audio_t);
