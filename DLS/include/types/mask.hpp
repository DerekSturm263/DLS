#pragma once

#include "interfaces/serializable.hpp"

namespace dls {
	template <typename T>
	class mask : public serializable {
		private:
			std::size_t _internal;
			
		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_internal));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_internal));
			}
	};
}
