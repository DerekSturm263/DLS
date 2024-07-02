#pragma once

#include <unordered_map>
#include "engine systems/random.hpp"

namespace dls {
	class unique_base {
		public:
			using guid = unsigned long long;

			enum class sync_type {
				local,
				networked
			};
	};

	template <typename T>
	class unique : public unique_base {
        protected:
			guid _id;

			// TODO: ALLOCATE ON HEAP
			static inline std::unordered_map<guid, T*> _ids_to_values;

			unique() : _id(random::next<guid>()) {
				_ids_to_values[_id] = static_cast<T*>(this);
			}

			unique(guid id) : _id(id) {
				_ids_to_values[id] = static_cast<T*>(this);
			}

			template <typename T>
			friend class ref;
	};
}
