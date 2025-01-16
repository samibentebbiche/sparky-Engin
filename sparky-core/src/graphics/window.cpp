
#include "window.h"

namespace sparky {  namespace graphics {

	void window_resize(GLFWwindow* window, int width, int hight);


	Window::Window(const char* title,int width, int hight)
	{
		m_Title = title;
		m_Hight = hight;
		m_Width = width;
		if (!Init()) glfwTerminate();
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::update()
	{ 
		GLenum error = glGetError();
		if (errno != GL_NO_ERROR)
		{
			std::cout << "OpenGlError : " << error << std::endl;
		}
		glfwPollEvents();
		glfwSwapBuffers(m_Window);

	}

	bool Window::closed() 
	{
		if (glfwWindowShouldClose(m_Window)) {
			m_Closed = true;
			return true;
		}
		else return false;
	}

	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	}
	bool Window::Init()
	{

		if (!glfwInit()) 
		{
			std::cout << "GLFW filed to Initialize !" << std::endl;
			return false;
		}
		m_Window = glfwCreateWindow(m_Width, m_Hight, m_Title , NULL, NULL);


		if (!m_Window)
		{
			std::cout << "Failed to cread a Window ! " << std::endl;
			glfwTerminate();
			return false;
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(m_Window);


		// Initialiser GLAD
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			std::cerr << "Erreur : Impossible d'initialiser GLAD\n";
			glfwTerminate();
			return false;
		}

		std::cout << " OpenGL Version :" << glGetString(GL_VERSION) << std::endl;
		glfwSetWindowSizeCallback(m_Window, window_resize);
		return true;
	}
	void Window::getMoisePos(float &x, float &y)
	{
		using namespace input;
		std::pair<float, float> xy;
		xy = InputManager::getInstance().getMousePosition();
		x = xy.first;
		y = xy.second;
		
	}


	void window_resize(GLFWwindow* window, int width, int hight) 
	{
		glViewport(0, 0, width, hight);
	}
	

	void Window::processInput()
	{
		using namespace input;
		InputManager::getInstance().processInput(m_Window);
		
		//if (InputManager::getInstance().isKeyPressed(GLFW_KEY_ENTER))
		//{
		//	std::cout<< " Enter !" << std::endl;
		//}
		//std::pair<double, double> xy = InputManager::getInstance().getMousePosition();
		//if (InputManager::getInstance().isMouseButtonPressed(GLFW_MOUSE_BUTTON_1)) 
		//{
		//	std::cout << " left click ! " << std::endl;
		//}
		//std::cout << xy.first << " , " << xy.second << std::endl;
	}



}}