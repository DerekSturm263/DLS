#pragma once

#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/nodes/node_group.hpp"
#include "types/events/event.hpp"

namespace dls::nodes::modules {
	template <typename T>
	class node_group_resolver : public core::module<> {
		private:
			type<node_group<T>> _node_group;
			type<events::event<void(T)>> _on_resolve;

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
