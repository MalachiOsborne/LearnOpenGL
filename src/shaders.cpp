#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "functions.h"
#include <cstddef>
#include <iostream>

void vertex_shaders()
{

    const char* vertex_shader_source = "version 460 core\n"
                                       "layout (location = 0) in vec3 a_pos;\n"
                                       "void main()\n"
                                       "{\n"
                                       "    gl_Position = vec4(a_pos.x, a_pos.y, a_pos.z, 1.0f)\n"
                                       "}\0";
    //NDC, normalized device coordinates 
    float vertices[]
    {
        -0.2f,  0.0f, 0.0f,
         0.0f,  0.8f, 0.0f,
         0.3f, -0.4f, 0.0f

    };

    //VBO is vertex buffer object
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

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
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infolog << std::endl;
    }
}

void fragment_shaders()
{
   const char*  fragment_shader_source = "vertex 460 core\n"
                                         "out vec4 frag_color;\n"
                                         "void main()\n"
                                         "{\n"
                                         "  frag_color = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
                                         "}\0";

    unsigned int fragment_shader;
    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
    glCompileShader(fragment_shader);
}

void shader_program()
{
    
}
