#version 330

out vec4 finalColor;

uniform vec2 pointA;
uniform vec2 pointB;
uniform vec4 colorA;
uniform vec4 colorB;

void main()
{
	finalColor = colorA;
}
