#pragma once

namespace dls::math::interfaces {
	template <typename Decimal, typename TSelf>
	class interpolatable {
        protected:
			virtual TSelf lerp(TSelf const&, Decimal) const = 0;
			virtual Decimal inverse_lerp(TSelf const&, TSelf const&) const = 0;
	};
}
