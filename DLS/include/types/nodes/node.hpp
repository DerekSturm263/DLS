#pragma once

#include "interfaces/serializable.hpp"

namespace dls::nodes::types {
	template <typename T>
	class node : public serializable<node<T>> {
		private:

		public:
			void save(serializable_base::os& file) const override {

			}

			void load(serializable_base::is& file) override {

			}
	};
}
