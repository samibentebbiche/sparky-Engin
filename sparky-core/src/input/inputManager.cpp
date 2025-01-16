
#include "InputManager.h"

namespace sparky { namespace input {



	InputManager& InputManager::getInstance()
	{
		static InputManager instance;
		return instance;
	}

	void InputManager::processInput(GLFWwindow* window)
	{
		// Parcours des touches à surveiller
		for (int key = GLFW_KEY_SPACE; key <= GLFW_KEY_LAST; key++)
		{
			keyState[key] = glfwGetKey(window, key) == GLFW_PRESS;
		}

		// Parcours des boutons de souris
		for (int button = GLFW_MOUSE_BUTTON_1; button <= GLFW_MOUSE_BUTTON_LAST; ++button) {
			mouseButtonState[button] = glfwGetMouseButton(window, button) == GLFW_PRESS;
		}

		updateMousePosition(window);
	}

	bool InputManager::isKeyPressed(int key) const
	{
		auto it = keyState.find(key);

		return it != keyState.end() && it->second;
	}
	bool InputManager::isMouseButtonPressed(int button) const {
		auto it = mouseButtonState.find(button);
		return it != mouseButtonState.end() && it->second;
	}

	std::pair<double, double> InputManager::getMousePosition() const {
		return { lastMouseX, lastMouseY };
	}

	std::pair<double, double> InputManager::getMouseDelta() const {
		return { deltaX, deltaY };
	}

	void InputManager::updateMousePosition(GLFWwindow* window) {
		double currentX, currentY;
		glfwGetCursorPos(window, &currentX, &currentY);

		deltaX = currentX - lastMouseX;
		deltaY = currentY - lastMouseY;

		lastMouseX = currentX;
		lastMouseY = currentY;
	}

	void InputManager::setCursorMode(GLFWwindow* window, int mode) {
		glfwSetInputMode(window, GLFW_CURSOR, mode);
	}
	
}}