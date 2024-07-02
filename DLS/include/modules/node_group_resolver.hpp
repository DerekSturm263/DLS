#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/node_group.hpp"
#include "types/event.hpp"

namespace dls {
	class node_group_resolver : public module<> {
		private:
			type<node_group<void*>> _node_group;
			type<event<void(void*)>> _on_resolve;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_node_group));
				file(CEREAL_NVP(_on_resolve));
			}

			void load(is& file) override {
				file(_node_group);
				file(_on_resolve);
			}
	};
}

REGISTER_MODULE(dls::node_group_resolver);
