#pragma once

#include <GLFW/glfw3.h>
#include "interfaces/serializable.hpp"
#include "types/miscellaneous/variant.hpp"
#include "types/miscellaneous/dropdown.hpp"
#include "types/collections/tuple.hpp"

namespace dls::input::types {
	class input_trigger : public core::interfaces::serializable<input_trigger> {
		public:
			enum class resolution_type : unsigned char {
				on_press, on_tick, on_release
			};
			using resolution_dropdown = miscellaneous::types::dropdown<resolution_type,
				resolution_type::on_press,
				resolution_type::on_tick,
				resolution_type::on_release
			>;

            enum class interaction_type : unsigned char {
                tap, hold, multi_tap
            };
			using interaction_dropdown = miscellaneous::types::dropdown<interaction_type,
				interaction_type::tap,
				interaction_type::hold,
				interaction_type::multi_tap
			>;

			enum class modifier_type : unsigned char {
				unchanged, normalized
			};
			using modifier_dropdown = miscellaneous::types::dropdown<modifier_type,
				modifier_type::unchanged,
				modifier_type::normalized
			>;

			enum class flags_type : unsigned char {
				any, all
			};
			using flags_dropdown = miscellaneous::types::dropdown<flags_type,
				flags_type::any,
				flags_type::all
			>;

			enum class keyboard_key : unsigned long long {
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
				numpad_0 = GLFW_KEY_KP_0,
				numpad_1 = GLFW_KEY_KP_1,
				numpad_2 = GLFW_KEY_KP_2,
				numpad_3 = GLFW_KEY_KP_3,
				numpad_4 = GLFW_KEY_KP_4,
				numpad_5 = GLFW_KEY_KP_5,
				numpad_6 = GLFW_KEY_KP_6,
				numpad_7 = GLFW_KEY_KP_7,
				numpad_8 = GLFW_KEY_KP_8,
				numpad_9 = GLFW_KEY_KP_9,
				numpad_decimal = GLFW_KEY_KP_DECIMAL,
				numpad_divide = GLFW_KEY_KP_DIVIDE,
				numpad_multiply = GLFW_KEY_KP_MULTIPLY,
				numpad_subtract = GLFW_KEY_KP_SUBTRACT,
				numpad_add = GLFW_KEY_KP_ADD,
				numpad_enter = GLFW_KEY_KP_ENTER,
				numpad_equals = GLFW_KEY_KP_EQUAL,
				left_shift = GLFW_KEY_LEFT_SHIFT,
				left_control = GLFW_KEY_LEFT_CONTROL,
				left_alt = GLFW_KEY_LEFT_ALT,
				left_super = GLFW_KEY_LEFT_SUPER,
				right_shift = GLFW_KEY_RIGHT_SHIFT,
				right_control = GLFW_KEY_RIGHT_CONTROL,
				right_alt = GLFW_KEY_RIGHT_ALT,
				right_super = GLFW_KEY_RIGHT_SUPER,
				menu = GLFW_KEY_MENU
			};
			using keyboard_key_dropdown = miscellaneous::types::dropdown<keyboard_key,
				keyboard_key::space
			>;

			enum class mouse_button : unsigned char {
				left, middle, right, scroll_delta, cursor_pos, cursor_delta
			};
			using mouse_button_dropdown = miscellaneous::types::dropdown<mouse_button,
				mouse_button::left,
				mouse_button::middle,
				mouse_button::right,
				mouse_button::scroll_delta,
				mouse_button::cursor_pos,
				mouse_button::cursor_delta
			>;

			enum class gamepad_button : unsigned char {
				east, south, north, west,
				d_pad_up, d_pad_down, d_pad_left, d_pad_right,
				l_stick_pos, l_stick_delta, l_stick_press, r_stick_pos, r_stick_delta, r_stick_press,
				l_shoulder, r_shoulder, l_trigger, r_trigger,
				options, menu
			};
			using gamepad_button_dropdown = miscellaneous::types::dropdown<gamepad_button,
				gamepad_button::east,
				gamepad_button::south,
				gamepad_button::north,
				gamepad_button::west,
				gamepad_button::d_pad_up,
				gamepad_button::d_pad_down,
				gamepad_button::d_pad_left,
				gamepad_button::d_pad_right,
				gamepad_button::l_stick_pos,
				gamepad_button::l_stick_delta,
				gamepad_button::l_stick_press,
				gamepad_button::r_stick_pos,
				gamepad_button::r_stick_delta,
				gamepad_button::r_stick_press,
				gamepad_button::l_shoulder,
				gamepad_button::r_shoulder,
				gamepad_button::l_trigger,
				gamepad_button::r_trigger,
				gamepad_button::options,
				gamepad_button::menu
			>;

			enum class xbox_button : unsigned char {
				b, a, y, x,
				d_pad_up, d_pad_down, d_pad_left, d_pad_right,
				l_stick_pos, l_stick_delta, l_stick_press, r_stick_pos, r_stick_delta, r_stick_press,
				l_bumper, r_bumper, l_trigger, r_trigger,
				view, menu
			};
			using xbox_button_dropdown = miscellaneous::types::dropdown<xbox_button,
				xbox_button::b,
				xbox_button::a,
				xbox_button::y,
				xbox_button::x,
				xbox_button::d_pad_up,
				xbox_button::d_pad_down,
				xbox_button::d_pad_left,
				xbox_button::d_pad_right,
				xbox_button::l_stick_pos,
				xbox_button::l_stick_delta,
				xbox_button::l_stick_press,
				xbox_button::r_stick_pos,
				xbox_button::r_stick_delta,
				xbox_button::r_stick_press,
				xbox_button::l_bumper,
				xbox_button::r_bumper,
				xbox_button::l_trigger,
				xbox_button::r_trigger,
				xbox_button::view,
				xbox_button::menu
			>;

			enum class playstation_button : unsigned char {
				circle, cross, triangle, square,
				d_pad_up, d_pad_down, d_pad_left, d_pad_right,
				l_stick_pos, l_stick_delta, l_stick_press, r_stick_pos, r_stick_delta, r_stick_press,
				l1, r1, l2, r2,
				share, options
			};
			using playstation_button_dropdown = miscellaneous::types::dropdown<playstation_button,
				playstation_button::circle,
				playstation_button::cross,
				playstation_button::triangle,
				playstation_button::square,
				playstation_button::d_pad_up,
				playstation_button::d_pad_down,
				playstation_button::d_pad_left,
				playstation_button::d_pad_right,
				playstation_button::l_stick_pos,
				playstation_button::l_stick_delta,
				playstation_button::l_stick_press,
				playstation_button::r_stick_pos,
				playstation_button::r_stick_delta,
				playstation_button::r_stick_press,
				playstation_button::l1,
				playstation_button::r1,
				playstation_button::l2,
				playstation_button::r2,
				playstation_button::share,
				playstation_button::options
			>;

			enum class switch_button : unsigned char {
				a, b, x, y,
				d_pad_up, d_pad_down, d_pad_left, d_pad_right,
				l_stick_pos, l_stick_delta, l_stick_press, r_stick_pos, r_stick_delta, r_stick_press,
				l, r, zl, zr,
				minus, plus
			};
			using switch_button_dropdown = miscellaneous::types::dropdown<switch_button,
				switch_button::a,
				switch_button::b,
				switch_button::x,
				switch_button::y,
				switch_button::d_pad_up,
				switch_button::d_pad_down,
				switch_button::d_pad_left,
				switch_button::d_pad_right,
				switch_button::l_stick_pos,
				switch_button::l_stick_delta,
				switch_button::l_stick_press,
				switch_button::r_stick_pos,
				switch_button::r_stick_delta,
				switch_button::r_stick_press,
				switch_button::l,
				switch_button::r,
				switch_button::zl,
				switch_button::zr,
				switch_button::minus,
				switch_button::plus
			>;

			using gamepad_type = miscellaneous::types::variant<gamepad_button_dropdown, xbox_button_dropdown, playstation_button_dropdown, switch_button_dropdown>;
            using trigger = collections::types::tuple<keyboard_key_dropdown, mouse_button_dropdown, gamepad_type>;

		private:
			trigger _trigger;
			resolution_dropdown _resolution;
			interaction_dropdown _interaction;
            modifier_dropdown _modifier;
			flags_dropdown _flags;

		public:
			input_trigger() : _trigger(), _resolution(resolution_type::on_press), _interaction(interaction_type::tap), _modifier(modifier_type::unchanged), _flags(flags_type::any) { }
			input_trigger(trigger trigger, resolution_type resolution, interaction_type interaction, modifier_type modifier, flags_type flags) : _trigger(trigger), _resolution(resolution), _interaction(interaction), _modifier(modifier), _flags(flags) { }

			bool operator<(input_trigger const& rhs) const {
				return std::get<gamepad_type>(_trigger.value()).value() < std::get<gamepad_type>(rhs._trigger.value()).value();
			}

			bool operator>(input_trigger const& rhs) const {
				return std::get<gamepad_type>(_trigger.value()).value() > std::get<gamepad_type>(rhs._trigger.value()).value();
			}

			void save(os& file) const override {
                file(CEREAL_NVP(_trigger));
				file(CEREAL_NVP(_resolution));
				file(CEREAL_NVP(_interaction));
				file(CEREAL_NVP(_modifier));
				file(CEREAL_NVP(_flags));
			}

			void load(is& file) override {
				file(_trigger);
				file(_resolution);
				file(_interaction);
				file(_modifier);
				file(_flags);
			}
	};
}
