#pragma once

#include <variant>
#include <vector>
#include "interfaces/serializable.hpp"
#include "wrappers/val.hpp"
#include "wrappers/ref.hpp"

namespace dls::events::types {
	/// <summary>
	/// Represents a type that can be used as a parameter in a statement. These types can be valTs, refTs, or references to parameters in the event's callback context
	/// </summary>
	/// <typeparam name="T">Type to reference or store (must be serializable)</typeparam>
	template <typename T>
	class param_ref : public core::interfaces::serializable<param_ref<T>> {
		private:
			std::variant<core::wrappers::val<T>, core::wrappers::ref<T>, size_t> _internal;

		public:
			param_ref() : _internal(core::wrappers::val<T>{}) { }
			param_ref(T&& value) : _internal(core::wrappers::val<T>{ std::move(value) }) { }
			param_ref(core::wrappers::val<T>&& value) : _internal(std::move(value)) { }
			param_ref(core::wrappers::ref<T>&& reference) : _internal(std::move(reference)) { }

			param_ref(param_ref<T> const& rhs) : _internal(rhs._internal) { }
			param_ref(param_ref<T>&& rhs) : _internal(std::move(rhs._internal)) { }

			T value(std::vector<void*> const& event_args) const {
				switch (_internal.index()) {
					case 0:
						return std::get<core::wrappers::val<T>>(_internal).value();
						break;

					case 1:
						return std::get<core::wrappers::ref<T>>(_internal).value();
						break;

					case 2:
						return *static_cast<T*>(event_args.at(std::get<size_t>(_internal)));
						break;
				}
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_internal));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_internal);
			}

			void draw(std::string const& label) const override {

			}

			param_ref<T>& operator= (param_ref<T> const& rhs) {
				_internal = rhs._internal;

				return *this;
			}

			param_ref<T>& operator= (param_ref<T>&& rhs) {
				_internal = std::move(rhs._internal);

				return *this;
			}
	};
}
