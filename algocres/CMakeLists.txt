# One CMakeLists.txt per project (lib)

add_library(
	algocres
)
set_target_properties(algocres PROPERTIES LINKER_LANGUAGE CXX)
target_sources(
	algocres

	PRIVATE
	# add header files for ide integration
	include/algocres/array_stack.hxx
	include/algocres/stackable.hxx
	include/algocres/util.hxx
)

target_include_directories(
	algocres

	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>

	PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/src"
)

# can use INTERFACE_INCLUDE_DIRECTORIES populated by target_include_directories
# better to use FILES, and manually add files, so cmake can properly reload
# install(DIRECTORY include/algocres/ DESTINATION include/algocres/)

# gtest
enable_testing()
find_package(GTest REQUIRED)
add_executable(algocres_tests)
target_sources(
	algocres_tests

	PRIVATE
	test/stack_tests.cxx
)
target_link_libraries(algocres_tests GTest::GTest GTest::Main algocres)

# require when working with threads
find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)
add_executable(
	main
	main.cpp)
#SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread")
target_link_libraries(main algocres Threads::Threads)