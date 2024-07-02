#pragma once

#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "event.hpp"

namespace dls {
	template <typename T>
	class processor : public serializable<processor<T>> {
		private:
			val<event<T(T const&)>> _event;
			
		public:
			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_event));
			}

			void load(serializable_base::is& file) override {
				file(CEREAL_NVP(_event));
			}
	};
}
