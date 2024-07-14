#pragma once

#include <string>
#include <fstream>
#include "val.hpp"
#include "instance.hpp"

namespace dls::core::wrappers {
	/// <summary>
	/// Stores any given serializable value as a readonly asset in the file explorer
	/// </summary>
	/// <typeparam name="T">Type to store (must be serializable)</typeparam>
	template <typename T>
	class asset {
		private:
			std::string _file_path;
			val<T> _value;

			template <typename T>
			friend class instance;
			
			friend class save_data;

		public:
			asset() : _file_path(), _value() { }

			asset(std::string const& file_path, T const& def) : _file_path(file_path), _value() {
				try {
					std::ifstream ifstream{ file_path };

					if (ifstream.is_open()) {
						interfaces::serializable_base::is archive{ ifstream };
						archive(_value);
					} else {
						// TODO: Add debug message.
						_value = def;
					}
				} catch (std::exception const& e) {
					// TODO: Add debug message.
					_value = def;
				}
			}
			asset(std::string const& file_path, T&& def) : _file_path(file_path), _value() {
				try {
					std::ifstream ifstream{ file_path };

					if (ifstream.is_open()) {
						interfaces::serializable_base::is archive{ ifstream };
						archive(_value);
					}
					else {
						// TODO: Add debug message.
						_value = std::move(def);
					}
				}
				catch (std::exception const& e) {
					// TODO: Add debug message.
					_value = std::move(def);
				}
			}

			asset(asset<T> const& rhs) : _file_path(rhs._file_path), _value(rhs._value) { }
			asset(asset<T>&& rhs) : _file_path(std::move(rhs._file_path)), _value(std::move(rhs._value)) { }

			~asset() {
				std::ofstream ofstream{ _file_path };

				if (ofstream.is_open()) {
					interfaces::serializable_base::os archive{ ofstream };
					archive(_value);
				} else {
					// TODO: Add debug message.
				}
			}

			std::string const& file_path() const {
				return _file_path;
			}

			T const& value() const {
				return _value.value();
			}

			T& value() {
				return _value.value();
			}

			void set_from_instance(instance<T> const& rhs) {
				_value = rhs._value;
			}

			void set_from_instance(instance<T>&& rhs) {
				_value = std::move(rhs._value);
			}

			asset<T>& operator= (asset<T> const& rhs) {
				_file_path = rhs._file_path;
				_value = rhs._value;

				return *this;
			}

			asset<T>& operator= (asset<T>&& rhs) {
				_file_path = std::move(rhs._file_path);
				_value = std::move(rhs._value);

				return *this;
			}
	};
}
