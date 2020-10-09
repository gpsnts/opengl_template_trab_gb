set(LIBS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)                                
                                                    
set(OpenGL_GL_PREFERENCE "GLVND")                                
find_package(OpenGL REQUIRED)                                         

if(NOT OPENGL_FOUND)                                      
  message(OpenGL needed!)                                            
endif(NOT OPENGL_FOUND)