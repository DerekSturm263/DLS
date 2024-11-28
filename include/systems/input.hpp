#pragma once

#include "types/core/system.hpp"
#include "types/core/scene.hpp"
#include "interfaces/systems/on_scene_load.hpp"
#include "interfaces/systems/on_scene_unload.hpp"

struct GLFWwindow;

namespace dls::input::systems {
    class input : public core::types::system<>, public core::interfaces::i_on_scene_load, public core::interfaces::i_on_scene_unload {
        private:
            static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
                
            }

            static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
        
            }
    
            static void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {

            }
    
            static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {

            }
        
        public:
            void on_scene_load(miscellaneous::game& game, core::wrappers::ref<core::types::scene> const& scene) override {
                /*glfwSetKeyCallback(scene.value().window().glfw_window(), key_callback);
                glfwSetMouseButtonCallback(scene.value().window().glfw_window(), mouse_button_callback);
                glfwSetCursorPosCallback(scene.value().window().glfw_window(), cursor_pos_callback);
                glfwSetScrollCallback(scene.value().window().glfw_window(), scroll_callback);*/
            }

            void on_scene_unload(miscellaneous::game& game, core::wrappers::ref<core::types::scene> const& scene) override {
                /*glfwSetKeyCallback(scene.value().window().glfw_window(), nullptr);
                glfwSetMouseButtonCallback(scene.value().window().glfw_window(), nullptr);
                glfwSetCursorPosCallback(scene.value().window().glfw_window(), nullptr);
                glfwSetScrollCallback(scene.value().window().glfw_window(), nullptr);*/
            }

            void save(core::interfaces::serializable_base::os& file) const override {

            }

            void load(core::interfaces::serializable_base::is& file) override {

            }
    };
}

REGISTER_SYSTEM("Input", dls::input::systems::input);
