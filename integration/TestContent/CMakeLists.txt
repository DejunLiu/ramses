#  -------------------------------------------------------------------------
#  Copyright (C) 2018 BMW Car IT GmbH
#  -------------------------------------------------------------------------
#  This Source Code Form is subject to the terms of the Mozilla Public
#  License, v. 2.0. If a copy of the MPL was not distributed with this
#  file, You can obtain one at https://mozilla.org/MPL/2.0/.
#  -------------------------------------------------------------------------

ACME_MODULE(
    #==========================================================================
    # general module information
    #==========================================================================
    NAME                    TestContent
    TYPE                    STATIC_LIBRARY
    ENABLE_INSTALL          OFF

    #==========================================================================
    # files of this module
    #==========================================================================
    FILES_PRIVATE_HEADER    include/TestEffects/*.h
                            include/TestScenes/*.h
                            include/TestScenes/TextFake/*.h
                            include/*.h
    FILES_SOURCE            src/*.cpp
                            src/TextFake/*.cpp
    FILES_RESOURCE          res/*

    #==========================================================================
    # dependencies
    #==========================================================================
    DEPENDENCIES            ramses-client-api
                            ramses-client
                            ramses-framework
                            ramses-renderer-lib
                            ramses-text-api
                            ramses-text
)
