#include "types/core/window.hpp"

//#include <glad/glad.h>
//#include <GLFW/glfw3.h>

namespace dls::core::types {
    void window::create() const {
		/*if (!glfwInit())
    		return;
        
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);

        _glfw_window = glfwCreateWindow(_dimensions.value().x, _dimensions.value().y, _title.value().value().c_str(), nullptr, nullptr);
        if (!_glfw_window) {
            glfwTerminate();
	        return;
        }

        glfwMakeContextCurrent(_glfw_window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            glfwTerminate();
	        return;
        }

		glViewport(0, 0, _dimensions.value().x, _dimensions.value().y);
        glClearColor(_background_color.value().r(), _background_color.value().g(), _background_color.value().b(), _background_color.value().a());

		glfwSetFramebufferSizeCallback(_glfw_window, framebuffer_size_callback);*/

        _active_windows.insert(_glfw_window);
	}

	void window::destroy() const {
        _active_windows.erase(_glfw_window);

        //glfwDestroyWindow(_glfw_window);
    }
}
