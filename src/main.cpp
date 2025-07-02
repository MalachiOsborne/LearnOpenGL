#include <cstdlib> //C standard lib, handy
#include "glad/glad.h"
#include "GLFW/glfw3.h"

//tells OpenGL we resized
void framebuffer_size_callback(GLFWwindow*, int width, int height)
{
    glViewport(0, 0, width, height);
}

void process_input(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main()
{
    //window instantiation
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //window object
    GLFWwindow* window = glfwCreateWindow(800, 600, "success" , NULL, NULL);
    if (window == NULL)
    {
        glfwTerminate();
        return EXIT_FAILURE;
    }

    //tell OpenGL this is where you're working, slave
    glfwMakeContextCurrent(window);

    //loads OpenGL function pointers (bridges GLFW and OpenGL)
    if(!gladLoadGL())
        return EXIT_FAILURE;

    //OpenGL playground
//    glViewport(0, 0, 800, 600);

    //resize callback function call
//   glfwSetFramebufferSizeCallback(window, &framebuffer_size_callback);

    //render loop
    while(!glfwWindowShouldClose(window))
    {
        process_input(window);

        glClearColor(0.5f, 0.1f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //self explanatory
    glfwTerminate();

    return 0;
}
