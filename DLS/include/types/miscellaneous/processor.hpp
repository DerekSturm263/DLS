#pragma once

#include "interfaces/serializable.hpp"
#include "type templates/type_templates.hpp"
#include "../events/event.hpp"

namespace dls::miscellaneous::types {
	template <typename T>
	class processor : public serializable<processor<T>> {
		private:
			val<events::types::event<T(T const&)>> _event;
			
		public:
			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_event));
			}

			void load(serializable_base::is& file) override {
				file(CEREAL_NVP(_event));
			}
	};
}
