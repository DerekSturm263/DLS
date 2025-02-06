#pragma once

#include <cereal/archives/json.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/variant.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/utility.hpp>
#include <cereal/types/tuple.hpp>

namespace dls::core::interfaces {
	class serializable_base {
        public:
			using os = cereal::JSONOutputArchive;
			using is = cereal::JSONInputArchive;
			
			virtual void save(os&) const = 0;
			virtual void load(is&) = 0;
	};

	template <typename TSelf>
	class serializable : public serializable_base {
		public:
			friend std::ostream& operator<< (std::ostream& stream, TSelf const& rhs) {
				std::string str = rhs;
				stream << str;

				return stream;
			}

			virtual operator std::string() const {
				std::ostringstream stream;

				os archive{ stream };
				archive(*this);

				return stream.str();
			}
	};
}
