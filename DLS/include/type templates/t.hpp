#pragma once

#include <variant>
#include "interfaces/serializable.hpp"
#include "val.hpp"
#include "ref.hpp"

namespace dls {
	/// <summary>
	/// Stores a reference to or value of for any given serializable value. This can be changed at edit-time but not run-time
	/// </summary>
	/// <typeparam name="T">Type to reference or store (must be serializable)</typeparam>
	template <typename T>
	class t : public serializable {
		private:
			std::variant<val<T>, ref<T>> _internal;
			bool _is_ref;

		public:
			t() : _internal(val<T>{}), _is_ref(false) { }
			t(val<T> const&& value) : _internal(value), _is_ref(false) { }
			t(ref<T> const&& reference) : _internal(reference), _is_ref(true) { }

			T const& value() const {
				if (_is_ref)
					return std::get<ref<T>>(_internal).value();
				else
					return std::get<val<T>>(_internal).value();
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_internal));
				file(CEREAL_NVP(_is_ref));
			}

			void load(is& file) override {
				file(_internal);
				file(_is_ref);
			}
	};
}
