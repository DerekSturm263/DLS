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
			bool _is_ref;

		public:
			type() : _internal(val<T>{}), _is_ref(false) { }
			type(T&& value) : _internal(val<T>{ std::move(value) }), _is_ref(false) { }
			type(val<T>&& value) : _internal(std::move(value)), _is_ref(false) { }
			type(ref<T>&& reference) : _internal(std::move(reference)), _is_ref(true) { }

			T const& value() const {
				if (_is_ref)
					return std::get<ref<T>>(_internal).value();
				else
					return std::get<val<T>>(_internal).value();
			}

			T& value() {
				if (_is_ref)
					return std::get<ref<T>>(_internal).value();
				else
					return std::get<val<T>>(_internal).value();
			}

			void save(interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_internal));
				file(CEREAL_NVP(_is_ref));
			}

			void load(interfaces::serializable_base::is& file) override {
				file(_internal);
				file(_is_ref);
			}

			void draw(std::string const& label) const override {

			}
	};
}
