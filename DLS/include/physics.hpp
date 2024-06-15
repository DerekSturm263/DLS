#pragma once

#include "module.hpp"
#include "type_templates.hpp"
#include "fixed.hpp"
#include "set_velocity.hpp"
#include "set_acceleration.hpp"

namespace dls {
	class physics : public module<set_velocity, set_acceleration> {
		private:
			type<fixed<32>> _mass;
			type<fixed<32>> _gravity_scale;
			type<fixed<32>> _linear_drag;
			type<fixed<32>> _angular_drag;
			
		protected:
			void save(os& file) const override {

			}

			void load(is& file) const override {

			}
	};
}

REGISTER_MODULE(dls::physics);
