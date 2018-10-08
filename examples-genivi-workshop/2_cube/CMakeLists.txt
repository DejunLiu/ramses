#  -------------------------------------------------------------------------
#  Copyright (C) 2018 BMW Car IT GmbH
#  -------------------------------------------------------------------------
#  This Source Code Form is subject to the terms of the Mozilla Public
#  License, v. 2.0. If a copy of the MPL was not distributed with this
#  file, You can obtain one at https://mozilla.org/MPL/2.0/.
#  -------------------------------------------------------------------------

ADD_EXECUTABLE(2_cube "src/main.cpp")
TARGET_LINK_LIBRARIES(2_cube ${RAMSES_LIBS} ${additional_target_link_libraries})
TARGET_INCLUDE_DIRECTORIES(2_cube PRIVATE ${RAMSES_INCLUDE_DIRS})

FILE(GLOB res_files RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/" "res/*" )
FOREACH(res_file ${res_files})
	CONFIGURE_FILE("${CMAKE_CURRENT_SOURCE_DIR}/${res_file}" "${CMAKE_CURRENT_BINARY_DIR}/${res_file}" COPYONLY)
ENDFOREACH(res_file)
