#version 330

out vec4 finalColor;

uniform vec2 pointA;
uniform vec2 pointB;
uniform vec4 colorA;
uniform vec4 colorB;

void main()
{
	vec2 direction = pointB - pointA;
	vec2 difference = gl_FragCoord.xy - pointA;

	float projected = dot(direction, difference) / length(direction);

	float progress = projected / length(direction);
	finalColor = mix(colorA, colorB, progress);
}
