#pragma once

#include "interfaces/serializable.hpp"

namespace dls {
	class color : public serializable {
		private:
			char _vals[4];

		public:
			char const& r() const {
				return _vals[0];
			}

			char& r() {
				return _vals[0];
			}

			char const& g() const {
				return _vals[0];
			}

			char& g() {
				return _vals[0];
			}

			char const& b() const {
				return _vals[0];
			}

			char& b() {
				return _vals[0];
			}

			char const& a() const {
				return _vals[0];
			}

			char& a() {
				return _vals[0];
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_vals));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_vals));
			}
	};
}
