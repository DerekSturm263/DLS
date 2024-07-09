#pragma once

#include <vector>
#include "interfaces/serializable.hpp"
#include "node.hpp"
#include "type templates/type_templates.hpp"

namespace dls::nodes::types {
	template <typename T>
	class node_group : public serializable<node_group<T>> {
		private:
			std::vector<node<T>> _nodes;

		public:
			void save(serializable_base::os& file) const override {

			}

			void load(serializable_base::is& file) override {

			}
	};
}
