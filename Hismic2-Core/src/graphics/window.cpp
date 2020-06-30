#include "window.h"
namespace hismic {
	namespace graphics {

		void window_resize(GLFWwindow* window, int width, int height);
		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

		Window::Window(const char* title, int width, int height) {
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (!init()) {
				glfwTerminate();
			}
			for (int i = 0; i < MAX_KEYS; i++) {
				m_Keys[i] = false;

			}
			for (int i = 0; i < MAX_BUTTONS; i++) {
				m_MouseButtons[i] = false;

			}
		}
		Window::~Window() {
			glfwTerminate();
		}
		
		bool Window::init() {
			if (!glfwInit()) {
				m_Log.PrintLog("Failed to intialize GLFW", 3);
				return false;
			}
			m_Window = glfwCreateWindow(m_Width,m_Height,m_Title,NULL,NULL);
			if (!m_Window) {
				glfwTerminate();
				m_Log.PrintLog("Failed to create GLFW window", 3);
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window,this);
			glfwSetWindowSizeCallback(m_Window ,window_resize);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);
			
			if (glewInit() != GLEW_OK) {
				m_Log.PrintLog("Failed to initialize GLEW",3);
				return false;
			}
			printf_s("[RENDER]OpenGL Version: %s \n", glGetString(GL_VERSION));
			printf_s("[RENDER]OpenGL Vendor: %s \n", glGetString(GL_VENDOR));
			printf_s("[RENDER]OpenGL Renderer: %s \n", glGetString(GL_RENDERER));
			return true;

		}
		bool Window::isKeyPressed(unsigned int keycode) const {
			Utils::Logger k_log;
			if (keycode >= MAX_KEYS){
				k_log.PrintLog("keycode is larger than MAX_KEYS (1024)",2);
				return false;
			}
			return m_Keys[keycode];
		}
		bool Window::isMouseButtonPressed(unsigned int button) const  {
			Utils::Logger k_log;
			if (button >= MAX_BUTTONS) {
				k_log.PrintLog("buttons is larger than MAX_BUTTONS (32)", 2);
				return false;
			}
			return m_MouseButtons[button];
		}
		void Window::getMousePosition(double& x, double& y) const
		{
			x = mx;
			y = my;
		}
		void Window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}
		void Window::update() {
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}
		bool Window::closed() const {
			return glfwWindowShouldClose(m_Window) == 1;
		}
		
		void window_resize(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);

		}
		void key_callback(GLFWwindow* window,int key,int scancode,int action,int mods) {
			Window * win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Keys[key] = action != GLFW_RELEASE;
		}
		
		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = action != GLFW_RELEASE;
		}
		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mx = xpos;
			win->my = ypos;
		}
	}
}
