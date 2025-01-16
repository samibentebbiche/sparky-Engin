#pragma once

#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "../input/InputManager.h"


namespace sparky {  namespace graphics {



	class Window {

	private:
		GLFWwindow* m_Window;
		const char* m_Title;
		int m_Width, m_Hight;
		bool m_Closed;


	public:
		Window(const char* title, int width, int hight);
		~Window();
		void update();
		bool closed();
		void clear() const;
		void processInput();
		inline int getWidth() const { return m_Width; }
		inline int getHight() const { return m_Hight; }
		void getMoisePos(float& x, float& y);
	private:
		bool Init();

			
	};


}}