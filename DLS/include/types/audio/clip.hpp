#pragma once

#include "interfaces/serializable.hpp"

namespace dls::audio::types {
	class clip : public core::interfaces::serializable<clip> {
		public:
			void save(core::interfaces::serializable_base::os& file) const override {

			}

			void load(core::interfaces::serializable_base::is& file) override {

			}

			void draw(std::string const& label) const override {

			}
	};
}
