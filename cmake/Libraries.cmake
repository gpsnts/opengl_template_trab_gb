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

# GLFW
add_subdirectory(${LIBS_DIR}/glfw EXCLUDE_FROM_ALL)

# GLM
add_subdirectory(${LIBS_DIR}/glm EXCLUDE_FROM_ALL)

# STB
include_directories(${LIBS_DIR}/stb)
link_directories(${LIBS_DIR}/stb)

target_link_libraries(${PROJECT_NAME} glad glfw glm)

file(
  GLOB
  LIBS_INCLUDES
  ${LIBS_DIR}/glad/include
  ${OpenGL_INCLUDE_DIRS}
)

message("\nLibs...OK\n")