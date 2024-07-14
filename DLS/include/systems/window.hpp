#pragma once

#include "types/core/system.hpp"
#include "types/math/vector.hpp"

namespace dls::graphics::types {
	class texture;
}

namespace dls::graphics::functions {
	class open;
	class close;
}

namespace dls::graphics::systems {
	class window : public core::types::system<functions::open, functions::close> {
		private:
			core::wrappers::type<std::string> _title;
			core::wrappers::type<types::texture> _icon;
			core::wrappers::type<math::types::vector2<int>> _dimensions;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_title));
				file(CEREAL_NVP(_icon));
				file(CEREAL_NVP(_dimensions));
			}

			void load(is& file) override {
				file(_title);
				file(_icon);
				file(_dimensions);
			}

			void draw(std::string const& label) const override {
				_title.draw("Title");
				_icon.draw("Icon");
				_dimensions.draw("Dimensions");
			}
	};
}

namespace dls::graphics::functions {
	class open : public core::interfaces::function<void()> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<> const& args) const override {

			}
	};
	
	class close : public core::interfaces::function<void()> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<> const& args) const override {

			}
	};
}

REGISTER_SYSTEM("Window", dls::graphics::systems::window);
