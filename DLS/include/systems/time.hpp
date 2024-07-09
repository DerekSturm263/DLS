#pragma once

#include "interfaces/system.hpp"

namespace dls::time::systems {
	template <typename Decimal>
	class time : public system<> {
		private:
			Decimal _scale;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_scale));
			}

			void load(is& file) override {
				file(_scale);
			}
	};
}
