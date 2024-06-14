#include "val.hpp"

namespace dls {
	template <typename T>
	val<T>::val(T const& value) : _value(value) { }

	template <typename T>
	T const& val<T>::value() {
		return _value;
	}
}
