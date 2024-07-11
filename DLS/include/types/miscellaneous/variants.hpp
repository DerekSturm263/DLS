#pragma once

#include <vector>
#include "interfaces/serializable.hpp"

namespace dls::miscellaneous::types {
	template <typename T>
	class variants : public core::interfaces::serializable<variants<T>> {
		private:
			std::vector<core::wrappers::type<T>> _variants;

		public:
			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_variants));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_variants);
			}

			void draw(std::string const& label) const override {
				for (auto& variant : _variants) {
					variant.draw("Variant");
				}
			}
	};
}
