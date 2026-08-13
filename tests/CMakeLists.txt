file(GLOB_RECURSE CSTL_TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

foreach(TEST_SOURCE ${CSTL_TEST_SOURCES})
  get_filename_component(name ${TEST_SOURCE} NAME_WE)
  add_executable(${name} ${TEST_SOURCE})
  target_link_libraries(${name} PRIVATE ${PROJECT_NAME})

  if(MSVC)
    target_compile_options(${PROJECT_NAME} PUBLIC /W4 /Zi)
  elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wpedantic -g)
  endif()

  add_test(NAME ${name} COMMAND ${name})
endforeach()
