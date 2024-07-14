#pragma once

#include <vector>
#include "statement.hpp"

namespace dls::events::types {
	class event_base : public core::interfaces::serializable<event_base> {
		protected:
			std::vector<core::wrappers::val<std::unique_ptr<statement_base>>> _funcs;
	};

	template <typename TFunc>
	class event : public event_base {
		public:
			using return_type = dls::functions::helpers::func_traits<std::function<TFunc>>::return_type;
			using args_type = dls::functions::helpers::func_traits<std::function<TFunc>>::args_type;

			return_type invoke(game::game& game, args_type const& args) const {
				return_type output{};

				for (auto& func : _funcs) {
					std::vector<void*> event_args{};
					func.value().get()->invoke(game, event_args);
				}

				return output;
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_funcs));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_funcs);
			}

			void draw(std::string const& label) const override {

			}
	};
}
