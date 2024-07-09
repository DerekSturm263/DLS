#pragma once

#include "interfaces/system.hpp"
#include "miscellaneous/simulation_agent.hpp"
#include "types/core/entity.hpp"
#include "types/core/scene.hpp"
#include "types/math/vector.hpp"
#include "miscellaneous/tick.hpp"
#include "miscellaneous/math_defines.hpp"

namespace dls::math::systems {
    template <typename Decimal, glm::length_t Size>
    class simulation : public system {
        private:
            std::vector<simulation_agent<Decimal, Size>> _agents;

        protected:
            void initialize() override {

            }

            void on_scene_load() override {
                _agents.clear();

                for (auto& ety : dls::core::scene{}.entities()) {
                    std::optional<modules::transform<Decimal, Size> const*> trans = ety.value().get_module<modules::transform<Decimal, Size>>();
                    std::optional<modules::physics<Decimal, Size> const*> phys = ety.value().get_module<modules::physics<Decimal, Size>>();
                    std::optional<modules::structure<Decimal, Size> const*> strct = ety.value().get_module<modules::structure<Decimal, Size>>();

                    if (trans.has_value() && phys.has_value() && strct.has_value()) {
                        _agents.push_back(simulation_agent<Decimal, Size>{ *trans.value(), *phys.value(), *strct.value() });
                    }
                }
            }

            void on_tick(game::tick& tick) override {
                int t = tick.index();

                for (auto& agent : _agents) {
                    agent.trans().position() = agent.initial_pos() + (agent.initial_speed() * t) + 1 / 2 * agent.acceleration() * t * t;
                }
            }

            void on_scene_unload() override {
                _agents.clear();
            }

            void shutdown() override {

            }

        public:
            static void set_velocity(game::tick& tick, simulation_agent<Decimal, Size>& agent, vector<Decimal, Size> const& velocity) {

            }

            static void set_acceleration(game::tick& tick, simulation_agent<Decimal, Size>& agent, vector<Decimal, Size> const& acceleration) {

            }
    };
}
