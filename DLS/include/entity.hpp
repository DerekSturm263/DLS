#pragma once

#include "serializable.hpp"
#include "module.hpp"

namespace dls {
	class entity : public serializable {
		private:
			// TODO: Store the vals somewhere!
			std::vector<ref<module_base>> _modules;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_modules));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_modules));
			}
	};
}
