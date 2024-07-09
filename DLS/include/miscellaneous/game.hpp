#pragma once

#include "save_data.hpp"
#include "tick.hpp"

namespace dls::game {
	class game {
		private:
			save_data _save_data;
			tick _tick;

		public:
			game() : _save_data() { }

			save_data& save_data() {
				return _save_data;
			}

			tick& tick() {
				return _tick;
			}
	};
}
