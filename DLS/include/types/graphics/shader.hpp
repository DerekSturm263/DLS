#pragma once

#include <string>
#include "interfaces/serializable.hpp"

namespace dls::graphics::types {
	class shader : public core::interfaces::serializable<shader> {
		public:
			using any = std::variant<int>;

		private:
			int _id;

		public:
			void set(std::string const& name, any const& value) {

			}

			void use() {

			}

			void save(core::interfaces::serializable_base::os& file) const override {
				
			}

			void load(core::interfaces::serializable_base::is& file) override {
				
			}

			void draw(std::string const& label) const override {

			}
	};
}
