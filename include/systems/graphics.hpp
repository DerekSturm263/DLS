#pragma once

#include "types/core/system.hpp"
#include "modules/transform.hpp"
#include "modules/appearance.hpp"
#include "interfaces/systems/on_entity_spawn.hpp"
#include "interfaces/systems/on_entity_despawn.hpp"

namespace dls::graphics::functions {
	template <typename Decimal, glm::length_t Size>
	class render {};
}

namespace dls::graphics::systems {
	template <typename Decimal, glm::length_t Size>
	class graphics : public core::types::system<functions::render<Decimal, Size>>, public core::interfaces::i_on_entity_spawn, public core::interfaces::i_on_entity_despawn {
		private:
            class agent {
                private:
                    core::interfaces::unique_base::guid_type _guid;
                    math::modules::transform<Decimal, Size> const& _transform;
                    modules::appearance const& _appearance;
                    math::types::matrix<float, 4, 4>* _camera;
                    math::types::matrix<float, 4, 4>* _projection;
                    unsigned int* _uv_offset;

                public:
                    agent(core::interfaces::unique_base::guid_type guid, math::modules::transform<Decimal, Size> const& transform, modules::appearance const& appearance) : _guid(guid), _transform(transform), _appearance(appearance) { }

                    void draw() const {
                        //Vector2Int uv_offset = _material->_texture->get_uvs(*_uv_offset);

                        math::types::vector<float, 2> uv_offset{};
                        math::types::vector<float, 2> dimensions{};

                        _appearance.material().value().use(*_camera, *_projection, _transform.transformation().value().get_matrix(), uv_offset, dimensions);
                    }

                    bool operator>(agent const& rhs) const {
                        return _guid > rhs._guid;
                    }

                    bool operator<(agent const& rhs) const {
                        return _guid < rhs._guid;
                    }
            };

			std::set<agent> _agents;

        public:
			void update() override {
                for (auto& agent : _agents) {
                    agent.draw();
                }

                //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
            }

            void on_entity_spawn(miscellaneous::game& game, core::wrappers::ref<core::types::entity> const& entity) override {
                auto modules = entity.value().get_modules<math::modules::transform<Decimal, Size>, modules::appearance>();
        
                if (modules.has_value()) {
                    auto transform = std::get<math::modules::transform<Decimal, Size> const*>(modules.value());
                    auto appearance = std::get<modules::appearance const*>(modules.value());

                    agent agent{ entity.id(), *transform, *appearance };
                    _agents.insert(std::move(agent));
                }
            }

            void on_entity_despawn(miscellaneous::game& game, core::wrappers::ref<core::types::entity> const& entity) override {
                auto modules = entity.value().get_modules<math::modules::transform<Decimal, Size>, modules::appearance>();
        
                if (modules.has_value()) {
                    auto transform = std::get<math::modules::transform<Decimal, Size> const*>(modules.value());
                    auto appearance = std::get<modules::appearance const*>(modules.value());
                    
                    agent agent{ entity.id(), *transform, *appearance };
                    _agents.erase(agent);
                }
            }

            void save(core::interfaces::serializable_base::os& file) const override {

            }

            void load(core::interfaces::serializable_base::is& file) override {

            }
	};

	using graphics_t = graphics<float, 3>;
}

REGISTER_SYSTEM("Graphics", dls::graphics::systems::graphics_t);
