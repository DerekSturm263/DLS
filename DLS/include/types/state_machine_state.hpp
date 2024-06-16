#pragma once

#include "interfaces/serializable.hpp"

namespace dls {
	template <typename T>
	class state_machine_state : public serializable {
		private:
			type<T> _value;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_value));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_value));
			}
	};
}
