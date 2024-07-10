#pragma once

#include "types/core/module.hpp"
#include "wrappers/wrappers.hpp"
#include "types/nodes/node_group.hpp"
#include "types/events/event.hpp"

namespace dls::nodes::modules {
	template <typename T>
	class node_group_resolver : public core::types::module<> {
		private:
			core::wrappers::type<types::node_group<T>> _node_group;
			core::wrappers::type<events::types::event<void(T)>> _on_resolve;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_node_group));
				file(CEREAL_NVP(_on_resolve));
			}

			void load(is& file) override {
				file(_node_group);
				file(_on_resolve);
			}

			void draw(std::string const& label) const override {
				_node_group.draw("Node Group");
				_on_resolve.draw("On Resolve");
			}
	};
}
