#version 330

in vec2 fragTexCoord;
in vec4 fragColor;
out vec4 finalColor;

void main()
{
	finalColor.rgb = fragColor.rgb;
	finalColor.a = 1.0 - distance(fragTexCoord, vec2(0.5, 0.5));
}
