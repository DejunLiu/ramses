#version 100

uniform highp vec4 color;
void main(void)
{
    gl_FragColor = color + vec4(0.1);
}
