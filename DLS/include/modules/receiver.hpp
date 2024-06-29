#pragma once

#include "types/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/processor.hpp"

namespace dls {
	class receiver : public module<> {
		private:
			type<processor<void*>> _post_processor;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_post_processor));
			}

			void load(is& file) override {
				file(_post_processor);
			}
	};
}

REGISTER_MODULE(dls::receiver);
