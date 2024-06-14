#include "asset.hpp"
#include "instance.hpp"
#include "optional.hpp"
#include "ref.hpp"
#include "required.hpp"
#include "t.hpp"
#include "val.hpp"

namespace dls {
	template <typename T>
	using type = required<t<T>>;
}
