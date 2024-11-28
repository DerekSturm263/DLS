#pragma once

#include <GLFW/glfw3.h>
#include "interfaces/serializable.hpp"
#include "types/miscellaneous/variant.hpp"

namespace dls::input::types {
	class input_trigger : public core::interfaces::serializable<input_trigger> {
		public:
			enum class resolution_type {
				on_press,
				on_tick,
                on_release
			};

            enum class modifier_type {
                tap,
                hold,
                multi_tap
            };

			enum class keyboard_key {
				none = -1,
				space = GLFW_KEY_SPACE,
				apostrophe = GLFW_KEY_APOSTROPHE,
				comma = GLFW_KEY_COMMA,
				minus = GLFW_KEY_MINUS,
				period = GLFW_KEY_PERIOD,
				slash = GLFW_KEY_SLASH,
				key_0 = GLFW_KEY_0,
				key_1 = GLFW_KEY_1,
				key_2 = GLFW_KEY_2,
				key_3 = GLFW_KEY_3,
				key_4 = GLFW_KEY_4,
				key_5 = GLFW_KEY_5,
				key_6 = GLFW_KEY_6,
				key_7 = GLFW_KEY_7,
				key_8 = GLFW_KEY_8,
				key_9 = GLFW_KEY_9,
				semicolon = GLFW_KEY_SEMICOLON,
				equals = GLFW_KEY_EQUAL,
				a = GLFW_KEY_A,
				b = GLFW_KEY_B,
				c = GLFW_KEY_C,
				d = GLFW_KEY_D,
				e = GLFW_KEY_E,
				f = GLFW_KEY_F,
				g = GLFW_KEY_G,
				h = GLFW_KEY_H,
				i = GLFW_KEY_I,
				j = GLFW_KEY_J,
				k = GLFW_KEY_K,
				l = GLFW_KEY_L,
				m = GLFW_KEY_M,
				n = GLFW_KEY_N,
				o = GLFW_KEY_O,
				p = GLFW_KEY_P,
				q = GLFW_KEY_Q,
				r = GLFW_KEY_R,
				s = GLFW_KEY_S,
				t = GLFW_KEY_T,
				u = GLFW_KEY_U,
				v = GLFW_KEY_V,
				w = GLFW_KEY_W,
				x = GLFW_KEY_X,
				y = GLFW_KEY_Y,
				z = GLFW_KEY_Z,
				left_bracket = GLFW_KEY_LEFT_BRACKET,
				backslash = GLFW_KEY_BACKSLASH,
				right_bracket = GLFW_KEY_RIGHT_BRACKET,
				grave_accent = GLFW_KEY_GRAVE_ACCENT,
				escape = GLFW_KEY_ESCAPE,
				enter = GLFW_KEY_ENTER,
				tab = GLFW_KEY_TAB,
				backspace = GLFW_KEY_BACKSPACE,
				insert = GLFW_KEY_INSERT,
				del = GLFW_KEY_DELETE,
				right = GLFW_KEY_RIGHT,
				left = GLFW_KEY_LEFT,
				down = GLFW_KEY_DOWN,
				up = GLFW_KEY_UP,
				page_up = GLFW_KEY_PAGE_UP,
				page_down = GLFW_KEY_PAGE_DOWN,
				home = GLFW_KEY_HOME,
				end = GLFW_KEY_END,
				caps_lock = GLFW_KEY_CAPS_LOCK,
				scroll_lock = GLFW_KEY_SCROLL_LOCK,
				num_lock = GLFW_KEY_NUM_LOCK,
				print_screen = GLFW_KEY_PRINT_SCREEN,
				pause = GLFW_KEY_PAUSE,
				f1 = GLFW_KEY_F1,
				f2 = GLFW_KEY_F2,
				f3 = GLFW_KEY_F3,
				f4 = GLFW_KEY_F4,
				f5 = GLFW_KEY_F5,
				f6 = GLFW_KEY_F6,
				f7 = GLFW_KEY_F7,
				f8 = GLFW_KEY_F8,
				f9 = GLFW_KEY_F9,
				f10 = GLFW_KEY_F10,
				f11 = GLFW_KEY_F11,
				f12 = GLFW_KEY_F12,
				f13 = GLFW_KEY_F13,
				f14 = GLFW_KEY_F14,
				f15 = GLFW_KEY_F15,
				f16 = GLFW_KEY_F16,
				f17 = GLFW_KEY_F17,
				f18 = GLFW_KEY_F18,
				f19 = GLFW_KEY_F19,
				f20 = GLFW_KEY_F20,
				numpad_0,
				numpad_1,
				numpad_2,
				numpad_3,
				numpad_4,
				numpad_5,
				numpad_6,
				numpad_7,
				numpad_8,
				numpad_9,
				numpad_decimal,
				numpad_divide,
				numpad_multiple,
				numpad_subtract,
				numpad_add,
				numpad_enter,
				numpad_equals,
				left_shift = GLFW_KEY_LEFT_SHIFT,
				left_control = GLFW_KEY_LEFT_CONTROL,
				left_alt = GLFW_KEY_LEFT_ALT,
				left_super = GLFW_KEY_LEFT_SUPER,
				right_shift = GLFW_KEY_RIGHT_SHIFT,
				right_control = GLFW_KEY_RIGHT_CONTROL,
				right_alt = GLFW_KEY_RIGHT_ALT,
				right_super = GLFW_KEY_RIGHT_SUPER,
				menu = GLFW_KEY_MENU,
				any
			};

			enum class mouse_button {
				none = -1,
				left = GLFW_MOUSE_BUTTON_LEFT,
				middle = GLFW_MOUSE_BUTTON_MIDDLE,
				right = GLFW_MOUSE_BUTTON_RIGHT,
				scroll,
				cursor_pos,
				cursor_delta,
				any
			};

			enum class xbox_button {
				none = -1,
				b,
				a,
				y,
				x,
				d_pad,
				left_stick_pos,
				left_stick_delta,
				left_stick_press,
				right_stick_pos,
				right_stick_delta,
				right_stick_press,
				l_bumper,
				r_bumper,
				l_trigger,
				r_trigger,
				view,
				menu,
				any
			};

			enum class playstation_button {
				none = -1,
				circle,
				cross,
				triangle,
				square,
				d_pad,
				left_stick_pos,
				left_stick_delta,
				left_stick_press,
				right_stick_pos,
				right_stick_delta,
				right_stick_press,
				l1,
				r1,
				l2,
				r2,
				share,
				options,
				any
			};

			enum class switch_button {
				none = -1,
				a,
				b,
				x,
				y,
				d_pad,
				left_stick_pos,
				left_stick_delta,
				left_stick_press,
				right_stick_pos,
				right_stick_delta,
				right_stick_press,
				l,
				r,
				zl,
				zr,
				minus,
				plus,
				any
			};

			enum class generic_button {
				none = -1,
				east,
				south,
				north,
				west,
				d_pad,
				left_stick_pos,
				left_stick_delta,
				left_stick_press,
				right_stick_pos,
				right_stick_delta,
				right_stick_press,
				l_bumper,
				r_bumper,
				l_trigger,
				r_trigger,
				options,
				menu,
				any
			};

            using trigger = miscellaneous::types::variant<keyboard_key, mouse_button, generic_button, xbox_button, playstation_button, switch_button>;

		private:
			resolution_type _resolution;
            modifier_type _modifier;
			trigger _trigger;

		public:
			input_trigger() : _resolution(resolution_type::on_press), _modifier(modifier_type::tap), _trigger(keyboard_key::none) { }
			input_trigger(resolution_type resolution, modifier_type modifier, trigger trigger) : _resolution(resolution), _modifier(modifier), _trigger(trigger) { }

			bool operator<(input_trigger const& rhs) const {
				return _trigger.value() < rhs._trigger.value();
			}

			bool operator>(input_trigger const& rhs) const {
				return _trigger.value() > rhs._trigger.value();
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_resolution));
				file(CEREAL_NVP(_modifier));
                file(CEREAL_NVP(_trigger));
			}

			void load(is& file) override {
				file(_resolution);
                file(_modifier);
				file(_trigger);
			}
	};
}
