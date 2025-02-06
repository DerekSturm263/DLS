#pragma once

#include "interfaces/serializable.hpp"
#include "wrappers/val.hpp"
#include "wrappers/ref.hpp"
#include "types/core/entity.hpp"
#include "types/miscellaneous/text.hpp"
#include "types/math/integer.hpp"
#include "types/math/vector.hpp"
#include "types/graphics/color.hpp"

struct GLFWwindow;

namespace dls::core::types {
	class window : public interfaces::serializable<window> {
		private:
		    core::wrappers::type<miscellaneous::types::text> _title;
            core::wrappers::type<math::types::vector<math::types::integer, 2>> _dimensions;
            core::wrappers::type<graphics::types::color<float>> _background_color;

			mutable GLFWwindow* _glfw_window;

		public:
		    window() : _title(), _dimensions(), _background_color() { }
			window(miscellaneous::types::text const& title, math::types::vector<math::types::integer, 2> const& dimensions, graphics::types::color<float> const& background_color) : _title(title), _dimensions(dimensions), _background_color(background_color) { }
        
			miscellaneous::types::text const& title() const {
				return _title.value();
			}

			miscellaneous::types::text& title() {
				return _title.value();
			}

			math::types::vector<math::types::integer, 2> const& dimensions() const {
				return _dimensions.value();
			}

			math::types::vector<math::types::integer, 2>& dimensions() {
				return _dimensions.value();
			}

			graphics::types::color<float> const& background_color() const {
				return _background_color.value();
			}

			graphics::types::color<float>& background_color() {
				return _background_color.value();
			}

			GLFWwindow* glfw_window() const {
				return _glfw_window;
			}

			void create() const;
			void destroy() const;

		    static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
        		glViewport(0, 0, width, height);
    		}

			void save(os& file) const override {
                file(CEREAL_NVP(_title));
                file(CEREAL_NVP(_dimensions));
                file(CEREAL_NVP(_background_color));
			}

			void load(is& file) override {
                file(_title);
				file(_dimensions);
                file(_background_color);
			}

			static inline std::set<GLFWwindow*> _active_windows;
	};
}
