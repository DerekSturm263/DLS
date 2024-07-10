#pragma once

#include "miscellaneous/math_defines.hpp"
#include "types/core/system.hpp"
#include "miscellaneous/simulation_agent.hpp"

namespace dls::simulation::functions {
	template <typename Decimal, glm::length_t Size>
	class shape_cast : public core::interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

            void draw(std::string const& label) const override {

            }
	};
}

namespace dls::simulation::systems {
	template <typename Decimal, glm::length_t Size>
	class simulation : public core::types::system<functions::shape_cast<Decimal, Size>> {
		private:
			std::vector<simulation_agent<Decimal, Size>> _agents;

		public:
			void on_tick(game::tick& tick) override {
				for (auto& agent : _agents) {
					update_agent(tick, agent);
				}
			}

			void update_agent(game::tick& tick, simulation_agent<Decimal, Size>& agent) {

			}

			void save(core::interfaces::serializable_base::os& file) const override {

			}

			void load(core::interfaces::serializable_base::is& file) override {

			}

			void draw(std::string const& label) const override {

			}
	};

	using simulation_t = simulation<math::decimal, math::dimensions>;
}

REGISTER_SYSTEM("Simulation", dls::simulation::systems::simulation_t);
