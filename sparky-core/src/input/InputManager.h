#pragma once


#include <GLFW/glfw3.h>
#include <unordered_map>
namespace sparky {  namespace input {


	class InputManager
	{

	private:

		InputManager() = default;
		std::unordered_map<int, bool> keyState;

		std::unordered_map<int, bool> mouseButtonState;
		double lastMouseX = 0.0, lastMouseY = 0.0;
		double deltaX = 0.0, deltaY = 0.0;


	public:

		static InputManager& getInstance();

		void processInput(GLFWwindow* window);

		bool isKeyPressed(int key) const;

		bool isMouseButtonPressed(int button) const;
		std::pair<double, double> getMousePosition() const;
		std::pair<double, double> getMouseDelta() const;
		void setCursorMode(GLFWwindow* window, int mode);

	private:

		void updateMousePosition(GLFWwindow* window);



	};

}}