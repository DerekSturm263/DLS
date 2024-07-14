#pragma once

#include "types/core/module.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::miscellaneous::functions {
	template <typename T, typename Decimal>
	class emit : public core::interfaces::function<void(int)> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<int> const& args) const override {

			}
	};
}

namespace dls::miscellaneous::modules {
	template <typename T, typename Decimal>
	class emitter : public core::types::module<functions::emit<T, Decimal>> {
		private:
			core::wrappers::type<T> _object;
			core::wrappers::type<Decimal> _rate;
			core::wrappers::type<int> _max;

		public:
			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_object));
				file(CEREAL_NVP(_rate));
				file(CEREAL_NVP(_max));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_object);
				file(_rate);
				file(_max);
			}

			void draw(std::string const& label) const override {
				_object.draw("Object");
				_rate.draw("Rate");
				_max.draw("Max");
			}
	};
}
