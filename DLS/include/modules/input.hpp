#pragma once

#include <map>
#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/input/input_trigger.hpp"
#include "types/input/input_event_group.hpp"

namespace dls::input::modules {
	class input : public core::module<> {
		private:
			std::map<input_trigger, type<input_event_group>> _actions;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_actions));
			}

			void load(is& file) override {
				file(_actions);
			}
	};
}
