#pragma once

#include "serializable.hpp"
#include "type_templates.hpp"
#include "event.hpp"

namespace dls {
	template <typename T>
	class processor : public serializable {
		private:
			type<event<T const& (T const&)>> _event;
			
		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_event));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_event));
			}
	};
}
