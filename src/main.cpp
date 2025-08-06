#include <cstdlib> //C standard lib, handy
#include "glad/glad.h"
#include "shaders.h"
#include "GLFW/glfw3.h"
#include "functions.h"
#include <iostream>
#include <math.h>

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

    //resize callback function call

//    int num_attributes;
//    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &num_attributes);
//    std::cout << "Maximum num of vertex attributes supported: " << num_attributes << std::endl;
    shader my_shader("src/vertex_shader.vs", "src/fragment_shader.fs");
    //NDC, normalized device coordinates 
    float vertices[]
    {
        //position              //color
        -0.6f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,
         0.0f,  0.7f, 0.0f,     0.0f, 1.0f, 0.0f, 
         0.6f, -0.5f, 0.0f,     0.0f, 0.0f, 1.0f

    };

    //VAO is vertex array object
    //used to store VBO layout without having to rebind all the time
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    //VBO is vertex buffer object
    //this is used for one attribute, i.e. color, position, orientation, etc...
    unsigned int VBO;
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //position traversal
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0); 
    glEnableVertexAttribArray(0);

    //don't change pipeline state often
    glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
    glBindVertexArray(VAO);

    //color traversal
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


    //render loop
    while(!glfwWindowShouldClose(window))
    {
        process_input(window);

        //background color
        glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        //render triangle
        my_shader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    //self explanatory
    glfwTerminate();
    return 0;
}

void process_input(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

//GLFWwindow* doens't need a name because we're not using it, we can put "window" in there but the lsp will complain that its an unused variable
void framebuffer_size_callback(GLFWwindow*, int width, int height)
{
    glViewport(0, 0, width, height);
}
