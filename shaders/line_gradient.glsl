#version 330

out vec4 finalColor;

uniform vec2 pointA;
uniform vec2 pointB;
uniform vec4 colorA;
uniform vec4 colorB;

void main()
{
	if (pointA == pointB) {
		finalColor = colorA;
		return;
	}
	vec2 direction = pointB - pointA;
	vec2 difference = gl_FragCoord.xy - pointA;

	float projected = dot(direction, difference) / dot(direction, direction);;
	finalColor = mix(colorA, colorB, projected);
}
