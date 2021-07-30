#include "display.h"
#define GLEW_STATIC
#include "GL/glew.h"
#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0,0,width, height);
}

Display::Display(int width, int height, const std::string& title){

	    if( glfwInit() != GLFW_TRUE) {
        std::cout << "Failed to initialize glfw" << std::endl;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1600, 600, "test", nullptr, nullptr);
    if(window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    // Set to disable fps
    glfwSwapInterval(0);

    GLenum err = glewInit();
    if(err != GLEW_OK) {
        std::cout << "Failed to initialize glew: " <<glewGetErrorString(err) << std::endl;
    }

    glViewport(0,0, 1600, 600); // x,y -> lower left corner
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // callback for resizing window


    isClosed = false;
}

Display::~Display(){
    glfwTerminate();
}

void Display::Clear(float r, float g, float b, float a){
    glClearColor(r,g,b,a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Display::ListenInput(Mouse *mouse){
    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
        mouse->moveMouse(0,-0.05);
    }

    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
        mouse->moveMouse(0,0.05);
    }

    if(glfwGetKey(window, GLFW_KEY_KP_ADD) == GLFW_PRESS){
        mouse->zoomMouse();
    }

    if(glfwGetKey(window, GLFW_KEY_KP_SUBTRACT) == GLFW_PRESS){
        mouse->unzoomMouse();
    }

    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        isClosed = true;
    }

    if(glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS){
        mouse->moveMouse(-0.05, 0);
    }

    if(glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS){
        mouse->moveMouse(0.05, 0);
    }

}

bool Display::IsClosed(){
    return isClosed;
}

void Display::Update(){
        glfwSwapBuffers(window);
        glfwPollEvents();
}



