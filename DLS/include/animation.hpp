#pragma once

#include <map>
#include "serializable.hpp"
#include "keyframe_data.hpp"

namespace dls {
	class animation : public serializable {
		private:
			std::map<std::size_t, keyframe_data> _keyframes;
			
		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_keyframes));
			}

			void load(is& file) override {
				file(_keyframes);
			}
	};
}
