#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::nodes::types {
	template <typename T>
	class node;

	template <typename T>
	class node_group : public core::interfaces::serializable<node_group<T>> {
		private:
			std::vector<node<T>> _nodes;

		public:
			void save(core::interfaces::serializable_base::os& file) const override {

			}

			void load(core::interfaces::serializable_base::is& file) override {

			}

			void draw(std::string const& label) const override {

			}
	};
}
