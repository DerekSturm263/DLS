#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/transform.hpp"
#include "types/fixed.hpp"

namespace dls {
	template <typename T, size_t Size>
	class transformer : public module<> {
		private:
			type<transform<T, Size>> _transform;

		public:
			transformer() : _transform() { }
			
			void save(os& file) const override {
				file(CEREAL_NVP(_transform));
			}

			void load(is& file) override {
				file(_transform);
			}
	};
}

REGISTER_MODULE(dls::transformer);
