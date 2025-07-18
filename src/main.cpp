#include <cstdlib> //C standard lib, handy
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "functions.h"
#include <iostream>
#include <math.h>

//GLSL stuff
static const char* vertex_shader_source =    "#version 460 core\n"
                                      "layout (location = 0) in vec3 a_pos;\n"
                                      "layout (location = 1) in vec3 a_color;\n"
                                      "out vec3 our_color;\n"
                                      "void main()\n"
                                      "{\n"
<<<<<<< HEAD
=======
<<<<<<< HEAD
                                      "    gl_Position = vec4(a_pos.x, a_pos.y, a_pos.z, 1.0f);\n"
                                      "}";
=======
>>>>>>> c2d3d11abd8d178c2fc65e773f37fb5adc4bcc7b
                                      "    gl_Position = vec4(a_pos, 1.0f);\n"
                                      "    our_color = a_color;\n"
                                      "}\0";
>>>>>>> 25a7bc1 (add own shader class and make colourful triangle)

static const char*  fragment_shader_source = "#version 460 core\n"
                                      "out vec4 frag_color;\n"
                                      "in vec3 our_color;\n"
                                      "void main()\n"
                                      "{\n"
<<<<<<< HEAD
=======
<<<<<<< HEAD
                                      "  frag_color = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
                                      "}";
=======
>>>>>>> c2d3d11abd8d178c2fc65e773f37fb5adc4bcc7b
                                      "  frag_color = vec4(our_color, 1.0f);\n"
                                      "}\0";
>>>>>>> 25a7bc1 (add own shader class and make colourful triangle)
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
    glViewport(0, 0, 1040, 800);

    //resize callback function call
    glfwSetFramebufferSizeCallback(window, &framebuffer_size_callback);

//    int num_attributes;
//    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &num_attributes);
//    std::cout << "Maximum num of vertex attributes supported: " << num_attributes << std::endl;

    //NDC, normalized device coordinates 
    float vertices[]
    {
        //position              //color
        -0.6f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,
         0.0f,  0.7f, 0.0f,     0.0f, 1.0f, 0.0f, 
         0.6f, -0.5f, 0.0f,     0.0f, 0.0f, 1.0f

    };


    //first step of the graphics pipeline

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

    //second step of the graphics pipeline

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


    //third step of the graphics pipeline

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

<<<<<<< HEAD
=======
<<<<<<< HEAD
    //don't change pipeline state often
    glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
    glBindVertexArray(VAO);
    glUseProgram(shader_program);
=======
>>>>>>> c2d3d11abd8d178c2fc65e773f37fb5adc4bcc7b
    //color traversal
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


<<<<<<< HEAD
=======
>>>>>>> 25a7bc1 (add own shader class and make colourful triangle)
>>>>>>> c2d3d11abd8d178c2fc65e773f37fb5adc4bcc7b
    //render loop
    while(!glfwWindowShouldClose(window))
    {
        process_input(window);

        //background color
        glClear(GL_COLOR_BUFFER_BIT);

<<<<<<< HEAD
=======
<<<<<<< HEAD
        //triangle
=======
>>>>>>> c2d3d11abd8d178c2fc65e773f37fb5adc4bcc7b
        glUseProgram(shader_program);
        
        //color changing
        float time_value = glfwGetTime();
        float green_value = (sin(time_value)/2.0f)+0.5f;
        int vertex_color_location = glGetUniformLocation(shader_program, "our_color");
        glUniform4f(vertex_color_location, 0.0f, green_value, 0.0f, 1.0f);

        //render triangle
        glBindVertexArray(VAO);
>>>>>>> 25a7bc1 (add own shader class and make colourful triangle)
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
