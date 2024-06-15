#include "engine.hpp"
#include "engine_system_manager.hpp"
#include "debug.hpp"
#include "scene_manager.hpp"
#include "val.hpp"
#include "ref.hpp"
#include "t.hpp"
#include "asset.hpp"
#include "instance.hpp"
#include "required.hpp"
#include "optional.hpp"
#include "state_machine.hpp"
#include "color.hpp"
#include <vector>
#include <string>
#include <iostream>

namespace dls {
	void engine::execute() {
		val<int> int_val{ 5 };
		//val<std::string> string_val{ "Your Mom" };
		//val<state_machine<color>> color_state_machine_val{ state_machine<color>{} };

		//std::cout << int_val.value() << std::endl;
		//std::cout << string_val.value() << std::endl;
		//std::cout << color_state_machine_val.value() << std::endl;
		/*
		ref<int> int_ref{ int_val };
		ref<std::string> string_ref{ string_val };
		//ref<state_machine<color>> color_state_machine_ref{ color_state_machine_val };

		std::cout << int_ref.value() << std::endl;
		std::cout << string_ref.value() << std::endl;
		//std::cout << color_state_machine_ref.value() << std::endl;

		t<int> int_val_or_ref{ val<int>{ 10 } };
		t<std::string> string_val_or_ref{ val<std::string>{ "Your Dad" } };
		//t<state_machine<color>> color_state_machine_val_or_ref{ val<state_machine<color>>{ state_machine<color>{} } };

		std::cout << int_val_or_ref.value() << std::endl;
		std::cout << string_val_or_ref.value() << std::endl;
		//std::cout << color_state_machine_val_or_ref.value() << std::endl;

		t<int> int_val_or_ref2{ ref<int>{ int_val } };
		t<std::string> string_val_or_ref2{ ref<std::string>{ string_val } };
		//t<state_machine<color>> color_state_machine_val_or_ref2{ ref<state_machine<color>>{ color_state_machine_val } };

		std::cout << int_val_or_ref2.value() << std::endl;
		std::cout << string_val_or_ref2.value() << std::endl;
		//std::cout << color_state_machine_val_or_ref2.value() << std::endl;

		asset<int> int_asset{ "MyInt.int.asset", 32 };
		asset<std::string> string_asset{ "MyString.string.asset", "Hello world!" };
		//asset<state_machine<color>> color_state_machine_asset{ "MyColorStateMachine.state_machine.asset", state_machine<color>() };

		std::cout << int_asset.name() << std::endl;
		std::cout << string_asset.name() << std::endl;
		//std::cout << color_state_machine_asset.name() << std::endl;

		asset<int> int_asset2 = asset<int>::from_file("MyInt2.int.asset");
		asset<std::string> string_asset2 = asset<std::string>::from_file("MyString2.string.asset");
		//asset<state_machine<color>> color_state_machine_asset2 = asset<state_machine<color>>::from_file("MyColorStateMachine2.state_machine.asset");

		std::cout << int_asset2.name() << std::endl;
		std::cout << string_asset2.name() << std::endl;
		//std::cout << color_state_machine_asset2.name() << std::endl;

		instance<int> int_instance{ int_asset };
		instance<std::string> string_instance{ string_asset };
		//instance<state_machine<color>> color_state_machine_instance{ color_state_machine_asset };

		std::cout << int_instance.value() << std::endl;
		std::cout << string_instance.value() << std::endl;
		//std::cout << color_state_machine_instance.value() << std::endl;

		instance<int> int_instance2{ int_asset2 };
		instance<std::string> string_instance2{ string_asset2 };
		//instance<state_machine<color>> color_state_machine_instance2{ color_state_machine_asset2 };

		std::cout << int_instance2.value() << std::endl;
		std::cout << string_instance2.value() << std::endl;
		//std::cout << color_state_machine_instance2.value() << std::endl;

		optional<val<int>> optional_int_val{ val<int>{ 5 } };
		optional<val<std::string>> optional_string_val{ val<std::string>{ "Default" }};
		//optional<val<state_machine<color>>> optional_state_machine_color_val{ val<state_machine<color>>{ state_machine<color>() } };

		std::cout << optional_int_val.value() << std::endl;
		std::cout << optional_string_val.value() << std::endl;
		//std::cout << optional_state_machine_color_val.value() << std::endl;

		required<ref<int>> required_int_ref{};
		required<ref<std::string>> required_string_ref{};
		//required<ref<state_machine<color>>> required_state_machine_color_ref{};

		std::cout << required_int_ref.value() << std::endl;
		std::cout << required_string_ref.value() << std::endl;
		//std::cout << required_state_machine_color_ref.value() << std::endl;
		*/
		/*debug debug{};
		scene_manager scene_manager{};

		std::vector<engine_system*> all_systems{};
		all_systems.push_back(debug);

		engine_system_manager manager{all_systems};*/
	}
}
