#pragma once

#include "modules/transform.hpp"
#include "modules/physics.hpp"
#include "modules/structure.hpp"

namespace dls::math {
	template <typename Decimal, glm::length_t Size>
	class simulation_agent {
		public:
			modules::transform<Decimal, Size>& trans;
			modules::physics<Decimal, Size>& phys;
			modules::structure<Decimal, Size>& strct;

			types::vector<Decimal, Size> initial_pos;
			types::vector<Decimal, Size> initial_speed;
			types::vector<Decimal, Size> acceleration;

			simulation_agent(
				modules::transform<Decimal, Size> const& trans,
				modules::physics<Decimal, Size> const& phys,
				modules::structure<Decimal, Size> const& strct
			) : trans(trans), phys(phys), strct(strct) { }
	};
}
