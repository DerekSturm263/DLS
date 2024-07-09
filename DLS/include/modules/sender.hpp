#pragma once

#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/miscellaneous/processor.hpp"

namespace dls::send_receive::modules {
	template <typename T>
	class sender : public core::types::module<> {
		private:
			type < miscellaneous::types::processor<T >> _pre_processor;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_pre_processor));
			}

			void load(is& file) override {
				file(_pre_processor);
			}
	};
}
