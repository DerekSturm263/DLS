#pragma once

#include "types/core/module.hpp"
#include "wrappers/type.hpp"
#include "types/math/vector.hpp"

namespace dls::simulation::functions {
	template <typename Decimal, glm::length_t Size>
	class set_velocity {};

    template <typename Decimal, glm::length_t Size>
    class add_force {};
}

namespace dls::simulation::modules {
	template <typename Decimal, glm::length_t Size>
	class simulation : public core::types::module<functions::set_velocity<Decimal, Size>, functions::add_force<Decimal, Size>> {
		private:
			core::wrappers::type<math::types::vector<Decimal, Size>> _initial_velocity;

		public:
			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_initial_velocity));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_initial_velocity);
			}
	};

	using simulation_t = simulation<float, 3>;
}

REGISTER_MODULE("SimulationModule", dls::simulation::modules::simulation_t);
