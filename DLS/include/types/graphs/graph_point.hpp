#pragma once

#include "interfaces/serializable.hpp"

namespace dls::graph::types {
	template <typename T>
	class graph_point : public core::interfaces::serializable<graph_point<T>> {
		private:
			core::wrappers::type<T> _value;

		public:
			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_value));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(CEREAL_NVP(_value));
			}

			void draw(std::string const& label) const override {
				_value.draw("Value");
			}
	};
}
