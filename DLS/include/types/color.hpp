#pragma once

#include "interfaces/serializable.hpp"

namespace dls {
	class color : public serializable<color> {
		private:
			char _vals[4];

		public:
			color() : _vals{ 0, 0, 0, 0 } { }
			color(char r, char g, char b, char a) : _vals{r, g, b, a} { }

			char const& r() const {
				return _vals[0];
			}

			char& r() {
				return _vals[0];
			}

			char const& g() const {
				return _vals[1];
			}

			char& g() {
				return _vals[1];
			}

			char const& b() const {
				return _vals[2];
			}

			char& b() {
				return _vals[2];
			}

			char const& a() const {
				return _vals[3];
			}

			char& a() {
				return _vals[3];
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_vals));
			}

			void load(is& file) override {
				file(CEREAL_NVP(_vals));
			}
	};
}
