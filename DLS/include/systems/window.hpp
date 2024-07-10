#pragma once

#include "types/graphics/texture.hpp"
#include "types/core/system.hpp"

namespace dls::graphics::functions {
	class open : public core::interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};
	
	class close : public core::interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};
}

namespace dls::graphics::systems {
	class window : public core::types::system<functions::open, functions::close> {
		private:
			core::wrappers::type<std::string> _title;
			core::wrappers::type<types::texture> _icon;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_title));
				file(CEREAL_NVP(_icon));
			}

			void load(is& file) override {
				file(_title);
				file(_icon);
			}

			void draw(std::string const& label) const override {
				_title.draw("Title");
				_icon.draw("Icon");
			}
	};
}

REGISTER_SYSTEM("Window", dls::graphics::systems::window);
