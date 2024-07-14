#pragma once

#include "interfaces/function.hpp"

namespace dls::math::functions {
	template <typename T, typename U>
	class compare : public core::interfaces::function<bool(T, U)> {
		public:
			bool invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<T, U> const& args) const override {

			}
	};

	template <typename Result, typename T, typename U>
	class math : public core::interfaces::function<Result(T, U)> {
		public:
			Result invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<T, U> const& args) const override {

			}
	};

	class branch : public core::interfaces::function<void()> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<> const& args) const override {
			
			}
	};

	class wait : public core::interfaces::function<void()> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<> const& args) const override {

			}
	};

	class iterate : public core::interfaces::function<void()> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<> const& args) const override {

			}
	};

	class end : public core::interfaces::function<void()> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<> const& args) const override {

			}
	};

	class skip : public core::interfaces::function<void()> {
		public:
			void invoke(game::game& game, std::vector<void*> const& event_args, std::tuple<> const& args) const override {

			}
	};
}