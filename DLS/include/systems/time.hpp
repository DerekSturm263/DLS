#pragma once

#include "interfaces/system.hpp"

namespace dls::time::functions {
	template <typename Decimal>
	class set_scale : public function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}
	};
}

namespace dls::time::systems {
	template <typename Decimal>
	class time : public system<functions::set_scale<Decimal>> {
		private:
			Decimal _scale;

		public:
			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_scale));
			}

			void load(serializable_base::is& file) override {
				file(_scale);
			}
	};
}
