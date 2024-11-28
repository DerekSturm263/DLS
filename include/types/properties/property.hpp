#pragma once

#include <variant>
#include "interfaces/serializable.hpp"
#include "wrappers/val.hpp"

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

namespace dls::properties::types {
	class property : public core::interfaces::serializable<property> {
		public:
			using any = dls::miscellaneous::types::variant<
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
				//dls::math::types::transform<dls::math::types::decimal<unsigned long long, float, 1 << 16>, 2>,
				//dls::math::types::transform<dls::math::types::decimal<unsigned long long, float, 1 << 16>, 3>,
				dls::math::types::transformation<float, 2>,
				dls::math::types::transformation<float, 3>,
				//dls::graphics::types::color<dls::math::types::decimal<unsigned long long, float, 1 << 16>>,
				dls::graphics::types::color<float>,
				dls::graphics::types::material,
				dls::graphics::types::mesh,
				dls::graphics::types::shader,
				dls::graphics::types::texture<2>,
				dls::graphics::types::texture<3>,
				dls::input::types::input_trigger
			>;

		private:
			core::wrappers::val<any> _value;
			
		public:
			property() : _value() { }
			
			property(any const& value) : _value(value) { }
			property(any&& value) : _value(std::move(value)) { }

			any const& value() const {
				return _value.value();
			}

			any& value() {
				return _value.value();
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_value));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_value);
			}

		private:
			template <typename T>
			std::string to_string(T const& t) const {
				return t;
			}

			template <>
			std::string to_string<int>(int const& t) const {
				return std::to_string(t);
			}

			template <>
			std::string to_string<long long>(long long const& t) const {
				return std::to_string(t);
			}

			template <>
			std::string to_string<float>(float const& t) const {
				return std::to_string(t);
			}

			template <>
			std::string to_string<double>(double const& t) const {
				return std::to_string(t);
			}

			template <>
			std::string to_string<bool>(bool const& t) const {
				return std::to_string(t);
			}

		public:
			operator std::string() const override {
				std::string output = std::visit([&](auto&& arg) { return to_string(arg); }, value().value());
				return output;
			}

			template <typename T>
			property& operator=(T const& rhs) {
				_value.value().value() = rhs;
				return *this;
			}
	};
}
