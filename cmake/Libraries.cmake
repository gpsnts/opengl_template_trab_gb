# Libraries location
set(LIBS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)                                

# OpenGL (Must be OS installed -- 4.6+ required)
set(OpenGL_GL_PREFERENCE "GLVND")                                
find_package(OpenGL REQUIRED)                                         
if(NOT OPENGL_FOUND)                                      
  message(OpenGL needed!)                                            
endif(NOT OPENGL_FOUND)

# GLAD
add_library(glad ${LIBS_DIR}/glad/src/glad.c)
target_include_directories(glad PRIVATE ${LIBS_DIR}/glad/include)

# FreeType2
# set(FREETYPE_DIR        ${CMAKE_CURRENT_SOURCE_DIR}/third_party/freetype2)
set(FREETYPE_DIR ${LIBS_DIR}/freetype)
set(FREETYPE_LIBRARY freetype)
set(FREETYPE_LIBRARIES ${FREETYPE_LIBRARY})
set(FREETYPE_INCLUDE_DIRS ${FREETYPE_DIR}/include)
# add_subdirectory(${LIBS_DIR}/freetype)
include_directories(${FREETYPE_INCLUDE_DIRS})
link_directories(${FREETYPE_DIR})

# GLFW
add_subdirectory(${LIBS_DIR}/glfw)

# GLM
add_subdirectory(${LIBS_DIR}/glm)

# STB
include_directories(${LIBS_DIR}/stb)
link_directories(${LIBS_DIR}/stb)

target_link_libraries(${PROJECT_NAME} glad glfw glm ${FREETYPE_LIBRARIES})

file(
  GLOB
  LIBS_INCLUDES
  ${LIBS_DIR}/glad/include
	${FREETYPE_INCLUDE_DIRS}
  ${OpenGL_INCLUDE_DIRS}
)

message("\nLibs...OK\n")