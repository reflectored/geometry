# Boost.Geometry
# Copyright (c) 2024 Barend Gehrels, Amsterdam, the Netherlands.
# Use, modification and distribution is subject to the Boost Software License,
# Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)

add_compile_options(-ftime-trace)
add_library(test_crosses_instantiation STATIC instantiate_test_crosses.cpp)
target_include_directories(test_crosses_instantiation
PUBLIC
  "${PROJECT_SOURCE_DIR}/test"
  "${PROJECT_SOURCE_DIR}/index/test"
  .)
foreach(item IN ITEMS
    crosses
    crosses_gc
    crosses_sph
  )
  boost_geometry_add_unit_test("algorithms" ${item} DEPENDS test_crosses_instantiation)
  target_link_libraries(boost_geometry_algorithms_${item} PRIVATE test_crosses_instantiation)
endforeach()
