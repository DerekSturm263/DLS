#pragma once

#include "miscellaneous/math_defines.hpp"
#include "types/core/system.hpp"

namespace dls::time::functions {
	template <typename Decimal>
	class set_scale;
}

namespace dls::time::systems {
	template <typename Decimal>
	class time : public core::types::system<functions::set_scale<Decimal>> {
		private:
			core::wrappers::type<Decimal> _scale;
			core::wrappers::type<unsigned int> _tick_rate;

		public:
			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_scale));
				file(CEREAL_NVP(_tick_rate));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_scale);
				file(_tick_rate);
			}

			void draw(std::string const& label) const override {
				_scale.draw("Scale");
				_tick_rate.draw("Tick Rate");
			}
	};

	using time_t = time<math::decimal>;
}

namespace dls::time::functions {
	template <typename Decimal>
	class set_scale : public core::interfaces::function<void()> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<> const& args) const override {

			}
	};
}

REGISTER_SYSTEM("Time", dls::time::systems::time_t);
