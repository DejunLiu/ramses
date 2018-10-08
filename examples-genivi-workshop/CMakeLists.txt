#  -------------------------------------------------------------------------
#  Copyright (C) 2018 BMW Car IT GmbH
#  -------------------------------------------------------------------------
#  This Source Code Form is subject to the terms of the Mozilla Public
#  License, v. 2.0. If a copy of the MPL was not distributed with this
#  file, You can obtain one at https://mozilla.org/MPL/2.0/.
#  -------------------------------------------------------------------------

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(examples-genivi-workshop)

OPTION(USE_RAMSES_STATIC_LIBS "Build using RAMSES static libs" TRUE)

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	SET(additional_target_link_libraries rt pthread)
	SET(RAMSES_LIB_SYSTEM LINUX)
ELSEIF(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
	SET(additional_target_link_libraries "")
	SET(RAMSES_LIB_SYSTEM WINDOWS)
ENDIF()


IF(${USE_RAMSES_STATIC_LIBS})
    FIND_PACKAGE(ramses-static-lib REQUIRED COMPONENTS ${RAMSES_LIB_SYSTEM})
    SET(RAMSES_LIBS ${ramses-static-lib_LIBRARIES})
    SET(RAMSES_INCLUDE_DIRS ${ramses-static-lib_INCLUDE_DIRS})
ELSE()
    FIND_PACKAGE(ramses-shared-lib REQUIRED COMPONENTS ${RAMSES_LIB_SYSTEM})
    SET(RAMSES_LIBS ${ramses-shared-lib_LIBRARIES})
    SET(RAMSES_INCLUDE_DIRS ${ramses-shared-lib_INCLUDE_DIRS})
ENDIF()

ADD_SUBDIRECTORY(1_helloWorld)
ADD_SUBDIRECTORY(2_cube)
ADD_SUBDIRECTORY(3_localAnimation)
ADD_SUBDIRECTORY(4_remoteAnimation)
ADD_SUBDIRECTORY(5_text)
ADD_SUBDIRECTORY(6_renderer)
ADD_SUBDIRECTORY(7_embeddedCompositing)
ADD_SUBDIRECTORY(8_dataLinking)
ADD_SUBDIRECTORY(9_contentPersistation)
