#pragma once

#include <optional>
#include <type_traits>
#include "interfaces/serializable.hpp"
#include "wrappers/wrappers.hpp"
#include "../properties/property_group.hpp"
#include "../events/event.hpp"
#include "module.hpp"

namespace dls::core::types {
	class entity : public interfaces::serializable<entity> {
		private:
			wrappers::val<std::string> _name;
			wrappers::val<std::unordered_map<size_t, wrappers::val<std::unique_ptr<module_base>>>> _modules;
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
				/*([&] {
					std::unique_ptr<module_base> ptr = std::make_unique<Ts>(std::move(modules));
					wrappers::val<std::unique_ptr<module_base>> val{ std::move(ptr) };

					_modules.value().push_back(std::move(val));
				} (), ...);*/
			}

			std::string const& name() const {
				return _name.value();
			}

			std::string& name() {
				return _name.value();
			}

			template <typename T>
			std::optional<T const*> get_module() const {
				/*size_t index = typeid(T).hash_code();

				if (_modules.value().contains(index))
					return std::optional<T const*>{ _modules.value().at(index).value().get() };
				*/
				return std::optional<T const*>();
			}

			template <typename T>
			std::optional<T*> get_module() {
				/*size_t index = typeid(T).hash_code();

				if (_modules.value().contains(index))
					return std::optional<T*>{ _modules.value().at(index).value().get() };
				*/
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
				//file(CEREAL_NVP(_modules));
				file(CEREAL_NVP(_properties));
				file(CEREAL_NVP(_on_start));
				file(CEREAL_NVP(_on_enable));
				file(CEREAL_NVP(_on_tick));
				file(CEREAL_NVP(_on_disable));
				file(CEREAL_NVP(_on_exit));
			}

			void load(is& file) override {
				file(_name);
				//file(_modules);
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
