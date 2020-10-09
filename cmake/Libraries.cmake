# Libraries location
set(LIBS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)                                

# OpenGL (Must be OS installed -- 4.6+ required)
set(OpenGL_GL_PREFERENCE "GLVND")                                
find_package(OpenGL REQUIRED)                                         
if(NOT OPENGL_FOUND)                                      
  message(OpenGL needed!)                                            
endif(NOT OPENGL_FOUND)

# Glad
add_library(glad ${LIBS_DIR}/glad/src/glad.c)
target_include_directories(glad PRIVATE ${LIBS_DIR}/glad/include)

# Includes directories
file(
  GLOB
  LIBS_INCLUDES
  ${LIBS_DIR}/glad/include
  ${OpenGL_INCLUDE_DIRS}
)

message("\nLibs...OK\n")