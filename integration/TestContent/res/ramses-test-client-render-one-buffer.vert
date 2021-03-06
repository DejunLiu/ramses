//  -------------------------------------------------------------------------
//  Copyright (C) 2018 BMW Car IT GmbH
//  -------------------------------------------------------------------------
//  This Source Code Form is subject to the terms of the Mozilla Public
//  License, v. 2.0. If a copy of the MPL was not distributed with this
//  file, You can obtain one at https://mozilla.org/MPL/2.0/.
//  -------------------------------------------------------------------------

#version 300 es
precision highp float;

in vec3 a_position;

uniform highp mat4 mvpMatrix;

void main()
{
    gl_Position = mvpMatrix * vec4(a_position, 1.0);
}
