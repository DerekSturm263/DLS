#pragma once

namespace dls::game {
	class tick {
		private:
			unsigned long long _index;

		public:
			unsigned long long index() const {
				return _index;
			}
	};
}
