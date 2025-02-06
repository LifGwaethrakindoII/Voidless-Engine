#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>

class Graphics {
public:
    // Constructor and Destructor
    Graphics();
    ~Graphics();

    // Initialization and Cleanup
    bool Initialize(int windowWidth, int windowHeight, const std::string& windowTitle);
    void Shutdown();

    // Rendering Functions
    void ClearScreen(float r, float g, float b, float a); // Clear the screen with a color
    void Render(); // Render the current frame
    void Present(); // Swap buffers to display the rendered frame

    // Utility Functions
    void SetViewport(int x, int y, int width, int height); // Set the viewport
    void SetClearColor(float r, float g, float b, float a); // Set the default clear color

private:
    // Private members for internal use
    void* window; // Pointer to the window (e.g., GLFWwindow, SDL_Window, etc.)
    void* context; // Graphics context (e.g., OpenGL context, DirectX device, etc.)
    float clearColor[4]; // Default clear color (RGBA)
};

#endif // GRAPHICS_H