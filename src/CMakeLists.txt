include_directories(${PROJECT_SOURCE_DIR}/libcr)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_executable(producer producer.c)
add_executable(consumer consumer.c)
add_executable(producer_call_consumer producer_call_consumer.c)
add_executable(toy1 toy1.c)
add_executable(toy2 toy2.c)
add_executable(toy3 toy3.c)
add_executable(toy4 toy4.c)
add_executable(switch_error switch_error.c)
add_executable(toy5 toy5.c)

add_executable(using_eventloop using_eventloop.c)
target_link_libraries(using_eventloop libcr)

add_executable(asyn_load_file asyn_load_file.c)
target_link_libraries(asyn_load_file libcr)

