#pragma once

#include "interfaces/serializable.hpp"

namespace dls::miscellaneous::types {
	template <typename T>
	class mask : public core::interfaces::serializable<mask<T>> {
		public:
			enum class comparison_type {
				any,
				all
			};

		private:
			std::size_t _mask;
			std::vector<T> _values;
			comparison_type _comparison_type;
			
		public:
			std::vector<T> values() const {
				std::vector output{};

				for (int i = 0; i < _values.size(); ++i) {
					if ((_mask & i) != 0) {
						output.push_back(_values[i]);
					}
				}

				return output;
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_mask));
				file(CEREAL_NVP(_values));
				file(CEREAL_NVP(_comparison_type));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_mask);
				file(_values);
				file(_comparison_type);
			}

			void draw(std::string const& label) const override {

			}
	};
}
