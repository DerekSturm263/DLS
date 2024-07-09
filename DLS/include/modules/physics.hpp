#pragma once

#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/math/fixed.hpp"
#include "types/math/vector.hpp"

namespace dls::math::modules {
	template <typename Decimal, glm::length_t Size>
	class physics : public core::module<> {
		private:
			type<Decimal> _mass;
			type<vector<Decimal, Size>> _gravity;
			type<Decimal> _linear_drag;
			type<Decimal> _angular_drag;
			
		protected:
			void save(os& file) const override {
				file(CEREAL_NVP(_mass));
				file(CEREAL_NVP(_gravity));
				file(CEREAL_NVP(_linear_drag));
				file(CEREAL_NVP(_angular_drag));
			}

			void load(is& file) override {
				file(_mass);
				file(_gravity);
				file(_linear_drag);
				file(_angular_drag);
			}
	};
	/*
	class set_acceleration : public function {
		public:
			void invoke(tick&, std::vector<void*> const&, std::vector<void*>*) override {
				simulation_agent* rb = static_cast<simulation_agent*>(input[0]);
				vector<fixed32, 3>* acc = static_cast<vector<fixed32, 3>*>(input[1]);

				simulation::set_acceleration(tick, *rb, *acc);
			}
	};

	class set_velocity : public function {
		public:
			void invoke(tick&, std::vector<void*> const&, std::vector<void*>*) override {
				simulation_agent* rb = static_cast<simulation_agent*>(input[0]);
				vector<fixed32, 3>* vel = static_cast<vector<fixed32, 3>*>(input[1]);

				simulation::set_velocity(tick, *rb, *vel);
			}
	};
	*/
}
