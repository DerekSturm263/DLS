#pragma once

#include "interfaces/serializable.hpp"

namespace dls::animation {
	class keyframe_data : public serializable<keyframe_data> {
		public:
			void save(os& file) const override {

			}

			void load(is& file) override {

			}
	};
}
