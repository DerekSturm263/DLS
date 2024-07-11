#pragma once

#include "system_manager.hpp"

namespace dls::engine {
	class engine {
		public:
			static int execute(int, char*[]);

		private:
			static systems::system_manager _manager;

			static bool initialize(int, char* []);
			static void tick(game::tick&);
			static void shutdown();
	};
}
