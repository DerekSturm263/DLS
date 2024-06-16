#include "engine.hpp"
#include "types/entity.hpp"
#include "types/property_group.hpp"
#include <vector>
#include <string>
#include <iostream>

namespace dls {
	int engine::execute(int argc, char* argv[]) {
		/*val<property_group> props2{};
		props2.value().at("name").value() = "Derek";
		props2.value().at("age").value() = 21;
		props2.value().at("is_male").value() = true;
		props2.value().at("health").value() = 20;
		props2.value().at("mana").value() = 0;
		std::cout << serializable::to_string(props2) << std::endl;*/

		asset<property_group> props{"assets/character_stats.property_group.asset"};

		/*instance<property_group> props2{props};
		props2.value().at("name").value() = "Derek";
		props2.value().at("age").value() = 21;
		props2.value().at("is_male").value() = true;
		std::cout << serializable::to_string(props2.value()) << std::endl;*/

		std::cout << "Name: " << props.value().at("name") << std::endl;
		std::cout << "Age: " << props.value().at("age") << std::endl;
		std::cout << "Is Male: " << props.value().at("is_male") << std::endl;
		std::cout << "Health: " << props.value().at("health") << std::endl;
		std::cout << "Mana: " << props.value().at("mana") << std::endl;

		return 0;
	}
}
