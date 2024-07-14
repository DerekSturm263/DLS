#pragma once

#include "types/core/module.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::miscellaneous::types {
	template <typename T>
	class processor;
}

namespace dls::send_receive::functions {
	template <typename T>
	class send : public core::interfaces::function<void(T)> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<T> const& args) const override {

			}
	};
}

namespace dls::send_receive::modules {
	template <typename T>
	class sender : public core::types::module<functions::send<T>> {
		private:
			core::wrappers::type<miscellaneous::types::processor<T>> _pre_processor;

		public:
			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_pre_processor));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_pre_processor);
			}

			void draw(std::string const& label) const override {
				_pre_processor.draw("Pre-Processor");
			}
	};
}
