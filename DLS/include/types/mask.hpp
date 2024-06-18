#pragma once

#include "interfaces/serializable.hpp"

namespace dls {
	template <typename T>
	class mask : public serializable<mask<T>> {
		private:
			std::size_t _mask;
			std::vector<T> _values;
			
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

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_mask));
				file(CEREAL_NVP(_values));
			}

			void load(serializable_base::is& file) override {
				file(CEREAL_NVP(_mask));
				file(CEREAL_NVP(_values));
			}
	};
}
