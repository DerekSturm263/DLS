#pragma once

#include <map>
#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/input/input_trigger.hpp"
#include "types/input/input_event_group.hpp"

namespace dls::input::modules {
	template <typename Decimal>
	class input : public core::types::module<> {
		private:
			std::map<types::input_trigger, type<types::input_event_group<Decimal>>> _actions;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_actions));
			}

			void load(is& file) override {
				file(_actions);
			}
	};
}
