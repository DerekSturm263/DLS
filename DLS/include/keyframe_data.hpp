#pragma once

#include "serializable.hpp"

namespace dls {
	class keyframe_data : public serializable {
		public:
			void save(os& file) const override {

			}

			void load(is& file) override {

			}
	};
}
