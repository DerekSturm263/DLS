#pragma once

#include "interfaces/serializable.hpp"

namespace dls {
	class mesh : public serializable {
		public:
			void save(os& file) const override {

			}

			void load(is& file) override {

			}
	};
}
