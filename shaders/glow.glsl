#version 330

out vec4 finalColor;

uniform vec2 center;
uniform float inner_radius;
uniform float outer_radius;
uniform vec4 color;

#define PI 3.14159265359
const float alpha = 0.45;

void main()
{
	finalColor = color;

	float d = distance(gl_FragCoord.xy, center);
	float progress = clamp((d - inner_radius) / (outer_radius - inner_radius), 0.0, 1.0);

	// Linear
	//float mapped = 1.0 - progress;

	// Quadratic
	//float mapped = pow(1.0 - progress, 2);
	
	// Logarithmic
	//const float base = 5.0;
	//float mapped = 1.0 - log(base * progress) / log(base);

	// Cubic-beizer
	float mapped = pow(1.0 - progress, 4);

	// Sine
	//float mapped = 1.0 - sin((progress * PI) / 2.0);

	finalColor.a = mapped * alpha;
}
