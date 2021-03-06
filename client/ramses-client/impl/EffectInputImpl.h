//  -------------------------------------------------------------------------
//  Copyright (C) 2014 BMW Car IT GmbH
//  -------------------------------------------------------------------------
//  This Source Code Form is subject to the terms of the Mozilla Public
//  License, v. 2.0. If a copy of the MPL was not distributed with this
//  file, You can obtain one at https://mozilla.org/MPL/2.0/.
//  -------------------------------------------------------------------------

#ifndef RAMSES_EFFECTINPUTIMPL_H
#define RAMSES_EFFECTINPUTIMPL_H

// client api
#include "ramses-client-api/EffectInputDataType.h"
#include "ramses-client-api/EffectInputSemantic.h"

// internal
#include "StatusObjectImpl.h"

// framework
#include "SceneAPI/ResourceContentHash.h"
#include "SceneAPI/EDataType.h"
#include "SceneAPI/EFixedSemantics.h"
#include "Collections/String.h"
#include "SerializationContext.h"

namespace ramses
{
    class EffectInputImpl final : public StatusObjectImpl
    {
    public:
        EffectInputImpl();
        virtual ~EffectInputImpl();

        void initialize(
            const ramses_internal::ResourceContentHash& effectHash,
            const ramses_internal::String&              name,
            ramses_internal::EDataType                  dataType,
            ramses_internal::EFixedSemantics            semantics,
            uint32_t                                    elementCount,
            uint32_t                                    index);

        bool                                 isValid() const;

        ramses_internal::ResourceContentHash getEffectHash() const;
        const ramses_internal::String&       getName() const;
        ramses_internal::EDataType           getDataType() const;
        ramses_internal::EFixedSemantics     getSemantics() const;
        uint32_t                             getElementCount() const;
        uint32_t                             getInputIndex() const;

        EEffectInputDataType                 getUniformInputDataType() const;
        EEffectInputDataType                 getAttributeInputDataType() const;
        EEffectUniformSemantic               getUniformSemantics() const;
        EEffectAttributeSemantic             getAttributeSemantics() const;

        status_t                             serialize(ramses_internal::IOutputStream& outStream) const;
        status_t                             deserialize(ramses_internal::IInputStream& inStream);

        bool                                 operator==(const EffectInputImpl& other)const;
        bool                                 operator!=(const EffectInputImpl& other)const;

    private:
        ramses_internal::ResourceContentHash m_effectHash;
        ramses_internal::String              m_name;
        ramses_internal::EDataType           m_dataType;
        ramses_internal::EFixedSemantics     m_semantics;
        uint32_t                             m_elementCount;
        uint32_t                             m_inputIndex;
    };
}

#endif
