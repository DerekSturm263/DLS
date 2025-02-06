#pragma once

#include "types/core/system.hpp"
#include "modules/transform.hpp"
#include "modules/simulation.hpp"
#include "interfaces/systems/on_entity_spawn.hpp"
#include "interfaces/systems/on_entity_despawn.hpp"

namespace dls::simulation::functions {
    class set_speed {};
}

namespace dls::simulation::systems {
	template <typename Decimal, glm::length_t Size>
	class simulation : public core::types::system<functions::set_speed>, public core::interfaces::i_on_entity_spawn, public core::interfaces::i_on_entity_despawn {
		private:
            class agent {
                private:
                    core::interfaces::unique_base::guid_type _guid;

                    math::modules::transform<Decimal, Size> const* _transform;
                    modules::simulation<Decimal, Size> const* _simulation;

                public:
                    agent(core::interfaces::unique_base::guid_type guid, math::modules::transform<Decimal, Size> const* transform, modules::simulation<Decimal, Size> const* simulation) : _guid(guid), _transform(transform), _simulation(simulation) { }

                    void simulate() const {
                    
                    }

                    bool operator>(agent const& rhs) const {
                        return _guid > rhs._guid;
                    }

                    bool operator<(agent const& rhs) const {
                        return _guid < rhs._guid;
                    }
            };

			std::set<agent> _agents;

        public:
			void update() override {
                for (auto& agent : _agents) {
                    agent.simulate();
                }
            }

            void on_entity_spawn(miscellaneous::game& game, core::types::entity const& entity) override {
                auto modules = entity.get_modules<math::modules::transform<Decimal, Size>, modules::simulation<Decimal, Size>>();
        
                if (modules.has_value()) {
                    auto transform = std::get<math::modules::transform<Decimal, Size> const*>(modules.value());
                    auto simulation = std::get<modules::simulation<Decimal, Size> const*>(modules.value());

                    // TODO: Generate ID without reference.
                    auto agt = agent(0, transform, simulation);
                    _agents.insert(std::move(agt));
                }
            }

            void on_entity_despawn(miscellaneous::game& game, core::types::entity const& entity) override {
                auto modules = entity.get_modules<math::modules::transform<Decimal, Size>, modules::simulation<Decimal, Size>>();
        
                if (modules.has_value()) {
                    auto transform = std::get<math::modules::transform<Decimal, Size> const*>(modules.value());
                    auto simulation = std::get<modules::simulation<Decimal, Size> const*>(modules.value());
                    
                    // TODO: Generate ID without reference.
                    auto agt = agent(0, transform, simulation);
                    _agents.erase(agt);
                }
            }

            void save(core::interfaces::serializable_base::os& file) const override {

            }

            void load(core::interfaces::serializable_base::is& file) override {

            }
	};

	using simulation_t = simulation<float, 3>;
}

REGISTER_SYSTEM("SimulationSystem", dls::simulation::systems::simulation_t);
