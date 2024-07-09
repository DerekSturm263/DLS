#pragma once

#include "interfaces/system.hpp"

namespace dls::graphics::systems {
	class window : public system<> {
		private:
			std::string _window_title;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_window_title));
			}

			void load(is& file) override {
				file(_window_title);
			}
	};
}
