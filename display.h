#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "mouse.h"

class Display {
    public:
        Display(int width, int height, const std::string& title);

        void Clear(float r, float g, float b, float a);
        void Update();
        void ListenInput(Mouse *mouse);
        bool IsClosed();

        virtual ~Display();
    private:
        GLFWwindow* window;
        bool isClosed;
};

#endif // DISPLAY_H
