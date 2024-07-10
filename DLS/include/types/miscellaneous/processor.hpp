#pragma once

#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"
#include "../events/event.hpp"

namespace dls::miscellaneous::types {
	template <typename T>
	class processor : public core::interfaces::serializable<processor<T>> {
		private:
			core::wrappers::type<events::types::event<T(T const&)>> _event;
			
		public:
			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_event));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_event);
			}

			void draw(std::string const& label) const override {
				_event.draw("Event");
			}
	};
}
