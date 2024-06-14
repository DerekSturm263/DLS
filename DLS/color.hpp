#pragma once

#include "serializable.hpp"

namespace dls {
	class color : public serializable {
		private:
			char _vals[4];

		public:
			char r();
			char g();
			char b();
			char a();
	};
}
