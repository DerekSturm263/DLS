#pragma once

#include "interfaces/unique.hpp"
#include "val.hpp"

namespace dls::core::wrappers {
	/// <summary>
	/// Stores a reference to any given serializable value. This reference is id-based
	/// </summary>
	/// <typeparam name="T">Type to reference (must be serializable)</typeparam>
	template <typename T>
	class ref : public interfaces::serializable<ref<T>> {
		private:
			interfaces::unique_base::guid_type _id;

			ref(interfaces::unique_base::guid_type id) : _id(id) { }

			template <typename T>
			friend class required;

		public:
			ref() : _id(0) { }
			ref(val<T> const& value) : _id(value._id) { }

			T& value() {
				return interfaces::unique<val<T>>::_ids_to_values[_id]->value();
			}

			T const& value() const {
				return interfaces::unique<val<T>>::_ids_to_values[_id]->value();
			}

			bool is_valid() const {
				return _id != 0;
			}

			void save(interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_id));
			}

			void load(interfaces::serializable_base::is& file) override {
				file(_id);
			}

			void draw(std::string const& label) const override {

			}

			//static inline const ref<T> none{};
	};
}
