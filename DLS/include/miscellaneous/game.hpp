#pragma once

#include "types/core/project.hpp"
#include "system_manager.hpp"
#include "tick.hpp"

namespace dls::game {
	class game {
		private:
			core::wrappers::asset<core::types::project> _project;
			systems::system_manager _system_manager;
			mutable tick _tick;

		public:
			game() : _project(), _system_manager(), _tick() { }
			game(core::wrappers::asset<core::types::project> const& prj) : _project(prj), _system_manager(systems::system_manager{ prj.value().systems() }), _tick() { }
			game(core::wrappers::asset<core::types::project>&& prj) : _project(std::move(prj)), _system_manager(systems::system_manager{ prj.value().systems() }), _tick() { }

			core::types::project const& project() const {
				return _project.value();
			}

			core::types::project& project() {
				return _project.value();
			}

			systems::system_manager const& system_manager() const{
				return _system_manager;
			}

			systems::system_manager& system_manager() {
				return _system_manager;
			}

			tick& tick() const {
				return _tick;
			}
	};
}
