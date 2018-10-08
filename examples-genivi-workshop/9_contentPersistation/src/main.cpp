//  -------------------------------------------------------------------------
//  Copyright (C) 2018 BMW Car IT GmbH
//  -------------------------------------------------------------------------
//  This Source Code Form is subject to the terms of the Mozilla Public
//  License, v. 2.0. If a copy of the MPL was not distributed with this
//  file, You can obtain one at https://mozilla.org/MPL/2.0/.
//  -------------------------------------------------------------------------

#include <thread>

#include "ramses-client.h"
#include "ramses-utils.h"

int main(int argc, char* argv[])
{
    ramses::RamsesFramework framework(argc, argv);

    ramses::RamsesClient client("workshop example client", framework);

    framework.connect();

    ramses::ResourceFileDescriptionSet resourceFiles;
    ramses::ResourceFileDescription resourceFile("res/export_exampleScene_resources.ramres");
    resourceFiles.add(resourceFile);
    ramses::Scene* scene = client.loadSceneFromFile("res/export_exampleScene.ramscene", resourceFiles);

    //[optional part]
    ramses::SceneObjectIterator iterScene(*scene, ramses::ERamsesObjectType_AnimationSystem);
    ramses::AnimationSystemRealTime* animationSystem = ramses::RamsesUtils::TryConvert<ramses::AnimationSystemRealTime>(*iterScene.getNext());

    ramses::AnimationSequence* sequence = ramses::RamsesUtils::TryConvert<ramses::AnimationSequence>(*animationSystem->findObjectByName("NewAnimationSequence"));
    ramses::AnimationSystemObjectIterator iterAnimationSystem(*animationSystem, ramses::ERamsesObjectType_Animation);

    ramses::Animation* animation = ramses::RamsesUtils::TryConvert<ramses::Animation>(*iterAnimationSystem.getNext());
    sequence->setAnimationLooping(*animation);

    auto now = std::chrono::system_clock::now();
    sequence->startAt(std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count());

    scene->flush(ramses::ESceneFlushMode_SynchronizedWithResources);
    scene->publish();

    while (1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    scene->unpublish();
    client.destroy(*scene);
    framework.disconnect();
}
