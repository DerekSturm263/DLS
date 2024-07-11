#pragma once

#include "types/core/system.hpp"
#include "miscellaneous/graphics_agent.hpp"

namespace dls::graphics::functions {
	template <typename Decimal, glm::length_t Size>
	class render : public core::interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};
}

namespace dls::graphics::systems {
	template <typename Decimal, glm::length_t Size>
	class graphics : public core::types::system<functions::render<Decimal, Size>> {
		private:
			std::vector<graphics_agent<Decimal, Size>> _agents;

        public:
			void update() {
				for (auto& agent : _agents) {
					update_agent(agent);
				}
			}

			void update_agent(graphics_agent<Decimal, Size> const& agent) {

			}

            void save(core::interfaces::serializable_base::os& file) const override {

            }

            void load(core::interfaces::serializable_base::is& file) override {

            }

			void draw(std::string const& label) const override {

			}
	};

	using graphics_t = graphics<math::decimal, math::dimensions>;
}

REGISTER_SYSTEM("Graphics", dls::graphics::systems::graphics_t);
