#pragma once

#include "interfaces/serializable.hpp"
#include "interfaces/function.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::events::types {
	class statement_base : public core::interfaces::serializable<statement_base> {
		public:
			virtual void invoke(game::game& game, std::vector<void*> const& event_args) const = 0;
	};

	template <typename TFunc>
	class statement : public statement_base {
		public:
			using return_type = dls::functions::helpers::func_traits<std::function<TFunc>>::return_type;
			using args_type = dls::functions::helpers::func_traits<std::function<TFunc>>::args_type;

		private:
			core::wrappers::ref<core::interfaces::function<TFunc>> _function;
			args_type _arguments;

		public:
			void invoke(game::game& game, std::vector<void*> const& event_args) const {
				if (_function.is_valid()) {
					_function.value().invoke(game, event_args, _arguments);
				}
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_function));
				file(CEREAL_NVP(_arguments));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_function);
				file(_arguments);
			}

			void draw(std::string const& label) const override {

			}
	};
}
