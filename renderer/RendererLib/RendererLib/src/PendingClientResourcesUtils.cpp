//  -------------------------------------------------------------------------
//  Copyright (C) 2017 BMW Car IT GmbH
//  -------------------------------------------------------------------------
//  This Source Code Form is subject to the terms of the Mozilla Public
//  License, v. 2.0. If a copy of the MPL was not distributed with this
//  file, You can obtain one at https://mozilla.org/MPL/2.0/.
//  -------------------------------------------------------------------------

#include "RendererLib/PendingClientResourcesUtils.h"
#include "SceneUtils/ResourceChangeUtils.h"
#include "Common/Cpp11Macros.h"

namespace ramses_internal
{
    void PendingClientResourcesUtils::ConsolidateAddedResources(
        ResourceContentHashVector& needed,
        ResourceContentHashVector& unneeded,
        ResourceContentHashVector& newlyNeeded,
        const ResourceContentHashVector& addedResources)
    {
        assert(newlyNeeded.empty());

        needed.reserve(needed.size() + addedResources.size());
        newlyNeeded.reserve(addedResources.size());

        for (const auto& addedResource : addedResources)
        {
            const auto it = unneeded.find(addedResource);
            if (it == unneeded.end())
            {
                // add as needed resource only if not already unneeded
                assert(!needed.contains(addedResource));
                needed.push_back(addedResource);
                // resource is newly needed
                newlyNeeded.push_back(addedResource);
            }
            else
            {
                // ignore added resource which was unneeded before
                unneeded.erase(it);
            }
        }
    }

    void PendingClientResourcesUtils::ConsolidateRemovedResources(
        ResourceContentHashVector& needed,
        ResourceContentHashVector& unneeded,
        ResourceContentHashVector& newlyUnneededPreviouslyNeeded,
        const ResourceContentHashVector& removedResources)
    {
        unneeded.reserve(unneeded.size() + removedResources.size());

        for (const auto& removedResource : removedResources)
        {
            const auto it = needed.find(removedResource);
            if (it == needed.end())
            {
                // add as unneeded resource only if not already needed
                assert(!unneeded.contains(removedResource));
                unneeded.push_back(removedResource);
            }
            else
            {
                // removed resource which was needed before is not needed anymore
                needed.erase(it);
                // resource is newly unneeded but was previously needed
                newlyUnneededPreviouslyNeeded.push_back(removedResource);
            }
        }
    }

    void PendingClientResourcesUtils::ConsolidateNewlyNeededResources(
        ResourceContentHashVector& newlyNeeded,
        ResourceContentHashVector& pendingUnneeded)
    {
        ResourceContentHashVector consolidatedNewlyNeeded;
        consolidatedNewlyNeeded.reserve(newlyNeeded.size());

        for (const auto& res : newlyNeeded)
        {
            ResourceChangeUtils::ConsolidateResource(consolidatedNewlyNeeded, pendingUnneeded, res);
        }

        newlyNeeded = consolidatedNewlyNeeded;
    }

    void PendingClientResourcesUtils::ConsolidateNewlyUnneededResources(
        ResourceContentHashVector& pendingUnneeded,
        const ResourceContentHashVector& newlyUnneededPreviouslyNeeded)
    {
        for (const auto& res : newlyUnneededPreviouslyNeeded)
        {
            if (!pendingUnneeded.contains(res))
            {
                pendingUnneeded.push_back(res);
            }
        }
    }

    bool containSameElement(const ResourceContentHashVector& A, const ResourceContentHashVector& B)
    {
        for (const auto& res : A)
        {
            if (B.contains(res))
            {
                return true;
            }
        }

        return false;
    }

    void PendingClientResourcesUtils::ConsolidateNeededAndUnneededResources(
        ResourceContentHashVector& inUse,
        const ResourceContentHashVector& needed,
        const ResourceContentHashVector& unneeded)
    {
        assert(!containSameElement(needed, unneeded));
        assert(!containSameElement(needed, inUse));

        for (const auto& res : unneeded)
        {
            assert(!needed.contains(res));
            assert(inUse.contains(res));
            inUse.erase(inUse.find(res));
        }

        inUse.insert(inUse.end(), needed.begin(), needed.end());
    }
}
