#pragma once

#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/miscellaneous/processor.hpp"

namespace dls::send_receive::modules {
	template <typename T>
	class receiver : public core::module<> {
		private:
			type<miscellaneous::processor<T>> _post_processor;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_post_processor));
			}

			void load(is& file) override {
				file(_post_processor);
			}
	};
}
