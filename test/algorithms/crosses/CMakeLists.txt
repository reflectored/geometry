# Boost.Geometry
# Copyright (c) 2024 Barend Gehrels, Amsterdam, the Netherlands.
# Use, modification and distribution is subject to the Boost Software License,
# Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)

# Create a static library for test instantiations
add_library(geometry_test_instantiations STATIC
    geometry_test_instantiations.cpp
)
# Add a dependency to Boost.Geometry
target_link_libraries(geometry_test_instantiations
PRIVATE
  Boost::geometry)

# For unit tests, add a dependency to the unit test framework (in header only mode)
target_link_libraries(geometry_test_instantiations
PRIVATE
  Boost::included_unit_test_framework)

# Include the main Geometry test folder and the current folder
target_include_directories(geometry_test_instantiations
PRIVATE
  "${PROJECT_SOURCE_DIR}/test"
  "${PROJECT_SOURCE_DIR}/index/test"
  .)
# Link the static library to the test executables
foreach(item IN ITEMS
    crosses
    crosses_gc
    crosses_sph
  )
  boost_geometry_add_unit_test("algorithms" ${item})
  target_link_libraries(boost_geometry_algorithms_${item} PRIVATE geometry_test_instantiations)
  # target_compile_options(boost_geometry_algorithms_${item} PRIVATE -ftime-trace)
endforeach()
