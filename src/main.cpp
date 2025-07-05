#include <cstdlib> #include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "functions.h"
#include <iostream>

const char* vertex_shader_source =    "#version 460 core\n"
                                      "layout (location = 0) in vec3 a_pos;\n"
                                      "void main()\n"
                                      "{\n"
                                      "    gl_Position = vec4(a_pos.x, a_pos.y, a_pos.z, 1.0f);\n"
                                      "}";

const char*  fragment_shader_source = "#version 460 core\n"
                                      "out vec4 frag_color;\n"
                                      "void main()\n"
                                      "{\n"
                                      "  frag_color = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
                                      "}";
int main()
{
    
        glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GLFWwindow* window = glfwCreateWindow(800, 600, "success" , NULL, NULL);
    if (window == NULL)
    {
        glfwTerminate();
        return EXIT_FAILURE;
    }

        glfwMakeContextCurrent(window);

        if(!gladLoadGL())
        return EXIT_FAILURE;

        glViewport(0, 0, 800, 600);

        glfwSetFramebufferSizeCallback(window, &framebuffer_size_callback);

        float vertices[]
    {
        -0.2f,  0.0f, 0.0f,
         0.0f,  0.8f, 0.0f,
         0.3f, -0.4f, 0.0f

    };

    
    unsigned int vertex_shader;
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
    glCompileShader(vertex_shader);

    int success;
    char infolog[512];
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, NULL, infolog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infolog << std::endl;
    }

    
    unsigned int fragment_shader;
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);

    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(fragment_shader, 512, NULL, infolog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infolog << std::endl;
    }


    
    unsigned int shader_program;
    shader_program = glCreateProgram();

    glAttachShader(shader_program, vertex_shader);
    glAttachShader(shader_program, fragment_shader);
    glLinkProgram(shader_program);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shader_program, 512, NULL, infolog);
        std::cout << "ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n" << infolog << std::endl;
    }

            unsigned int VAO;
    glGenVertexArrays(1, &VAO);

            unsigned int VBO;
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); 
    glEnableVertexAttribArray(0);

        glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
    glBindVertexArray(VAO);
    glUseProgram(shader_program);
        while(!glfwWindowShouldClose(window))
    {
        process_input(window);

                glClear(GL_COLOR_BUFFER_BIT);

                glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
