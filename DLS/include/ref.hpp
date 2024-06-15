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

			ref() : _id(0) { }
			ref(unique_base::guid id) : _id(_id) { }

			template <typename T>
			friend class required;
			
		protected:
			void save(os& file) const override {
				file(CEREAL_NVP(_id));
			}

			void load(is& file) const override {
				file(_id);
			}

		public:
			ref(val<T> const& value) : _id(value._id) { }

			const T& value() const {
				return unique<val<T>>::_ids_to_values[_id]->value();
			}

			bool is_valid() {
				return _id != 0;
			}

			//static inline const ref<T> none{};
	};
}
