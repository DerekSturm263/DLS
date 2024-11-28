#pragma once

#include <variant>
#include "interfaces/serializable.hpp"
#include "types/miscellaneous/variant.hpp"
#include "val.hpp"
#include "ref.hpp"

namespace dls::core::wrappers {
	// Stores a reference to or value of for any given serializable value. This can be changed at edit-time but not run-time
	template <typename T>
	class type : public interfaces::serializable<type<T>> {
		private:
			miscellaneous::types::variant<val<T>, ref<T>> _internal;

		public:
			type() : _internal(val<T>{}) { }

			type(T const& value) : _internal(val<T>{ value }) { }
			type(T&& value) : _internal(val<T>{ std::move(value) }) { }

			type(val<T> const& value) : _internal(value) { }
			type(val<T>&& value) : _internal(std::move(value)) { }

			type(ref<T> const& reference) : _internal(reference) { }
			type(ref<T>&& reference) : _internal(std::move(reference)) { }

			type(type<T> const& rhs) : _internal(rhs._internal) { }
			type(type<T>&& rhs) : _internal(std::move(rhs._internal)) { }

			T const& value() const {
				switch (_internal.value().index()) {
					case 1:
						return std::get<ref<T>>(_internal.value()).value();
						break;

					default:
						return std::get<val<T>>(_internal.value()).value();
						break;
				}
			}

			T& value() {
				switch (_internal.value().index()) {
					case 1:
						return std::get<ref<T>>(_internal.value()).value();
						break;

					default:
						return std::get<val<T>>(_internal.value()).value();
						break;
				}
			}

			void save(interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_internal));
			}

			void load(interfaces::serializable_base::is& file) override {
				file(_internal);
			}

			type<T>& operator=(type<T> const& rhs) {
				_internal = rhs._internal;

				return *this;
			}

			type<T>& operator=(type<T>&& rhs) {
				_internal = std::move(rhs._internal);

				return *this;
			}
	};
}
