#pragma once

#include <memory>

namespace dls {
    template <typename T>
    class singleton {
        private:
            singleton() { }

        protected:
            static std::unique_ptr<T> _instance;

        public:
            static T* instance() {
                if (!_instance)
                    _instance = std::unique_ptr<T>();

                return _instance.get();
            }
    };
}
