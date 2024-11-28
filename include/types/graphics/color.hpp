#pragma once

#include "interfaces/serializable.hpp"
#include "types/collections/array.hpp"

namespace dls::graphics::types {
	template <typename Precision>
	class color : public core::interfaces::serializable<color<Precision>> {
		private:
			dls::collections::types::array<Precision, 4> _vals;

		public:
			color() : _vals(0, 0, 0, 1) { }

			color(Precision r, Precision g, Precision b) : _vals(r, g, b, 1) { }
			color(Precision r, Precision g, Precision b, Precision a) : _vals(r, g, b, a) { }

			color(Precision const (&rgb)[3]) : _vals(rgb[0], rgb[1], rgb[2], 1) { }
			color(Precision (&& rgb)[3]) : _vals(std::move(rgb[0]), std::move(rgb[1]), std::move(rgb[2]), 1) { }

			color(Precision const (&rgb)[4]) : _vals(rgb) { }
			color(Precision (&& rgb)[4]) : _vals(std::move(rgb)) { }

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

			void save(core::interfaces::serializable_base::os& file) const override {
				file(CEREAL_NVP(_vals));
			}

			void load(core::interfaces::serializable_base::is& file) override {
				file(_vals);
			}
	};
}
