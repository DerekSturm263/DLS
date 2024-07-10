#pragma once

#include "tick.hpp"

namespace dls::game {
	class game {
		private:
			tick _tick;

		public:
			game() : _tick() { }

			tick& tick() {
				return _tick;
			}
	};
}
