#pragma once

#include "interfaces/unique.hpp"
#include "val.hpp"

namespace dls {
	/// <summary>
	/// Stores a reference to any given serializable value. This reference is id-based
	/// </summary>
	/// <typeparam name="T">Type to reference (must be serializable)</typeparam>
	template <typename T>
	class ref : public serializable<ref<T>> {
		private:
			unique_base::guid _id;

			ref(unique_base::guid id) : _id(_id) { }

			template <typename T>
			friend class required;

		public:
			ref() : _id(0) { }
			ref(val<T> const& value) : _id(value._id) { }

			T const& value() const {
				return unique<val<T>>::_ids_to_values[_id]->value();
			}

			bool is_valid() const {
				return _id != 0;
			}

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_id));
			}

			void load(serializable_base::is& file) override {
				file(_id);
			}

			//static inline const ref<T> none{};
	};
}
