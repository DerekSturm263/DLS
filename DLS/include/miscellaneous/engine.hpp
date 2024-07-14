#pragma once

#include "game.hpp"

namespace dls::engine {
	class engine {
		public:
			static int execute(int, char*[]);

		private:
			static game::game _game;

			static void initialize(int, char*[]);
			static void tick();
			static void shutdown();
	};
}
