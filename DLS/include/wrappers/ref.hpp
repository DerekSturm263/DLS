#pragma once

#include "interfaces/serializable.hpp"
#include "interfaces/unique.hpp"
#include "val.hpp"

namespace dls::core::wrappers {
	// Stores a reference to any given serializable value. This reference is id-based
	template <typename T>
	class ref : public interfaces::serializable<ref<T>> {
		private:
			interfaces::unique_base::guid_type _id;

			ref(interfaces::unique_base::guid_type id) : _id(id) { }

		public:
			ref() : _id(0) { }

			ref(val<T> const& value) : _id(value._id) { }
			ref(val<T>&& value) = delete;

			ref(ref<T> const& rhs) : _id(rhs._id) { }
			ref(ref<T>&& rhs) : _id(std::move(rhs._id)) { }
				
			interfaces::unique_base::guid_type id() const {
				return _id;
			}

			T const& value() const {
				return interfaces::unique<val<T>>::_ids_to_values[_id]->value();
			}

			T& value() {
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

			ref<T>& operator=(ref<T> const& rhs) {
				_id = rhs._id;
				return *this;
			}

			ref<T>& operator=(ref<T>&& rhs) {
				_id = std::move(rhs._id);
				return *this;
			}

			//static inline const ref<T> none{};
	};

	class ref_helper {
		public:
			template <typename T>
			static ref<T> make(val<T> const& value) {
				return ref<T>{ value };
			}
	};
}
