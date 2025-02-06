#pragma once

#include <unordered_map>
#include "types/miscellaneous/dropdown.hpp"

namespace dls::core::interfaces {
	class unique_base {
		public:
			using guid_type = unsigned long long;

			enum class sync_type {
				local, networked
			};
			using sync_type_dropdown = miscellaneous::types::dropdown<sync_type,
				sync_type::local,
				sync_type::networked
			>;

			guid_type _id;
			sync_type_dropdown _sync_type;

        protected:
			unique_base(guid_type id, sync_type sync_type) : _id(id), _sync_type(sync_type) { }
	};

	template <typename T>
	class unique : public unique_base {
		public:
			static inline std::unordered_map<guid_type, T*> _ids_to_values;

		protected:
			unique() : unique_base(rand(), sync_type::networked) {
				_ids_to_values[_id] = static_cast<T*>(this);
			}

			unique(guid_type id) : unique_base(id, sync_type::networked) {
				_ids_to_values[id] = static_cast<T*>(this);
			}
	};
}
