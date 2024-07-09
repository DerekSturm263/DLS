#pragma once

#include "interfaces/system.hpp"
#include "miscellaneous/simulation_agent.hpp"

namespace dls::math::systems {
	template <typename Decimal, glm::length_t Size>
	class simulation : public system<> {
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

			void save(os& file) const override {

			}

			void load(is& file) override {

			}
	};
}
