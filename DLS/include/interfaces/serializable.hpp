#pragma once

#include <cereal/archives/json.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/variant.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/utility.hpp>

namespace dls {
	class serializable {
        public:
			using os = cereal::JSONOutputArchive;
			using is = cereal::JSONInputArchive;

			// TODO: Move to debug or build into each class
			template <typename T>
			static std::string to_string(T serializable) {
				std::ostringstream stream;

				os archive{ stream };
				archive(serializable);

				return stream.str();
			}

		protected:
			virtual void save(os&) const = 0;
			virtual void load(is&) = 0;
	};
}
