#pragma once

#include "interfaces/serializable.hpp"
#include "wrappers/val.hpp"

namespace dls::miscellaneous::types {
    template <typename... Ts>
	class variant : public core::interfaces::serializable<variant<Ts...>> {
		private:
			std::variant<Ts...> _value;
			
		public:
			variant() : _value() { }

			variant(std::variant<Ts...> const& value) : _value(value) { }
			variant(std::variant<Ts...>&& value) : _value(std::move(value)) { }

			std::variant<Ts...> const& value() const {
				return _value;
			}

			std::variant<Ts...>& value() {
				return _value;
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_value));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_value);
			}
	};
}
