#pragma once

#include "interfaces/serializable.hpp"

namespace dls::audio {
	class clip : public serializable<clip> {
		public:
			void save(os& file) const override {

			}

			void load(is& file) override {

			}
	};
}
