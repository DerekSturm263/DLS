#pragma once

#include "modules/transform.hpp"
#include "modules/physics.hpp"
#include "modules/structure.hpp"

namespace dls::math {
	template <typename Decimal, glm::length_t Size>
	class simulation_agent {
		private:
			modules::transform<Decimal, Size>& _trans;
			modules::physics<Decimal, Size>& _phys;
			modules::structure<Decimal, Size>& _strct;

			vector<Decimal, Size> _initial_pos;
			vector<Decimal, Size> _initial_speed;
			vector<Decimal, Size> _acceleration;

			simulation_agent(
				modules::transform<Decimal, Size> const& trans,
				modules::physics<Decimal, Size> const& phys,
				modules::structure<Decimal, Size> const& strct
			) : _trans(trans), _phys(phys), _strct(strct), _initial_pos(trans.transform().position()) { }

		public:
			modules::transform<Decimal, Size>& trans() {
				return _trans;
			}

			modules::physics<Decimal, Size>& phys() {
				return _phys;
			}

			modules::structure<Decimal, Size>& strct() {
				return _strct;
			}

			vector<Decimal, Size>& initial_pos() {
				return _initial_pos;
			}
			
			vector<Decimal, Size>& initial_speed() {
				return _inital_speed;
			}

			vector<Decimal, Size>& acceleration() {
				return _acceleration;
			}
	};
}
