#version 330

out vec4 finalColor;

uniform vec2 pointA;
uniform vec2 pointB;
uniform vec4 colorA;
uniform vec4 colorB;

uniform float inner_thick;
uniform float outer_thick;

const float alpha = 0.45;

float cross(vec2 a, vec2 b)
{
	return a.x * b.y - a.y * b.x;
}

void main()
{
	if (all(equal(pointA, pointB))) {
		finalColor = colorA;
		return;
	}
	vec2 direction = pointB - pointA;
	vec2 difference = gl_FragCoord.xy - pointA;

	float projected = dot(direction, difference) / dot(direction, direction);;
	finalColor = mix(colorA, colorB, projected);


	float d = abs(cross(direction, difference)) / length(direction);

	bool inner = false;
	float progress = (d - inner_thick) / (outer_thick - inner_thick);
	if (progress <= 0.0) {
		inner = true;
	}
	progress = clamp(progress, 0.0, 1.0);
	float mapped = pow(1.0 - progress, 4.0);

	if (!inner) {
		finalColor.a = mapped * alpha;
	}
}
