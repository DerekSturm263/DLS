#pragma once

#include <cereal/archives/json.hpp>
#include <cereal/types/functional.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/utility.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/variant.hpp>
#include <cereal/types/tuple.hpp>
#include <cereal/types/array.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/set.hpp>
#include <cereal/types/unordered_set.hpp>

namespace dls {
	class serializable {
        public:
			using os = cereal::JSONOutputArchive;
			using is = cereal::JSONInputArchive;

		protected:
			virtual void save(os&) const = 0;
			virtual void load(is&) const = 0;
	};
}
