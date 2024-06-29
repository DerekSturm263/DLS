#pragma once

#include <string>
#include "interfaces/serializable.hpp"

namespace dls {
	class shader : public serializable<shader> {
		public:
			using any = std::variant<int>;

			void set(std::string const& name, any const& value) {

			}

			void use() {

			}

			void save(os& file) const override {
				
			}

			void load(is& file) override {
				
			}
	};
}
