#pragma once

#include <optional>
#include <type_traits>
#include "interfaces/serializable.hpp"
#include "interfaces/function.hpp"
#include "wrappers/wrappers.hpp"

namespace dls::core::functions {
	class set_mod_enabled : public interfaces::function<std::tuple<>, std::tuple<>> {
		public:
			void invoke(game::game& game, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};
}

namespace dls::core::types {
	class module_base : public interfaces::serializable<module_base> {
		protected:
			std::unordered_map<size_t, wrappers::val<std::unique_ptr<interfaces::function_base>>> _functions;

			template <typename TFunc>
			friend class event;
			
		public:
			module_base() : _functions() { }
			module_base(module_base&& rhs) : _functions(std::move(rhs._functions)) { }

			template <typename T>
			std::optional<T const*> get_function() const {
				size_t index = typeid(T).hash_code();

				if (_functions.contains(index))
					return static_cast<T const*>(functions.at(index).value().get());
				
				return std::nullopt;
			}
	};

	template <typename... TFuncTypes>
	class module : public module_base {
		public:
			using base_type = typename module<TFuncTypes...>;

		protected:
			module() {
				std::unique_ptr<interfaces::function_base> ptr = std::make_unique<functions::set_mod_enabled>(functions::set_mod_enabled{});
				_functions.insert(std::make_pair(typeid(functions::set_mod_enabled).hash_code(), std::move(ptr)));

				([&] {
					std::unique_ptr<interfaces::function_base> ptr = std::make_unique<TFuncTypes>(TFuncTypes{});

					_functions.insert(std::make_pair(typeid(TFuncTypes).hash_code(), std::move(ptr)));
				} (), ...);
			}
	};
}

#define REGISTER_MODULE(name, derived)														\
	CEREAL_REGISTER_TYPE_WITH_NAME(derived, name);											\
	CEREAL_REGISTER_POLYMORPHIC_RELATION(derived::base_type, derived);						\
	CEREAL_REGISTER_POLYMORPHIC_RELATION(dls::core::types::module_base, derived::base_type);
