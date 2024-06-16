#pragma once

#include <random>
#include <limits>
#include "interfaces/engine_system.hpp"

namespace dls {
	class random : public engine_system {
        protected:
            void initialize() override;
            void update(tick&) override;
            void shutdown() override;

        public:
            template <typename T>
            static T next() {
                std::uniform_int_distribution<T> distr(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
                return distr(_engine);
            }

            template <>
            static float next() {
                std::uniform_real_distribution<float> distr(std::numeric_limits<float>::min(), std::numeric_limits<float>::max());
                return distr(_engine);
            }

            template <>
            static double next() {
                std::uniform_real_distribution<double> distr(std::numeric_limits<double>::min(), std::numeric_limits<double>::max());
                return distr(_engine);
            }

            template <typename T>
            static T next_range(T min, T max) {
                std::uniform_int_distribution<T> distr(min, max);
                return distr(_engine);
            }

            template <>
            static float next_range(float min, float max) {
                std::uniform_real_distribution<float> distr(min, max);
                return distr(_engine);
            }

            template <>
            static double next_range(double min, double max) {
                std::uniform_real_distribution<double> distr(min, max);
                return distr(_engine);
            }

        private:
            static inline std::default_random_engine _engine;
	};
}
