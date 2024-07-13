#pragma once

#include <variant>
#include "interfaces/serializable.hpp"
#include "val.hpp"
#include "ref.hpp"

namespace dls::core::wrappers {
	/// <summary>
	/// Stores a reference to or value of for any given serializable value. This can be changed at edit-time but not run-time
	/// </summary>
	/// <typeparam name="T">Type to reference or store (must be serializable)</typeparam>
	template <typename T>
	class type : public interfaces::serializable<type<T>> {
		private:
			std::variant<val<T>, ref<T>> _internal;

		public:
			type() : _internal(val<T>{}) { }
			type(T&& value) : _internal(val<T>{ std::move(value) }) { }
			type(val<T>&& value) : _internal(std::move(value)) { }
			type(ref<T>&& reference) : _internal(std::move(reference)) { }

			type(type<T> const& rhs) : _internal(rhs._internal) { }

			T const& value() const {
				if (_internal.index() == 0)
					return std::get<val<T>>(_internal).value();
				else
					return std::get<ref<T>>(_internal).value();
			}

			T& value() {
				if (_internal.index() == 0)
					return std::get<val<T>>(_internal).value();
				else
					return std::get<ref<T>>(_internal).value();
			}

			void save(interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_internal));
			}

			void load(interfaces::serializable_base::is& file) override {
				file(_internal);
			}

			void draw(std::string const& label) const override {

			}

			type<T>& operator= (type<T> const& rhs) {
				_internal = rhs._internal;

				return *this;
			}

			type<T>& operator= (type<T>&& rhs) {
				_internal = std::move(rhs._internal);

				return *this;
			}
	};
}
