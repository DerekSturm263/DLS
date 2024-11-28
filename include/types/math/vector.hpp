#pragma once

#include <glm/vec2.hpp>
#include "interfaces/serializable.hpp"

namespace dls::math::types {
	template <typename T, glm::length_t Size>
	class vector : public core::interfaces::serializable<vector<T, Size>>, public glm::vec<Size, T, glm::packed_highp> {
		public:
			vector() : glm::vec<Size, T, glm::packed_highp>(0) { }
			
			vector(glm::vec<Size, T, glm::packed_highp> const& rhs) : glm::vec<Size, T, glm::packed_highp>(0) {
                std::memcpy(this, &rhs, sizeof(vector<T, Size>));
            }
			vector(glm::vec<Size, T, glm::packed_highp>&& rhs) : glm::vec<Size, T, glm::packed_highp>(0) {
                std::memmove(this, &rhs, sizeof(vector<T, Size>));
				rhs{};
            }

			vector(vector<T, Size> const& rhs) : glm::vec<Size, T, glm::packed_highp>(0) {
                std::memcpy(this, &rhs, sizeof(vector<T, Size>));
            }
			vector(vector<T, Size>&& rhs) : glm::vec<Size, T, glm::packed_highp>(0) {
                std::memmove(this, &rhs, sizeof(vector<T, Size>));
				rhs{};
            }

			vector(T scalar) : glm::vec<Size, T, glm::packed_highp>(scalar) { }

			vector<T, Size>& operator=(vector<T, Size> const& rhs) {
				std::memcpy(this, &rhs, sizeof(vector<T, Size>));
				
				return *this;
			}

			vector<T, Size>& operator=(vector<T, Size>&& rhs) {
				std::memmove(this, &values, sizeof(vector<T, Size>));
				values{};

				return *this;
			}

			void save(core::interfaces::serializable_base::os& file) const override {
				for (int i = 0; i < Size; ++i) {
					file((*this)[i]);
				}
			}

			void load(core::interfaces::serializable_base::is& file) override {
				for (int i = 0; i < Size; ++i) {
					file((*this)[i]);
				}
			}
	};
}
