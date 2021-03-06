#version 410
layout(location = 0) in vec3 a_position;
layout(location = 1) in vec2 a_texCoord;
uniform mat4 projection;
uniform mat4 model;
out vec2 texCoord;
void main(void)
{
    texCoord = a_texCoord;
    gl_Position = projection * model * vec4(a_position, 1.0f);
}
