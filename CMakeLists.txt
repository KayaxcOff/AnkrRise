cmake_minimum_required(VERSION 3.10)

project(AnkrRise)

# MSVC edit and continue
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT 
      "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(SFML_DIR "C:/software/Cpp/libraries/SFML/SFML-2.6.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS system window graphics audio network REQUIRED)

# --------------------
# BOX2D
# --------------------
set(BOX2D_DIR "C:/software/Cpp/libraries/Box2D/box2d-2.4.1")

add_executable(AnkrRise main.cpp "MindEngine2D/Loop/Main/game.hpp" "MindEngine2D/Loop/Main/game.cpp")

# Include paths
target_include_directories(AnkrRise PRIVATE
    "${BOX2D_DIR}/include"
)

# Link libraries
target_link_libraries(AnkrRise PRIVATE
    sfml-system sfml-window sfml-graphics sfml-audio sfml-network
    "${BOX2D_DIR}/build/bin/$<IF:$<CONFIG:Debug>,Debug,Release>/box2d.lib"
)

set_property(TARGET AnkrRise PROPERTY CXX_STANDARD 20)

# --------------------
# SFML DLL copy (Windows)
# --------------------
if (WIN32)
    add_custom_command(TARGET AnkrRise POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${SFML_DIR}/../../../bin"
        $<TARGET_FILE_DIR:AnkrRise>
    )
endif()