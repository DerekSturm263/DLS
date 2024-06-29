#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/processor.hpp"

namespace dls {
	class sender : public module<> {
		private:
			type<processor<void*>> _pre_processor;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_pre_processor));
			}

			void load(is& file) override {
				file(_pre_processor);
			}
	};
}

REGISTER_MODULE(dls::sender);
