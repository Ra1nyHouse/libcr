set(LIB_SRC eventloop.c)
add_library(libcr ${LIB_SRC})
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set_target_properties(libcr PROPERTIES OUTPUT_NAME "cr")

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/include)
configure_file(cr_simple.h ${PROJECT_BINARY_DIR}/include)
configure_file(cr_context.h ${PROJECT_BINARY_DIR}/include)
configure_file(eventloop.h ${PROJECT_BINARY_DIR}/include)