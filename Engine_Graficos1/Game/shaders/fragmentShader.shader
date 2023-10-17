#version 330 core

out vec4 FragColor;

in vec4 ourColor;
in vec2 v_SpriteCoord;

uniform sampler2D u_Sprite;

void main()
{
   FragColor = texture(u_Sprite, v_SpriteCoord) * ourColor;
}