#pragma once

#include <string>
#include "serializable.hpp"
#include "val.hpp"

namespace dls {
	/// <summary>
	/// Stores any given serializable value as an asset in the file explorer
	/// </summary>
	/// <typeparam name="T">Type to store (must be serializable)</typeparam>
	template <typename T>
	class asset : public serializable {
		private:
			const std::string _name;
			const val<T> _value;

			template <typename T>
			friend class instance;

		public:
			asset(std::string const& name, T const& value) : _name(name), _value(value) { }

			std::string const& name() {
				return _name;
			}

			static asset<T> from_file(std::string const& full_path) {

			}
	};
}
