#pragma once

#include "interfaces/serializable.hpp"

namespace dls::animation::types {
	class keyframe_data : public core::interfaces::serializable<keyframe_data> {
		public:
			void save(core::interfaces::serializable_base::os& file) const override {

			}

			void load(core::interfaces::serializable_base::is& file) override {

			}

			void draw(std::string const& label) const override {

			}
	};
}
