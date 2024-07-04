#pragma once

#include "interfaces/serializable.hpp"

namespace dls::graphics {
	class mesh : public serializable<mesh> {
		public:
			void save(os& file) const override {

			}

			void load(is& file) override {

			}
	};
}
