#pragma once

#include "unique.hpp"
#include "val.hpp"

namespace dls {
	/// <summary>
	/// Stores a reference to any given serializable value. This reference is id-based
	/// </summary>
	/// <typeparam name="T">Type to reference (must be serializable)</typeparam>
	template <typename T>
	class ref : public serializable {
		private:
			const unique_base::guid _id;

			ref(unique_base::guid id) : _id(_id) { }

		public:
			ref(val<T> const& value) : _id(value._id) { }

			T const& value() const {
				return *(unique<val<T>>::_ids_to_values[_id]);
			}

			//const ref<T> none = ref<T>(0);
	};
}
