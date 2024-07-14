#pragma once

#include <random>
#include <limits>
#include "types/core/system.hpp"
#include "wrappers/wrappers.hpp"
#include "miscellaneous/game.hpp"

namespace dls::math::functions {
    template <typename T>
    class next;

    template <typename T>
    class next_range;
}

namespace dls::math::systems {
	class random : public core::types::system<functions::next<int>, functions::next_range<int>> {
        private:
            core::wrappers::type<unsigned int> _seed;
            std::default_random_engine _engine;

        public:
            void initialize(game::game& game) override {
                _engine = std::default_random_engine{ _seed.value() };
            }

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

namespace dls::math::functions {
    template <typename T>
    class next : public core::interfaces::function<T()> {
        public:
            T invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<> const& func_args) const override {
                auto random = game.project().get_system<systems::random>();

                if (random.has_value()) {
                    return random.value()->next<T>();
                }

                return T{};
            }
    };

    template <typename T>
    class next_range : public core::interfaces::function<T(events::types::param_ref<T>, events::types::param_ref<T>)> {
        public:
            T invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<events::types::param_ref<T>, events::types::param_ref<T>> const& func_args) const override {
                auto random = game.project().get_system<systems::random>();

                if (random.has_value()) {
                    return random.value()->next_range(std::get<0>(func_args).value(event_args), std::get<1>(func_args).value(event_args));
                }

                return T{};
            }
    };
}

REGISTER_SYSTEM("Random", dls::math::systems::random);
