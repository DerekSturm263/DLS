#pragma once

#include <functional>

namespace dls::functions::helpers {
	template <typename Func, typename = void>
	class func_traits;

	template <typename Result, typename... Args>
	class func_traits<std::function<Result(Args...)>> {
		public:
			using return_type = Result;
			using args_type = std::tuple<Args...>;
	};
}
