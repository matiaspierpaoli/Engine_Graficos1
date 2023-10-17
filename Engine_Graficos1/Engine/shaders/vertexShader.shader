#version 330 core
layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 texCoord;   
out vec2 v_SpriteCoord; 
out vec4 ourColor;

uniform mat4 mvp;

void main()
{
    gl_Position = mvp * position;
    ourColor = color;
    v_SpriteCoord = texCoord;   // set v_SpriteCoord to the input uv we got from the vertex data
}