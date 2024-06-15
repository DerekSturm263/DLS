#pragma once

#include <unordered_map>
#include "module.hpp"
#include "type_templates.hpp"
#include "input_button.hpp"
#include "input_event_group.hpp"
#include "event.hpp"

namespace dls {
	class input : public module<> {
		std::unordered_map<type<input_button>, type<input_event_group>> _actions;
	};
}

REGISTER_MODULE(dls::input);
