#pragma once

#include "miscellaneous/math_defines.hpp"
#include "types/core/module.hpp"
#include "types/math/vector.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::simulation::functions {
	template <typename Decimal, glm::length_t Size>
	class set_acceleration : public core::interfaces::function<void(math::types::vector<Decimal, Size>)> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<math::types::vector<Decimal, Size>> const& args) const override {

			}
	};

	template <typename Decimal, glm::length_t Size>
	class set_velocity : public core::interfaces::function<void(math::types::vector<Decimal, Size>)> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<math::types::vector<Decimal, Size>> const& args) const override {

			}
	};
}

namespace dls::simulation::modules {
	template <typename Decimal, glm::length_t Size>
	class physics : public core::types::module<functions::set_acceleration<Decimal, Size>, functions::set_velocity<Decimal, Size>> {
		private:
			core::wrappers::type<math::types::vector<Decimal, Size>> _gravity;
			core::wrappers::type<Decimal> _mass;
			core::wrappers::type<Decimal> _linear_drag;
			core::wrappers::type<Decimal> _angular_drag;
			core::wrappers::type<math::types::vector<Decimal, Size>> _initial_velocity;

		protected:
			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_gravity));
				file(CEREAL_NVP(_mass));
				file(CEREAL_NVP(_linear_drag));
				file(CEREAL_NVP(_angular_drag));
				file(CEREAL_NVP(_initial_velocity));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_gravity);
				file(_mass);
				file(_linear_drag);
				file(_angular_drag);
				file(_initial_velocity);
			}

			void draw(std::string const& label) const override {
				_gravity.draw("Gravity");
				_mass.draw("Mass");
				_linear_drag.draw("Linear Drag");
				_angular_drag.draw("Angular Drag");
				_initial_velocity.draw("Initial Velocity");
			}
	};

	using physics_t = physics<math::decimal, math::dimensions>;
}

REGISTER_MODULE("Physics", dls::simulation::modules::physics_t);
