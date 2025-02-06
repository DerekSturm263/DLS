#pragma once

#include <type_traits>
#include "interfaces/serializable.hpp"

namespace dls::miscellaneous::types {
	template <typename DropdownType, enum DropdownType... Ts>
	class dropdown : public core::interfaces::serializable<dropdown<DropdownType, Ts...>> {
		public:
			enum class selection_type : unsigned char {
				single,
				multiple
			};

			using underlying_type = std::underlying_type<DropdownType>::type;

		private:
			selection_type _selection_type;
			underlying_type _value;

		public:
			dropdown() : _selection_type(selection_type::single), _value(static_cast<underlying_type>(0)) {}
			dropdown(DropdownType value) : _selection_type(selection_type::single), _value(static_cast<underlying_type>(value)) {}

			void save(dls::core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(static_cast<unsigned char>(_selection_type)));
				file(CEREAL_NVP(_value));
			}

			void load(dls::core::interfaces::serializable_base::is& file) override {
				unsigned char selection_type_char = 0;
				file(selection_type_char);
				_selection_type = static_cast<selection_type>(selection_type_char);

				file(_value);
			}

			bool operator<(dropdown<DropdownType, Ts...> const& rhs) const {
				return _value > rhs._value;
			}

			bool operator>(dropdown<DropdownType, Ts...> const& rhs) const {
				return _value < rhs._value;
			}
	};
}
