#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/fixed.hpp"
#include "types/vector.hpp"
#include "functions/set_velocity.hpp"
#include "functions/set_acceleration.hpp"

namespace dls {
	class physics : public module<set_velocity, set_acceleration> {
		private:
			type<fixed32> _mass;
			type<vector<fixed32, 3>> _gravity;
			type<fixed32> _linear_drag;
			type<fixed32> _angular_drag;
			
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
}

REGISTER_MODULE(dls::physics);
