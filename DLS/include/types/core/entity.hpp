#pragma once

#include <optional>
#include <type_traits>
#include "types/miscellaneous/text.hpp"
#include "types/properties/property_group.hpp"
#include "types/collections/map.hpp"
#include "module.hpp"

namespace dls::core::types {
	class entity : public interfaces::serializable<entity> {
		private:
			wrappers::val<miscellaneous::types::text> _name;
			wrappers::val<collections::types::map<size_t, wrappers::val<std::unique_ptr<module_base>>>> _modules;
			wrappers::val<properties::types::property_group> _properties;

		public:
			entity() : _name(), _modules(), _properties() { }

			template <typename... Ts>
			entity(miscellaneous::types::text const& name, Ts&& ... modules) : _name(name), _modules(sizeof...(modules)), _properties() {
				([&] {
					std::unique_ptr<module_base> ptr = std::make_unique<Ts>(std::move(modules));
					wrappers::val<std::unique_ptr<module_base>> val{ std::move(ptr) };

					_modules.value().value().insert(std::make_pair(typeid(Ts).hash_code(), std::move(val)));
				} (), ...);
			}

			template <typename... Ts>
			entity(miscellaneous::types::text&& name, Ts&& ... modules) : _name(std::move(name)), _modules(sizeof...(modules)), _properties() {
				([&] {
					std::unique_ptr<module_base> ptr = std::make_unique<Ts>(std::move(modules));
					wrappers::val<std::unique_ptr<module_base>> val{ std::move(ptr) };

					_modules.value().value().insert(std::make_pair(typeid(Ts).hash_code(), std::move(val)));
				} (), ...);
			}

			miscellaneous::types::text const& name() const {
				return _name.value();
			}

			miscellaneous::types::text& name() {
				return _name.value();
			}

			template <typename T>
			std::optional<T const*> get_module() const {
				size_t index = typeid(T).hash_code();

				if (_modules.value().value().contains(index))
					return static_cast<T const*>(_modules.value().value().at(index).value().get());

				return std::nullopt;
			}

			template <typename T>
			std::optional<T*> get_module() {
				size_t index = typeid(T).hash_code();

				if (_modules.value().value().contains(index))
					return static_cast<T*>(_modules.value().value().at(index).value().get());

				return std::nullopt;
			}

			template <typename... Ts>
			std::optional<std::tuple<Ts const* ...>> get_modules() const {
				using ret_type = std::optional<std::tuple<Ts const* ...>>;
				ret_type ret = std::tuple<Ts const* ...>{};

				([&] {
					// Try to grab the current module from the entity.
					std::optional<Ts const*> module = get_module<Ts>();

					// If the module couldn't be grabbed, return an empty optional.
					if (!module.has_value()) {
						ret = std::nullopt;
						return;
					}

					// If the module could be grabbed, set the value in the return tuple to it.
					std::get<Ts const*>(ret.value()) = module.value();
				} (), ...);

				// If all modules were grabbed, return the modules as a tuple.
				return ret;
			}

			template <typename... Ts>
			std::optional<std::tuple<Ts* ...>> get_modules() {
				using ret_type = std::optional<std::tuple<Ts* ...>>;
				ret_type ret = std::tuple<Ts* ...>{};

				([&] {
					// Try to grab the current module from the entity.
					std::optional<Ts*> module = get_module<Ts>();

					// If the module couldn't be grabbed, return an empty optional.
					if (!module.has_value()) {
						ret = std::nullopt;
						return;
					}

					// If the module could be grabbed, set the value in the return tuple to it.
					std::get<Ts*>(ret.value()) = module.value();
				} (), ...);

				// If all modules were grabbed, return the modules as a tuple.
				return ret;
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
			}

			void load(is& file) override {
				file(_name);
				file(_modules);
				file(_properties);
			}
	};
}
