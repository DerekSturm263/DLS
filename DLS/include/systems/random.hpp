#pragma once

#include <random>
#include <limits>
#include "wrappers/wrappers.hpp"
#include "types/core/system.hpp"

namespace dls::math::functions {
	class next : public core::interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

            void draw(std::string const& label) const override {

            }
	};

	class next_range : public core::interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

            void draw(std::string const& label) const override {

            }
	};
}

namespace dls::math::systems {
	class random : public core::types::system<functions::next, functions::next_range> {
        private:
            core::wrappers::type<unsigned int> _seed;
            std::default_random_engine _engine;

        public:
            bool initialize() override;
            void shutdown() override;

            template <typename T>
            T next() {
                std::uniform_int_distribution<T> distr(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
                return distr(_engine);
            }

            template <>
            float next() {
                std::uniform_real_distribution<float> distr(std::numeric_limits<float>::min(), std::numeric_limits<float>::max());
                return distr(_engine);
            }

            template <>
            double next() {
                std::uniform_real_distribution<double> distr(std::numeric_limits<double>::min(), std::numeric_limits<double>::max());
                return distr(_engine);
            }

            template <typename T>
            T next_range(T min, T max) {
                std::uniform_int_distribution<T> distr(min, max);
                return distr(_engine);
            }

            template <>
            float next_range(float min, float max) {
                std::uniform_real_distribution<float> distr(min, max);
                return distr(_engine);
            }

            template <>
            double next_range(double min, double max) {
                std::uniform_real_distribution<double> distr(min, max);
                return distr(_engine);
            }

			void save(serializable_base::os& file) const override {
                file(CEREAL_NVP(_seed));
			}

			void load(serializable_base::is& file) override {
                file(_seed);
			}

            void draw(std::string const& label) const override {
                _seed.draw("Seed");
            }
	};
}

REGISTER_SYSTEM("Random", dls::math::systems::random);
