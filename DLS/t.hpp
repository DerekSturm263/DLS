#pragma once

#include <variant>
#include "serializable.hpp"
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
			std::variant<value<T>, reference<T>> _internal;

		public:
			t(val<T> const&& value) : _internal(value) { }
			t(ref<T> const&& reference) : _internal(reference) { }

			auto const& value() {
				return std::get(_internal);
			}
	};
}
