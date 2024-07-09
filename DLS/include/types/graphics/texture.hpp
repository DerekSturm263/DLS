#pragma once

#include "interfaces/serializable.hpp"

namespace dls::graphics::types {
	class texture : public serializable<texture> {
		public:
			void save(os& file) const override {

			}

			void load(is& file) override {

			}
	};
}
