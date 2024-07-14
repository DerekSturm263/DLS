#pragma once

#include "helpers/functions.hpp"
#include "miscellaneous/param_ref.hpp"
#include "unique.hpp"

namespace dls::game {
	class game;
}

namespace dls::core::interfaces {
	class function_base : public unique<function_base> {

	};

	template <typename TFunc>
	class function : public function_base {
		public:
			using return_type = dls::functions::helpers::func_traits<std::function<TFunc>>::return_type;
			using args_type = dls::functions::helpers::func_traits<std::function<TFunc>>::args_type;

			virtual return_type invoke(game::game& game, std::vector<void*> const& event_args, args_type const& func_args) const = 0;
	};
}
