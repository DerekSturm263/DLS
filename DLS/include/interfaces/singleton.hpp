#pragma once

namespace dls {
    template <typename T>
    class singleton {
        protected:
            static T& _instance;

            singleton(T const& derived) {
                _instance = derived;
            }

        public:
            static T& instance() {
                return _instance;
            }
    };
}
