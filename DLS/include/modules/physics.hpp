#pragma once

#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/math/fixed.hpp"
#include "types/math/vector.hpp"

namespace dls::math::functions {
	template <typename Decimal, glm::length_t Size>
	class set_acceleration : public function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {
				//simulation_agent* rb = static_cast<simulation_agent*>(inputs[0]);
				//types::vector<Decimal, Size>* acc = static_cast<types::vector<Decimal, Size>*>(inputs[1]);
			}
	};

	template <typename Decimal, glm::length_t Size>
	class set_velocity : public function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {
				//simulation_agent* rb = static_cast<simulation_agent*>(inputs[0]);
				//types::vector<Decimal, Size>* vel = static_cast<types::vector<Decimal, Size>*>(inputs[1]);
			}
	};
}

namespace dls::math::modules {
	template <typename Decimal, glm::length_t Size>
	class physics : public core::types::module<functions::set_acceleration<Decimal, Size>, functions::set_velocity<Decimal, Size>> {
		private:
			type<types::vector<Decimal, Size>> _gravity;
			type<Decimal> _mass;
			type<Decimal> _linear_drag;
			type<Decimal> _angular_drag;
			type<types::vector<Decimal, Size>> _initial_velocity;

		protected:
			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_mass));
				file(CEREAL_NVP(_gravity));
				file(CEREAL_NVP(_linear_drag));
				file(CEREAL_NVP(_angular_drag));
				file(CEREAL_NVP(_initial_velocity));
			}

			void load(serializable_base::is& file) override {
				file(_mass);
				file(_gravity);
				file(_linear_drag);
				file(_angular_drag);
				file(_initial_velocity);
			}
	};
}
