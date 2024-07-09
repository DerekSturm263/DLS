#pragma once

#include <unordered_map>
#include "interfaces/serializable.hpp"

namespace dls::graphics::types {
	class material_settings : public serializable<material_settings> {
		private:
			std::unordered_map<std::string, shader::any> _values;

		public:
			std::unordered_map<std::string, shader::any> const& values() const {
				return _values;
			}
			
			std::unordered_map<std::string, shader::any>& values() {
				return _values;
			}

			void save(os& file) const override {

			}

			void load(is& file) override {

			}
	};
}
