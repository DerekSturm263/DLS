#pragma once

#include "interfaces/serializable.hpp"

namespace dls::nodes::types {
	template <typename T>
	class node : public core::interfaces::serializable<node<T>> {
		private:

		public:
			void save(core::interfaces::serializable_base::os& file) const override {

			}

			void load(core::interfaces::serializable_base::is& file) override {

			}

			void draw(std::string const& label) const override {

			}
	};
}
