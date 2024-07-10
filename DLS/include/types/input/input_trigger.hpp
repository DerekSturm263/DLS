#pragma once

#include "interfaces/serializable.hpp"

namespace dls::input::types {
	/// <summary>
	/// Represents a trigger for an input, including which buttons trigger it and when it's resolved.
	/// </summary>
	class input_trigger : public core::interfaces::serializable<input_trigger> {
		public:
			/// <summary>
			/// Determines when an input trigger is resolved.
			/// </summary>
			enum class resolution_type {
				/// <summary>
				/// The input is only resolved when changed on the next tick. The event won't be resolved twice if the value is the same on both ticks.
				/// </summary>
				on_change,

				/// <summary>
				/// The input is resolved every tick, regardless of whether or not the value changed between ticks.
				/// </summary>
				on_tick
			};

			/// <summary>
			/// Represents a key on the keyboard.
			/// </summary>
			enum class keyboard_key {
				none = -1,
				space,
				apostrophe,
				comma,
				minus,
				period,
				slash,
				key_0,
				key_1,
				key_2,
				key_3,
				key_4,
				key_5,
				key_6,
				key_7,
				key_8,
				key_9,
				semicolon,
				equals,
				a,
				b,
				c,
				d,
				e,
				f,
				g,
				h,
				i,
				j,
				k,
				l,
				m,
				n,
				o,
				p,
				q,
				r,
				s,
				t,
				u,
				v,
				w,
				x,
				y,
				z,
				left_bracket,
				backslash,
				right_bracket,
				grave_accent,
				escape,
				enter,
				tab,
				backspace,
				insert,
				del,
				right,
				left,
				down,
				up,
				page_up,
				page_down,
				home,
				end,
				caps_lock,
				scroll_lock,
				num_lock,
				print_screen,
				pause,
				f1,
				f2,
				f3,
				f4,
				f5,
				f6,
				f7,
				f8,
				f9,
				f10,
				f11,
				f12,
				f13,
				f14,
				f15,
				f16,
				f17,
				f18,
				f19,
				f20,
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
				left_shift,
				left_control,
				left_alt,
				left_super,
				right_shift,
				right_control,
				right_alt,
				right_super,
				menu
			};

			/// <summary>
			/// Represents a button on a mouse.
			/// </summary>
			enum class mouse_button {
				none = -1,
				left,
				middle,
				right
			};

			/// <summary>
			/// Represents a button on an Xbox controller.
			/// </summary>
			enum class xbox_button {
				none = -1,
				b,
				a,
				y,
				x,
				d_pad,
				left_stick,
				left_stick_press,
				right_stick,
				right_stick_press,
				l_bumper,
				r_bumper,
				l_trigger,
				r_trigger,
				view,
				menu
			};

			/// <summary>
			/// Represents a button on a Playstation controller.
			/// </summary>
			enum class playstation_button {
				none = -1,
				circle,
				cross,
				triangle,
				square,
				d_pad,
				left_stick,
				left_stick_press,
				right_stick,
				right_stick_press,
				l1,
				r1,
				l2,
				r2,
				share,
				options
			};

			/// <summary>
			/// Represents a button on a Nintendo Switch controller.
			/// </summary>
			enum class switch_button {
				none = -1,
				a,
				b,
				x,
				y,
				d_pad,
				left_stick,
				left_stick_press,
				right_stick,
				right_stick_press,
				l,
				r,
				zl,
				zr,
				minus,
				plus
			};

			/// <summary>
			/// Represents a generic button on any gamepad.
			/// </summary>
			enum class generic_button {
				none = -1,
				east,
				south,
				north,
				west,
				d_pad,
				left_stick,
				left_stick_press,
				right_stick,
				right_stick_press,
				l_bumper,
				r_bumper,
				l_trigger,
				r_trigger,
				options,
				menu
			};

		private:
			resolution_type _resolution_type;
			
			keyboard_key _keyboard;
			mouse_button _mouse;

			union {
				generic_button _generic;
				xbox_button _xbox;
				playstation_button _playstation;
				switch_button _switch;
			};

		public:
			input_trigger() : _resolution_type(resolution_type::on_change), _keyboard(keyboard_key::none), _mouse(mouse_button::none), _generic(generic_button::none) { }
			input_trigger(resolution_type resolution_type, keyboard_key keyboard, mouse_button mouse, generic_button gamepad) : _resolution_type(resolution_type), _keyboard(keyboard), _mouse(mouse), _generic(gamepad) { }

			bool operator <(input_trigger const& rhs) const {
				return _keyboard < rhs._keyboard;
			}

			bool operator >(input_trigger const& rhs) const {
				return _keyboard > rhs._keyboard;
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_resolution_type));
				file(CEREAL_NVP(_keyboard));
				file(CEREAL_NVP(_generic));
			}

			void load(is& file) override {
				file(_resolution_type);
				file(_keyboard);
				file(_generic);
			}

			void draw(std::string const& label) const override {

			}
	};
}
