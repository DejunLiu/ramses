#version 100

uniform sampler2D textureSampler;

varying lowp vec2 v_texcoord;

void main(void)
{
    gl_FragColor = texture2D(textureSampler, v_texcoord);
}
