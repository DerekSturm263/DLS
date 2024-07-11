#pragma once

#include "interfaces/serializable.hpp"
#include "interfaces/function.hpp"

namespace dls::core::functions {
	class set_mod_enabled : public interfaces::function {
		public:
			void invoke(game::tick& tick, std::vector<void*> const& inputs, std::vector<void*>& outputs) const override {

			}

			void draw(std::string const& label) const override {

			}
	};
}

namespace dls::core::types {
	class module_base : public interfaces::serializable<module_base> {
		protected:
			std::vector<std::unique_ptr<interfaces::function>> _all_functions;

			template <typename TFunc>
			friend class event;
			
		public:
			module_base() : _all_functions() { }
			~module_base() { }
	};

	template <typename... TFuncTypes>
	class module : public module_base {
		public:
			using base_type = typename module<TFuncTypes...>;

		protected:
			module() {
				std::unique_ptr<interfaces::function> ptr = std::make_unique<functions::set_mod_enabled>(functions::set_mod_enabled{});
				_all_functions.push_back(std::move(ptr));

				([&] {
					std::unique_ptr<interfaces::function> ptr = std::make_unique<TFuncTypes>(TFuncTypes{});

					_all_functions.push_back(std::move(ptr));
				} (), ...);
			}
	};
}

#define REGISTER_MODULE(name, derived)														\
	CEREAL_REGISTER_TYPE_WITH_NAME(derived, name);											\
	CEREAL_REGISTER_POLYMORPHIC_RELATION(derived::base_type, derived);						\
	CEREAL_REGISTER_POLYMORPHIC_RELATION(dls::core::types::module_base, derived::base_type);
