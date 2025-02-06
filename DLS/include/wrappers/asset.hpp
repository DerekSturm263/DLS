#pragma once

#include <string>
#include <fstream>
#include "val.hpp"

namespace dls::core::wrappers {
	// Stores any given serializable value as a readonly asset in the file explorer
	template <typename T>
	class asset {
		private:
			std::string _file_path;
			val<T> _value;

			template <typename U>
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
					} else {
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

			val<T> const& value() const {
				return _value;
			}

			val<T>& value() {
				return _value;
			}

			asset<T>& operator=(asset<T> const& rhs) {
				_file_path = rhs._file_path;
				_value = rhs._value;

				return *this;
			}

			asset<T>& operator=(asset<T>&& rhs) {
				_file_path = std::move(rhs._file_path);
				_value = std::move(rhs._value);

				return *this;
			}
	};

	class asset_helper {
		public:
			template <typename T>
			static asset<T> make(std::string const& file_path, T const& def) {
				return asset<T>{ file_path, def };
			}

			template <typename T>
			static asset<T> make(std::string const& file_path, T&& def) {
				return asset<T>{ file_path, std::move(def) };
			}
	};
}
