#version 330

out vec4 finalColor;

uniform vec2 center;
uniform float inner_thick;
uniform float outer_thick;
uniform vec4 color;

const float alpha = 0.45;

void main()
{
	finalColor = color;
	vec2 center = 

	float d = distance(gl_FragCoord.xy, center);
	float progress = clamp((d - inner_thick) / (outer_thick - inner_thick), 0.0, 1.0);

	// Cubic-beizer ease out
	float mapped = pow(1.0 - progress, 4);

	finalColor.a = mapped * alpha;
}

