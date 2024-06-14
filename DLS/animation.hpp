#pragma once

#include <map>
#include "serializable.hpp"
#include "keyframe_data.hpp"

namespace dls {
	class animation : public serializable {
		private:
			std::map<std::size_t, keyframe_data> _keyframes;
	};
}
