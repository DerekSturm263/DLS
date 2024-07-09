#pragma once

#include "types/input/input_trigger.hpp"

namespace dls::input::callbacks {
	template <typename Decimal>
	class input_callback_context {
		public:
			const types::input_trigger trigger;

			union {
				const bool boolean;
				const Decimal axis;
				const math::types::vector2<Decimal> vector;
			};
	};
}
