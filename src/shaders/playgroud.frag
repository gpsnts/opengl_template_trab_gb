// GLSL-Canvas -- VSCode

#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;

float circle_shape(vec2 position, float radius)
{
  return step(
		radius,
		length(position - vec2(0.5))
	);
}

void main()
{
  vec2 position = gl_FragCoord.xy / u_resolution;
  vec4 color = vec4(1.0, 0.0, 2.0, 1.0);
  float circle = circle_shape(position, 0.2);
  color = vec4(circle);
  gl_FragColor = color;
}