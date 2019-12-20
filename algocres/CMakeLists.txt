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

# gtest
enable_testing()
#find_package(GTest REQUIRED)
add_executable(algocres_tests)
target_sources(
	algocres_tests

	PRIVATE
	test/stack_tests.cxx
)
target_link_libraries(algocres_tests gtest_main algocres)
