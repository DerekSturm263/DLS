#pragma once

#include <map>
#include "interfaces/serializable.hpp"
#include "keyframe_data.hpp"

namespace dls::animation {
	class animation : public serializable<animation> {
		private:
			std::map<std::size_t, keyframe_data> _keyframes;
			
		public:
			animation() : _keyframes() {}
			animation(std::map<std::size_t, keyframe_data> const& keyframes) : _keyframes(keyframes) {}

			void save(os& file) const override {
				file(CEREAL_NVP(_keyframes));
			}

			void load(is& file) override {
				file(_keyframes);
			}
	};
}
