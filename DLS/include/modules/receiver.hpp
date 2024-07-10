#pragma once

#include "types/core/module.hpp"
#include "wrappers/wrappers.hpp"
#include "types/miscellaneous/processor.hpp"

namespace dls::send_receive::modules {
	template <typename T>
	class receiver : public core::types::module<> {
		private:
			core::wrappers::type<miscellaneous::types::processor<T>> _post_processor;

		public:
			void save(os& file) const override {
				file(CEREAL_NVP(_post_processor));
			}

			void load(is& file) override {
				file(_post_processor);
			}

			void draw(std::string const& label) const override {
				_post_processor.draw("Post-Processor");
			}
	};
}
