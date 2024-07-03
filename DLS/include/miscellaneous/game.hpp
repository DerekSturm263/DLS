#pragma once

#include "interfaces/singleton.hpp"
#include "save_data.hpp"

namespace dls {
	class game : public singleton<game> {
		private:
			save_data _save_data;

		public:
			save_data& save_data() {
				return _save_data;
			}
	};
}
