#include "Graphics.h"
#include <iostream>

// Include the headers for your chosen graphics library
#ifdef USE_OPENGL
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#elif USE_DIRECTX
#include <d3d11.h>
#elif USE_SDL
#include <SDL.h>
#endif

Graphics::Graphics() : window(nullptr), context(nullptr) {
    clearColor[0] = 0.0f; // Red
    clearColor[1] = 0.0f; // Green
    clearColor[2] = 0.0f; // Blue
    clearColor[3] = 1.0f; // Alpha
}

Graphics::~Graphics() {
    Shutdown();
}

bool Graphics::Initialize(int windowWidth, int windowHeight, const std::string& windowTitle) {
    // Initialize the graphics library and create a window
#ifdef USE_OPENGL
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return false;
    }

    window = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(static_cast<GLFWwindow*>(window));
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW!" << std::endl;
        return false;
    }
#elif USE_DIRECTX
    // DirectX initialization code here
#elif USE_SDL
    // SDL initialization code here
#endif

    std::cout << "Graphics initialized successfully!" << std::endl;
    return true;
}

void Graphics::Shutdown() {
    // Clean up resources
#ifdef USE_OPENGL
    if (window) {
        glfwDestroyWindow(static_cast<GLFWwindow*>(window));
        window = nullptr;
    }
    glfwTerminate();
#elif USE_DIRECTX
    // DirectX cleanup code here
#elif USE_SDL
    // SDL cleanup code here
#endif
}

void Graphics::ClearScreen(float r, float g, float b, float a) {
    // Clear the screen with the specified color
#ifdef USE_OPENGL
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
#elif USE_DIRECTX
    // DirectX clear screen code here
#elif USE_SDL
    // SDL clear screen code here
#endif
}

void Graphics::Render() {
    // Perform rendering operations
    // (e.g., draw objects, apply shaders, etc.)
}

void Graphics::Present() {
    // Swap buffers to display the rendered frame
#ifdef USE_OPENGL
    glfwSwapBuffers(static_cast<GLFWwindow*>(window));
#elif USE_DIRECTX
    // DirectX present code here
#elif USE_SDL
    // SDL present code here
#endif
}

void Graphics::SetViewport(int x, int y, int width, int height) {
    // Set the viewport
#ifdef USE_OPENGL
    glViewport(x, y, width, height);
#elif USE_DIRECTX
    // DirectX viewport code here
#elif USE_SDL
    // SDL viewport code here
#endif
}

void Graphics::SetClearColor(float r, float g, float b, float a) {
    // Set the default clear color
    clearColor[0] = r;
    clearColor[1] = g;
    clearColor[2] = b;
    clearColor[3] = a;
}