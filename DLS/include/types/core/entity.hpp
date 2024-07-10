#pragma once

#include <optional>
#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"
#include "../properties/property_group.hpp"
#include "../events/event.hpp"
#include "module.hpp"

namespace dls::core::types {
	class entity : public interfaces::serializable<entity> {
		private:
			wrappers::val<std::string> _name;
			wrappers::val<std::vector<wrappers::val<std::shared_ptr<module_base>>>> _modules;
			wrappers::val<properties::types::property_group> _properties;

			wrappers::type<events::types::event<void()>> _on_start;
			wrappers::type<events::types::event<void()>> _on_enable;
			wrappers::type<events::types::event<void()>> _on_tick;
			wrappers::type<events::types::event<void()>> _on_disable;
			wrappers::type<events::types::event<void()>> _on_exit;

		public:
			entity() : _modules() { }

			template <typename... Ts>
			entity(std::string const&& name, Ts const&& ... modules) : _name(name), _modules() {
				([&] {
					_modules.value().push_back(wrappers::val<std::shared_ptr<module_base>>(std::make_shared<Ts>(modules)));
				} (), ...);
			}

			// TODO: Move into tick.cpp
			template <typename T>
			std::optional<T const*> get_module() const {
				for (int i = 0; i < _modules.value().size(); ++i) {
					wrappers::val<std::shared_ptr<module_base>> base = _modules.value()[i];
					module_base* base_get = base.value().get();

					T* ret = dynamic_cast<T*>(base_get);

					if (ret)
						return std::optional<T const*>(ret);
				}

				return std::optional<T const*>();
			}

			// TODO: Move into tick.cpp
			template <typename T>
			std::optional<T*> get_module() {
				for (int i = 0; i < _modules.value().size(); ++i) {
					wrappers::val<std::shared_ptr<module_base>> base = _modules.value()[i];
					module_base* base_get = base.value().get();

					T* ret = dynamic_cast<T*>(base_get);

					if (ret)
						return std::optional<T*>(ret);
				}

				return std::optional<T*>();
			}

			properties::types::property_group const& properties() const {
				return _properties.value();
			}

			properties::types::property_group& properties() {
				return _properties.value();
			}

			void save(os& file) const override {
				file(CEREAL_NVP(_name));
				file(CEREAL_NVP(_modules));
				file(CEREAL_NVP(_properties));
				file(CEREAL_NVP(_on_start));
				file(CEREAL_NVP(_on_enable));
				file(CEREAL_NVP(_on_tick));
				file(CEREAL_NVP(_on_disable));
				file(CEREAL_NVP(_on_exit));
			}

			void load(is& file) override {
				file(_name);
				file(_modules);
				file(_properties);
				file(_on_start);
				file(_on_enable);
				file(_on_tick);
				file(_on_disable);
				file(_on_exit);
			}

			void draw(std::string const& label) const override {
				_name.draw("Name");
				_modules.draw("Modules");
				_properties.draw("Properties");
				_on_start.draw("On Start");
				_on_enable.draw("On Enable");
				_on_tick.draw("On Tick");
				_on_disable.draw("On Disable");
				_on_exit.draw("On Exit");
			}
	};
}
