#pragma once

#include "interfaces/serializable.hpp"

namespace dls {
	class shader : public serializable<shader> {
		public:
			void save(os& file) const override {
				
			}

			void load(is& file) override {
				
			}
	};
}