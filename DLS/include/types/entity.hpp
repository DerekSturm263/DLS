#pragma once

#include <optional>
#include "interfaces/serializable.hpp"
#include "module.hpp"
#include "event.hpp"
#include "type templates/type_templates.hpp"

namespace dls {
	class entity : public serializable<entity> {
		private:
			val<std::vector<val<std::shared_ptr<module_base>>>> _modules;
			val<property_group> _properties;

			type<event<void()>> _on_scene_load;
			type<event<void()>> _on_enable;
			type<event<void()>> _on_start;
			type<event<void()>> _on_tick;
			type<event<void()>> _on_exit;
			type<event<void()>> _on_disable;
			type<event<void()>> _on_scene_unload;

		public:
			entity() : _modules() { }

			template <typename... Ts>
			entity(Ts const&& ... modules) : _modules() {
				([&]{
					_modules.value().push_back(val<std::shared_ptr<module_base>>(std::make_shared<Ts>(modules)));
				} (), ...);
			}

			// TODO: Move into tick.cpp
			template <typename T>
			std::optional<T*> get_module() {
				for (int i = 0; i < _modules.value().size(); ++i) {
					val<std::shared_ptr<module_base>> base = _modules.value()[i];
					module_base* base_get = base.value().get();

					T* ret = dynamic_cast<T*>(base_get);

					if (ret)
						return std::optional<T*>(ret);
				}
				
				return std::optional<T*>();
			}

			val<property_group> const& properties() const {
				return _properties;
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_modules));
			}

			void load(is& file) override {
				file(_modules);
			}
	};
}
