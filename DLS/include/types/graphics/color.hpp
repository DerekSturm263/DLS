#pragma once

#include "interfaces/serializable.hpp"

namespace dls::graphics::types {
	template <typename Precision>
	class color : public serializable<color<Precision>> {
		private:
			Precision _vals[4];

		public:
			color() : _vals{ 0, 0, 0, 1 } { }
			color(Precision r, Precision g, Precision b) : _vals{ r, g, b, 1 } { }
			color(Precision r, Precision g, Precision b, Precision a) : _vals{ r, g, b, a } { }

			Precision const& r() const {
				return _vals[0];
			}

			Precision& r() {
				return _vals[0];
			}

			Precision const& g() const {
				return _vals[1];
			}

			Precision& g() {
				return _vals[1];
			}

			Precision const& b() const {
				return _vals[2];
			}

			Precision& b() {
				return _vals[2];
			}

			Precision const& a() const {
				return _vals[3];
			}

			Precision& a() {
				return _vals[3];
			}

			void save(serializable_base::os& file) const override {
				file(CEREAL_NVP(_vals));
			}

			void load(serializable_base::is& file) override {
				file(_vals);
			}
	};
}
