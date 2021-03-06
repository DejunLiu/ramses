//  -------------------------------------------------------------------------
//  Copyright (C) 2016 BMW Car IT GmbH
//  -------------------------------------------------------------------------
//  This Source Code Form is subject to the terms of the Mozilla Public
//  License, v. 2.0. If a copy of the MPL was not distributed with this
//  file, You can obtain one at https://mozilla.org/MPL/2.0/.
//  -------------------------------------------------------------------------

#ifndef RAMSES_SCENEAPI_SCENEVERSIONTAG_H
#define RAMSES_SCENEAPI_SCENEVERSIONTAG_H

#include "PlatformAbstraction/PlatformTypes.h"
#include "Common/StronglyTypedValue.h"

namespace ramses_internal
{
    struct SceneVersionTagTag {};
    typedef StronglyTypedValue<UInt64, static_cast<UInt64>(-1), SceneVersionTagTag> SceneVersionTag;

    static const SceneVersionTag InvalidSceneVersionTag(SceneVersionTag::DefaultValue());
}

#endif
