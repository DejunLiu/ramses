#version 100

uniform highp mat4 mvpMatrix;

attribute vec3 a_position;

void main()
{
    gl_Position = mvpMatrix * vec4(a_position, 1.0);
}
