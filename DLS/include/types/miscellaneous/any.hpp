#include "types/miscellaneous/variant.hpp"
#include "types/miscellaneous/boolean.hpp"
#include "types/miscellaneous/text.hpp"
#include "types/math/integer.hpp"
#include "types/math/decimal.hpp"
#include "types/math/vector.hpp"
#include "types/math/matrix.hpp"
#include "types/math/quaternion.hpp"
#include "types/math/transformation.hpp"
#include "types/graphics/color.hpp"
#include "types/graphics/material.hpp"
#include "types/graphics/mesh.hpp"
#include "types/graphics/shader.hpp"
#include "types/graphics/texture.hpp"
#include "types/input/input_trigger.hpp"

namespace dls::miscellaneous::types {
	using any = miscellaneous::types::variant<
		dls::miscellaneous::types::boolean,
		dls::miscellaneous::types::text,
		dls::math::types::integer,
		dls::math::types::decimal<unsigned long long, float, 1 << 16>,
		dls::math::types::vector<dls::math::types::integer, 2>,
		dls::math::types::vector<dls::math::types::integer, 3>,
		dls::math::types::vector<dls::math::types::integer, 4>,
		//dls::math::types::vector<dls::math::types::decimal<unsigned long long, float, 1 << 16>, 2>,
		//dls::math::types::vector<dls::math::types::decimal<unsigned long long, float, 1 << 16>, 3>,
		//dls::math::types::vector<dls::math::types::decimal<unsigned long long, float, 1 << 16>, 4>,
		dls::math::types::vector<float, 2>,
		dls::math::types::vector<float, 3>,
		dls::math::types::vector<float, 4>,
		dls::math::types::matrix<dls::math::types::integer, 2, 2>,
		dls::math::types::matrix<dls::math::types::integer, 3, 3>,
		dls::math::types::matrix<dls::math::types::integer, 4, 4>,
		//dls::math::types::matrix<dls::math::types::decimal<unsigned long long, float, 1 << 16>, 2, 2>,
		//dls::math::types::matrix<dls::math::types::decimal<unsigned long long, float, 1 << 16>, 3, 3>,
		//dls::math::types::matrix<dls::math::types::decimal<unsigned long long, float, 1 << 16>, 4, 4>,
		dls::math::types::matrix<float, 2, 2>,
		dls::math::types::matrix<float, 3, 3>,
		dls::math::types::matrix<float, 4, 4>,
		//dls::math::types::quaternion<dls::math::types::decimal<unsigned long long, float, 1 << 16>>,
		dls::math::types::quaternion<float>,
		//dls::math::types::transformation<dls::math::types::decimal<unsigned long long, float, 1 << 16>, 2>,
		//dls::math::types::transformation<dls::math::types::decimal<unsigned long long, float, 1 << 16>, 3>,
		dls::math::types::transformation<float, 2>,
		dls::math::types::transformation<float, 3>,
		//dls::graphics::types::color<dls::math::types::decimal<unsigned long long, float, 1 << 16>>,
		dls::graphics::types::color<float>,
		dls::graphics::types::texture<2>,
		dls::graphics::types::texture<3>,
		dls::graphics::types::mesh,
		dls::graphics::types::shader,
		dls::input::types::input_trigger
	>;
}