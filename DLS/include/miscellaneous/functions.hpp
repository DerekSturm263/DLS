#pragma once

#include "interfaces/function.hpp"

namespace dls::math::functions {
	class compare : public core::interfaces::function<std::tuple<>, std::tuple<>> {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};
	
	class math : public core::interfaces::function<std::tuple<>, std::tuple<>> {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};

	class branch : public core::interfaces::function<std::tuple<>, std::tuple<>> {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};

	class wait : public core::interfaces::function<std::tuple<>, std::tuple<>> {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};

	class iterate : public core::interfaces::function<std::tuple<>, std::tuple<>> {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};

	class end : public core::interfaces::function<std::tuple<>, std::tuple<>> {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};

	class skip : public core::interfaces::function<std::tuple<>, std::tuple<>> {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};
}