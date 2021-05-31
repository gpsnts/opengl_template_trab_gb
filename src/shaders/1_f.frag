// Custom (Mixa duas imagens)
#version 450 core
in vec2 TexCoords;
out vec4 color;
uniform sampler2D image1;
uniform sampler2D image2;
uniform vec3 iColor;
void main()
{
  color = texture(image1, TexCoords);
  color = color + vec4(iColor, 0.0);
  vec4 mask = texture(image2, TexCoords);
  color = mix(color, mask, 0.3);
  color = vec4(color.rgb, 1.0);
}