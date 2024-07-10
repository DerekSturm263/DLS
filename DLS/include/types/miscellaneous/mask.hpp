#pragma once

#include "interfaces/serializable.hpp"

namespace dls::miscellaneous::types {
	template <typename T>
	class mask : public core::interfaces::serializable<mask<T>> {
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

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_mask));
				file(CEREAL_NVP(_values));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_mask);
				file(_values);
			}

			void draw(std::string const& label) const override {

			}
	};
}
