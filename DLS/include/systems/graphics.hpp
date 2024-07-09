#pragma once

#include "interfaces/system.hpp"
#include "miscellaneous/graphics_agent.hpp"

namespace dls::graphics::systems {
	class graphics : public system<> {
		private:
			std::vector<graphics_agent> _agents;

        public:
			void on_update() override {
				for (auto& agent : _agents) {
					update_agent(agent);
				}
			}

			void update_agent(graphics_agent& agent) {

			}

            void save(os& file) const override {

            }

            void load(is& file) override {

            }
	};
}
