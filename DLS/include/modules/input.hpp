#pragma once

#include <map>
#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/input_button.hpp"
#include "types/input_event_group.hpp"

namespace dls {
	class input : public module<> {
		private:
			std::map<input_button, type<input_event_group>> _actions;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_actions));
			}

			void load(is& file) override {
				file(_actions);
			}
	};
}

REGISTER_MODULE(dls::input);
