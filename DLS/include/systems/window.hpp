#pragma once

#include "type templates/ref.hpp"
#include "types/graphics/texture.hpp"
#include "interfaces/system.hpp"

namespace dls::graphics::systems {
	class window : public system<> {
		private:
			std::string _window_title;
			ref<types::texture> _icon;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_window_title));
				file(CEREAL_NVP(_icon));
			}

			void load(is& file) override {
				file(_window_title);
				file(_icon);
			}
	};
}
