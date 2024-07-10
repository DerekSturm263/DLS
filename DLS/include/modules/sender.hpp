#pragma once

#include "types/core/module.hpp"
#include "type templates/type_templates.hpp"
#include "types/miscellaneous/processor.hpp"

namespace dls::send_receive::functions {
	template <typename T>
	class send : public function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}
	};
}

namespace dls::send_receive::modules {
	template <typename T>
	class sender : public core::types::module<functions::send<T>> {
		private:
			type<miscellaneous::types::processor<T>> _pre_processor;

		public:
			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_pre_processor));
			}

			void load(serializable_base::is& file) override {
				file(_pre_processor);
			}
	};
}
