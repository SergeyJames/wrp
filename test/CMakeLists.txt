add_executable(
	unit_tests
	test_wrappers.cpp
	test_utilities.cpp
	test_numeric.cpp
	main.cpp
	)

target_link_libraries(unit_tests gtest_main)

add_test(NAME unit COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests)
