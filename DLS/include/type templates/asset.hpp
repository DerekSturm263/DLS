#pragma once

#include <string>
#include <fstream>
#include "interfaces/serializable.hpp"
#include "val.hpp"
#include "instance.hpp"

namespace dls {
	/// <summary>
	/// Stores any given serializable value as a readonly asset in the file explorer
	/// </summary>
	/// <typeparam name="T">Type to store (must be serializable)</typeparam>
	template <typename T>
	class asset {
		private:
			std::string _file_path;
			val<T> _value;

			void set_from_instance(instance<T> const& rhs) {
				_value = rhs._value;
			}

			template <typename T>
			friend class instance;
			
			friend class save_data;

		public:
			asset(std::string const& file_path, T const& def) : _file_path(file_path), _value() {
				try {
					std::ifstream ifstream{ file_path };

					if (ifstream.is_open()) {
						serializable_base::is archive{ ifstream };
						archive(_value);
					}
				} catch (std::exception const& e) {
					// TODO: Add debug message.
					_value = val<T>{ def };
				}
			}

			~asset() {
				std::ofstream ofstream{ _file_path };

				if (ofstream.is_open()) {
					serializable_base::os archive{ ofstream };
					archive(_value);
				}
			}

			std::string const& file_path() const {
				return _file_path;
			}

			T const& value() const {
				return _value.value();
			}
	};
}
