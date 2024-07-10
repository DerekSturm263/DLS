#pragma once

#include <unordered_map>

namespace dls {
	class unique_base {
		public:
			using guid_type = unsigned long long;

			enum class sync_type {
				local,
				networked
			};

        protected:
			guid_type _id;
			sync_type _sync_type;

			unique_base(guid_type id, sync_type sync_type) : _id(id), _sync_type(sync_type) { }

			template <typename T>
			friend class ref;
	};

	template <typename T>
	class unique : public unique_base {
		protected:
			static inline std::unordered_map<guid_type, T*> _ids_to_values;

			/*unique() : unique_base(math::systems::random::instance()->next<guid_type>(), sync_type::networked) {
				_ids_to_values[_id] = static_cast<T*>(this);
			}*/

			// TODO: FIX THIS TO USE UNSIGNED LONG LONGS
			unique() : unique_base(rand(), sync_type::networked) {
				_ids_to_values[_id] = static_cast<T*>(this);
			}

			unique(guid_type id) : unique_base(id, sync_type::networked) {
				_ids_to_values[id] = static_cast<T*>(this);
			}

			template <typename T>
			friend class ref;
	};
}
