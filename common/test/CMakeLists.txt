cmake_minimum_required(VERSION 2.8)

project(module_common_test)

find_package (Threads)

# factory test
add_executable(factory_test factory_test.cc)
target_link_libraries(factory_test gtest gtest_main ${CMAKE_THREAD_LIBS_INIT} glog)
add_test(NAME factory_test COMMAND factory_test)

# singleton test
add_executable(singleton_test singleton_test.cc)
target_link_libraries(singleton_test gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME singleton_test COMMAND singleton_test)

# thread_safe_queue test
add_executable(thread_safe_queue_test thread_safe_queue_test.cc)
target_link_libraries(thread_safe_queue_test gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME thread_safe_queue_test COMMAND thread_safe_queue_test)

# for_each test
add_executable(for_each_test for_each_test.cc)
target_link_libraries(for_each_test gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME for_each_test COMMAND for_each_test)

# concurrent_object_pool test
add_executable(concurrent_object_pool_test concurrent_object_pool_test.cc)
target_link_libraries(concurrent_object_pool_test gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME concurrent_object_pool_test COMMAND concurrent_object_pool_test)