#pragma once

#include "types/core/system.hpp"

namespace dls::core::functions {
	class load : public interfaces::function<std::tuple<>, std::tuple<>> {
		public:
			void invoke(game::game& game, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};

	class spawn : public interfaces::function<std::tuple<>, std::tuple<>> {
		public:
			void invoke(game::game& game, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};

	class despawn : public interfaces::function<std::tuple<>, std::tuple<>> {
		public:
			void invoke(game::game& game, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};
}

namespace dls::core::systems {
	class scene : public core::types::system<functions::load, functions::spawn, functions::despawn> {
		//private:
			//std::vector<wrappers::val<types::entity>> _entities;

		public:
			void save(os& file) const override {

			}

			void load(is& file) override {

			}

			void draw(std::string const& label) const override {

			}
	};
}

REGISTER_SYSTEM("Scene", dls::core::systems::scene);
