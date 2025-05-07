## Request:
I want to explicitly instantiate all calls to test_geometry in a new source file, build it and link it to the crosses test.
- make test_geometry extern in crosses.cpp
- create a source file instantiate_test_crosses.cpp and inside it create:
 - aliases for all types used in crosses.cpp
 - a macro to instantiate test_geometry for both in and double

## Response:
Okay, I can help you with that. Here's how to modify `crosses.cpp` and create `instantiate_test_crosses.cpp` to explicitly instantiate the `test_geometry` function.

**1. Modify `crosses.cpp`:**

```cpp
// filepath: /Development/boost/libs/geometry/test/algorithms/crosses/crosses.cpp
// ...existing code...
#include "test_crosses.hpp"

extern template void test_geometry<bg::model::multi_point<bg::model::d2::point_xy<int> >, bg::model::linestring<bg::model::d2::point_xy<int> > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::multi_point<bg::model::d2::point_xy<int> >, bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<int> > > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::multi_point<bg::model::d2::point_xy<int> >, bg::model::polygon<bg::model::d2::point_xy<int> > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::multi_point<bg::model::d2::point_xy<int> >, bg::model::multi_polygon<bg::model::polygon<bg::model::d2::point_xy<int> > > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<int> >, bg::model::linestring<bg::model::d2::point_xy<int> > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<int> >, bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<int> > > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<int> > >, bg::model::linestring<bg::model::d2::point_xy<int> > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<int> > >, bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<int> > > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<int> >, bg::model::ring<bg::model::d2::point_xy<int> > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<int> >, bg::model::polygon<bg::model::d2::point_xy<int> > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<int> >, bg::model::multi_polygon<bg::model::polygon<bg::model::d2::point_xy<int> > > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<int> > >, bg::model::ring<bg::model::d2::point_xy<int> > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<int> > >, bg::model::polygon<bg::model::d2::point_xy<int> > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<int> > >, bg::model::multi_polygon<bg::model::polygon<bg::model::d2::point_xy<int> > > >(std::string const&, std::string const&, bool);

extern template void test_geometry<bg::model::multi_point<bg::model::d2::point_xy<double> >, bg::model::linestring<bg::model::d2::point_xy<double> > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::multi_point<bg::model::d2::point_xy<double> >, bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<double> > > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::multi_point<bg::model::d2::point_xy<double> >, bg::model::polygon<bg::model::d2::point_xy<double> > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::multi_point<bg::model::d2::point_xy<double> >, bg::model::multi_polygon<bg::model::polygon<bg::model::d2::point_xy<double> > > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<double> >, bg::model::linestring<bg::model::d2::point_xy<double> > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<double> >, bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<double> > > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<double> > >, bg::model::linestring<bg::model::d2::point_xy<double> > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<double> > >, bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<double> > > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<double> >, bg::model::ring<bg::model::d2::point_xy<double> > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<double> >, bg::model::polygon<bg::model::d2::point_xy<double> > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<double> >, bg::model::multi_polygon<bg::model::polygon<bg::model::d2::point_xy<double> > > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<double> > >, bg::model::ring<bg::model::d2::point_xy<double> > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<double> > >, bg::model::polygon<bg::model::d2::point_xy<double> > >(std::string const&, std::string const&, bool);
extern template void test_geometry<bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<double> > >, bg::model::multi_polygon<bg::model::polygon<bg::model::d2::point_xy<double> > > >(std::string const&, std::string const&, bool);

template <typename P>
void test_pl()
{
    typedef bg::model::multi_point<P> mpt;
    typedef bg::model::linestring<P> ls;
    typedef bg::model::multi_linestring<ls> mls;

    test_geometry<mpt, ls>("MULTIPOINT(1 0,1 1)", "LINESTRING(0 0,1 0,3 3)", true);
    test_geometry<mpt, ls>("MULTIPOINT(0 0,1 1)", "LINESTRING(0 0,1 0,3 3)", false);
    test_geometry<mpt, ls>("MULTIPOINT(0 0,1 1)", "LINESTRING(0 0,1 1,3 3)", false);

    test_geometry<mpt, mls>("MULTIPOINT(0 0,3 0)", "MULTILINESTRING((0 0,0 1,1 1),(1 1,1 0,0 0))", true);
    test_geometry<mpt, mls>("MULTIPOINT(0 0,1 1)", "MULTILINESTRING((0 0,0 1,1 1),(1 1,1 0,0 0))", false);
}

template <typename P>
void test_pa()
{
    typedef bg::model::multi_point<P> mpt;
    typedef bg::model::polygon<P> poly;
    typedef bg::model::multi_polygon<poly> mpoly;

    test_geometry<mpt, poly>("MULTIPOINT(1 1,6 6)", "POLYGON((0 0,0 5,5 5,5 0,0 0))", true);
    test_geometry<mpt, poly>("MULTIPOINT(0 0,6 6)", "POLYGON((0 0,0 5,5 5,5 0,0 0))", false);
    test_geometry<mpt, poly>("MULTIPOINT(0 0,1 1)", "POLYGON((0 0,0 5,5 5,5 0,0 0))", false);

    test_geometry<mpt, mpoly>("MULTIPOINT(0 0,1 1)", "MULTIPOLYGON(((0 0,0 5,5 5,5 0,0 0)),((5 5,5 9,9 9,9 5,5 5)))", false);
    test_geometry<mpt, mpoly>("MULTIPOINT(1 1,1 6)", "MULTIPOLYGON(((0 0,0 5,5 5,5 0,0 0)),((5 5,5 9,9 9,9 5,5 5)))", true);
}

template <typename P>
void test_ll()
{
    typedef bg::model::linestring<P> ls;
    typedef bg::model::multi_linestring<ls> mls;

    test_geometry<ls, ls>("LINESTRING(0 0,2 2,4 4)", "LINESTRING(0 1,2 1,3 1)", true);
    test_geometry<ls, ls>("LINESTRING(0 0,2 2)", "LINESTRING(0 1,2 1)", true);
    test_geometry<ls, ls>("LINESTRING(0 0,2 2,4 4)", "LINESTRING(0 1,1 1,2 2,3 2)", false);

    test_geometry<ls, mls>("LINESTRING(0 0,2 2,4 4)", "MULTILINESTRING((0 1,4 1),(0 2,4 2))", true);
    test_geometry<mls, ls>("MULTILINESTRING((0 1,4 1),(0 2,4 2))", "LINESTRING(0 0,2 2,4 4)", true);

    test_geometry<mls, mls>("MULTILINESTRING((0 0,2 2,4 4),(3 0,3 4))", "MULTILINESTRING((0 1,4 1),(0 2,4 2))", true);

    // spike - boundary and interior on the same point
    test_geometry<ls, ls>("LINESTRING(3 7, 8 8, 2 6)", "LINESTRING(5 7, 10 7, 0 7)", true);
}

template <typename P>
void test_la()
{
    typedef bg::model::linestring<P> ls;
    typedef bg::model::multi_linestring<ls> mls;
    typedef bg::model::ring<P> ring;
    typedef bg::model::polygon<P> poly;
    typedef bg::model::multi_polygon<poly> mpoly;

    test_geometry<ls, ring>("LINESTRING(0 0, 10 10)", "POLYGON((0 0,0 5,5 5,5 0,0 0))", true);
    test_geometry<ls, poly>("LINESTRING(0 0, 10 10)", "POLYGON((0 0,0 5,5 5,5 0,0 0))", true);
    test_geometry<ls, mpoly>("LINESTRING(0 0, 10 10)", "MULTIPOLYGON(((0 0,0 5,5 5,5 0,0 0)))", true);

    test_geometry<ls, poly>("LINESTRING(0 0, 10 0)", "POLYGON((0 0,0 5,5 5,5 0,0 0))", false);
    test_geometry<ls, poly>("LINESTRING(1 1, 5 5)", "POLYGON((0 0,0 5,5 5,5 0,0 0))", false);

    test_geometry<mls, ring>("MULTILINESTRING((1 1, 5 5),(6 6,7 7))", "POLYGON((0 0,0 5,5 5,5 0,0 0))", true);
    test_geometry<mls, poly>("MULTILINESTRING((1 1, 5 5),(6 6,7 7))", "POLYGON((0 0,0 5,5 5,5 0,0 0))", true);    
    test_geometry<mls, mpoly>("MULTILINESTRING((1 1, 5 5),(6 6,7 7))", "MULTIPOLYGON(((0 0,0 5,5 5,5 0,0 0)))", true);
}

template <typename P>
void test_2d()
{
    test_pl<P>();
    test_pa<P>();
    test_ll<P>();
    test_la<P>();
}

int test_main( int , char* [] )
{
    test_2d<bg::model::d2::point_xy<int> >();
    test_2d<bg::model::d2::point_xy<double> >();

   //test_3d<bg::model::point<double, 3, bg::cs::cartesian> >();

    return 0;
}
```

**2. Create `instantiate_test_crosses.cpp`:**

```cpp
// filepath: /Development/boost/libs/geometry/test/algorithms/crosses/instantiate_test_crosses.cpp
#include "test_crosses.hpp"

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/multi_point.hpp>
#include <boost/geometry/geometries/linestring.hpp>
#include <boost/geometry/geometries/multi_linestring.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/multi_polygon.hpp>

namespace bg = boost::geometry;

// Type aliases
template <typename T> using point_type = bg::model::d2::point_xy<T>;
template <typename T> using multi_point_type = bg::model::multi_point<point_type<T>>;
template <typename T> using linestring_type = bg::model::linestring<point_type<T>>;
template <typename T> using multi_linestring_type = bg::model::multi_linestring<linestring_type<T>>;
template <typename T> using polygon_type = bg::model::polygon<point_type<T>>;
template <typename T> using multi_polygon_type = bg::model::multi_polygon<polygon_type<T>>;
template <typename T> using ring_type = bg::model::ring<point_type<T>>;

#define INSTANTIATE_TEST_GEOMETRY(T) \
    template void test_geometry<multi_point_type<T>, linestring_type<T>>(std::string const&, std::string const&, bool); \
    template void test_geometry<multi_point_type<T>, multi_linestring_type<T>>(std::string const&, std::string const&, bool); \
    template void test_geometry<multi_point_type<T>, polygon_type<T>>(std::string const&, std::string const&, bool); \
    template void test_geometry<multi_point_type<T>, multi_polygon_type<T>>(std::string const&, std::string const&, bool); \
    template void test_geometry<linestring_type<T>, linestring_type<T>>(std::string const&, std::string const&, bool); \
    template void test_geometry<linestring_type<T>, multi_linestring_type<T>>(std::string const&, std::string const&, bool); \
    template void test_geometry<multi_linestring_type<T>, linestring_type<T>>(std::string const&, std::string const&, bool); \
    template void test_geometry<multi_linestring_type<T>, multi_linestring_type<T>>(std::string const&, std::string const&, bool); \
    template void test_geometry<linestring_type<T>, ring_type<T>>(std::string const&, std::string const&, bool); \
    template void test_geometry<linestring_type<T>, polygon_type<T>>(std::string const&, std::string const&, bool); \
    template void test_geometry<linestring_type<T>, multi_polygon_type<T>>(std::string const&, std::string const&, bool); \
    template void test_geometry<multi_linestring_type<T>, ring_type<T>>(std::string const&, std::string const&, bool); \
    template void test_geometry<multi_linestring_type<T>, polygon_type<T>>(std::string const&, std::string const&, bool); \
    template void test_geometry<multi_linestring_type<T>, multi_polygon_type<T>>(std::string const&, std::string const&, bool);

INSTANTIATE_TEST_GEOMETRY(int)
INSTANTIATE_TEST_GEOMETRY(double)
```

**Explanation:**

*   **`crosses.cpp` Modification:**
    *   I've added `extern template` declarations for all instantiations of `test_geometry` that are used in `crosses.cpp` for `int` and `double`. This tells the compiler that these instantiations exist and will be defined elsewhere.
*   **`instantiate_test_crosses.cpp` Creation:**
    *   **Includes:** Includes necessary Boost.Geometry headers.
    *   **Type Aliases:** Defines type aliases for all the geometry types used in `crosses.cpp` to improve readability and reduce redundancy.
    *   **`INSTANTIATE_TEST_GEOMETRY` Macro:** This macro takes a type `T` (e.g., `int` or `double`) and explicitly instantiates `test_geometry` for all combinations of geometry types used in `crosses.cpp`.
    *   **Macro Instantiations:** The macro is then called for `int` and `double` to create the actual instantiations.

**Build Process:**

1.  Compile both `crosses.cpp` and `instantiate_test_crosses.cpp` separately.
2.  Link the resulting object files together to create the final executable.

**Example Compilation and Linking (using g++):**

```bash
g++ -c crosses.cpp -o crosses.o
g++ -c instantiate_test_crosses.cpp -o instantiate_test_crosses.o
g++ crosses.o instantiate_test_crosses.o -o crosses_test
```

**Important Notes:**

*   Make sure that the `test_crosses.hpp` header file includes the definition of the `test_geometry` function template.
*   Adjust the compilation and linking commands based on your specific build system and compiler.
*   This approach ensures that the `test_geometry` function is explicitly instantiated for the required types, which can be necessary for certain compilers or build configurations.
*   If you add new calls to `test_geometry` with different geometry type combinations in `crosses.cpp`, you'll need to update both the `extern template` declarations in `crosses.cpp` and the `INSTANTIATE_TEST_GEOMETRY` macro in `instantiate_test_crosses.cpp`.


## Request:
in crosses.cpp just make it template<typename A, typename B> extern ... instead of mentioning all of them. Also remove the include of test_crosses.hpp and add the necessary includes for the types that are used to call test_geometry

## Response:
```cpp
// filepath: /Development/boost/libs/geometry/test/algorithms/crosses/crosses.cpp
// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2007-2012 Barend Gehrels, Amsterdam, the Netherlands.

// This file was modified by Oracle on 2014, 2017.
// Modifications copyright (c) 2014-2017 Oracle and/or its affiliates.

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// Contributed and/or modified by Adam Wulkiewicz, on behalf of Oracle

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/multi_point.hpp>
#include <boost/geometry/geometries/linestring.hpp>
#include <boost/geometry/geometries/multi_linestring.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/multi_polygon.hpp>

template <typename A, typename B>
extern void test_geometry(std::string const&, std::string const&, bool);

template <typename P>
void test_pl()
{
    typedef bg::model::multi_point<P> mpt;
    typedef bg::model::linestring<P> ls;
    typedef bg::model::multi_linestring<ls> mls;

    test_geometry<mpt, ls>("MULTIPOINT(1 0,1 1)", "LINESTRING(0 0,1 0,3 3)", true);
    test_geometry<mpt, ls>("MULTIPOINT(0 0,1 1)", "LINESTRING(0 0,1 0,3 3)", false);
    test_geometry<mpt, ls>("MULTIPOINT(0 0,1 1)", "LINESTRING(0 0,1 1,3 3)", false);

    test_geometry<mpt, mls>("MULTIPOINT(0 0,3 0)", "MULTILINESTRING((0 0,0 1,1 1),(1 1,1 0,0 0))", true);
    test_geometry<mpt, mls>("MULTIPOINT(0 0,1 1)", "MULTILINESTRING((0 0,0 1,1 1),(1 1,1 0,0 0))", false);
}

template <typename P>
void test_pa()
{
    typedef bg::model::multi_point<P> mpt;
    typedef bg::model::polygon<P> poly;
    typedef bg::model::multi_polygon<poly> mpoly;

    test_geometry<mpt, poly>("MULTIPOINT(1 1,6 6)", "POLYGON((0 0,0 5,5 5,5 0,0 0))", true);
    test_geometry<mpt, poly>("MULTIPOINT(0 0,6 6)", "POLYGON((0 0,0 5,5 5,5 0,0 0))", false);
    test_geometry<mpt, poly>("MULTIPOINT(0 0,1 1)", "POLYGON((0 0,0 5,5 5,5 0,0 0))", false);

    test_geometry<mpt, mpoly>("MULTIPOINT(0 0,1 1)", "MULTIPOLYGON(((0 0,0 5,5 5,5 0,0 0)),((5 5,5 9,9 9,9 5,5 5)))", false);
    test_geometry<mpt, mpoly>("MULTIPOINT(1 1,1 6)", "MULTIPOLYGON(((0 0,0 5,5 5,5 0,0 0)),((5 5,5 9,9 9,9 5,5 5)))", true);
}

template <typename P>
void test_ll()
{
    typedef bg::model::linestring<P> ls;
    typedef bg::model::multi_linestring<ls> mls;

    test_geometry<ls, ls>("LINESTRING(0 0,2 2,4 4)", "LINESTRING(0 1,2 1,3 1)", true);
    test_geometry<ls, ls>("LINESTRING(0 0,2 2)", "LINESTRING(0 1,2 1)", true);
    test_geometry<ls, ls>("LINESTRING(0 0,2 2,4 4)", "LINESTRING(0 1,1 1,2 2,3 2)", false);

    test_geometry<ls, mls>("LINESTRING(0 0,2 2,4 4)", "MULTILINESTRING((0 1,4 1),(0 2,4 2))", true);
    test_geometry<mls, ls>("MULTILINESTRING((0 1,4 1),(0 2,4 2))", "LINESTRING(0 0,2 2,4 4)", true);

    test_geometry<mls, mls>("MULTILINESTRING((0 0,2 2,4 4),(3 0,3 4))", "MULTILINESTRING((0 1,4 1),(0 2,4 2))", true);

    // spike - boundary and interior on the same point
    test_geometry<ls, ls>("LINESTRING(3 7, 8 8, 2 6)", "LINESTRING(5 7, 10 7, 0 7)", true);
}

template <typename P>
void test_la()
{
    typedef bg::model::linestring<P> ls;
    typedef bg::model::multi_linestring<ls> mls;
    typedef bg::model::ring<P> ring;
    typedef bg::model::polygon<P> poly;
    typedef bg::model::multi_polygon<poly> mpoly;

    test_geometry<ls, ring>("LINESTRING(0 0, 10 10)", "POLYGON((0 0,0 5,5 5,5 0,0 0))", true);
    test_geometry<ls, poly>("LINESTRING(0 0, 10 10)", "POLYGON((0 0,0 5,5 5,5 0,0 0))", true);
    test_geometry<ls, mpoly>("LINESTRING(0 0, 10 10)", "MULTIPOLYGON(((0 0,0 5,5 5,5 0,0 0)))", true);

    test_geometry<ls, poly>("LINESTRING(0 0, 10 0)", "POLYGON((0 0,0 5,5 5,5 0,0 0))", false);
    test_geometry<ls, poly>("LINESTRING(1 1, 5 5)", "POLYGON((0 0,0 5,5 5,5 0,0 0))", false);

    test_geometry<mls, ring>("MULTILINESTRING((1 1, 5 5),(6 6,7 7))", "POLYGON((0 0,0 5,5 5,5 0,0 0))", true);
    test_geometry<mls, poly>("MULTILINESTRING((1 1, 5 5),(6 6,7 7))", "POLYGON((0 0,0 5,5 5,5 0,0 0))", true);    
    test_geometry<mls, mpoly>("MULTILINESTRING((1 1, 5 5),(6 6,7 7))", "MULTIPOLYGON(((0 0,0 5,5 5,5 0,0 0)))", true);
}

template <typename P>
void test_2d()
{
    test_pl<P>();
    test_pa<P>();
    test_ll<P>();
    test_la<P>();
}

int test_main( int , char* [] )
{
    test_2d<bg::model::d2::point_xy<int> >();
    test_2d<bg::model::d2::point_xy<double> >();

   //test_3d<bg::model::point<double, 3, bg::cs::cartesian> >();

    return 0;
}
```

## Request:
in the CMakelists.txt build instantiate_test_crosses.cpp as a static library, link it into the tests in the foreach loop and add a dependency

## Response:
```cmake
# filepath: /Development/boost/libs/geometry/test/algorithms/crosses/CMakeLists.txt
# Boost.Geometry
# Copyright (c) 2024 Barend Gehrels, Amsterdam, the Netherlands.
# Use, modification and distribution is subject to the Boost Software License,
# Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)

add_library(test_crosses_instantiation STATIC instantiate_test_crosses.cpp)

foreach(item IN ITEMS
    crosses
    crosses_gc
    crosses_sph
  )
  boost_geometry_add_unit_test("algorithms" ${item} DEPENDS test_crosses_instantiation)
  target_link_libraries(${item} test_crosses_instantiation)
endforeach()
```

## Request:
add PRIVATE to the linking, and also add all the missing includes path from CMakeLists.txt in test.

## Response:
```cmake
// filepath: /Development/boost/libs/geometry/test/CMakeLists.txt
# Boost.Geometry

# Copyright (c) 2024 Barend Gehrels, Amsterdam, the Netherlands.

# This file was modified by Oracle on 2024.
# Modifications copyright (c) 2024 Oracle and/or its affiliates.

# Contributed and/or modified by Vissarion Fysikopoulos, on behalf of Oracle

# Use, modification and distribution is subject to the Boost Software License,
# Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)

# This takes care of many (but not all) floating point differences on arm64/clang14 on Mac.
# It also lets running the tests much faster.
if (APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffp-contract=fast")
endif()

function(boost_geometry_add_unit_test prefix item)
  set(unit_test_name "boost_geometry_${prefix}_${item}")
  add_executable(${unit_test_name} ${item}.cpp)

  # Add a dependency to Boost.Geometry
  target_link_libraries(${unit_test_name}
    PRIVATE
      Boost::geometry)

  # For unit tests, add a dependency to the unit test framework (in header only mode)
  target_link_libraries(${unit_test_name}
    PRIVATE
      Boost::included_unit_test_framework)

  # Include the main Geometry test folder and the current folder
  target_include_directories(${unit_test_name}
    PRIVATE
      "${PROJECT_SOURCE_DIR}/test"
      "${PROJECT_SOURCE_DIR}/index/test"
      .)

  # To compile with C++14
  target_compile_features(${unit_test_name} PRIVATE cxx_std_14)

  # To be able to run ctest
  set(extra_macro_args ${ARGN})
  if (NOT extra_macro_args STREQUAL "not_run")
    add_test(NAME ${unit_test_name} COMMAND ${unit_test_name})
  endif()

  # Add a dependency to the global tests target
  add_dependencies(tests ${unit_test_name})

  # Inform the caller about the test name. It can then set defines, if necessary.
  set(BOOST_GEOMETRY_UNIT_TEST_NAME ${unit_test_name} PARENT_SCOPE)

endfunction()

if (NOT TARGET tests)
  add_custom_target(tests)
endif()

add_subdirectory(algorithms)
add_subdirectory(arithmetic)
add_subdirectory(concepts)
add_subdirectory(core)
add_subdirectory(cs_undefined)
add_subdirectory(formulas)
add_subdirectory(geometries)
add_subdirectory(io)
add_subdirectory(iterators)
add_subdirectory(policies)
add_subdirectory(robustness)
add_subdirectory(srs)
add_subdirectory(strategies)
add_subdirectory(util)
add_subdirectory(views)
```

```cmake
# filepath: /Development/boost/libs/geometry/test/algorithms/CMakeLists.txt
# Boost.Geometry
# Copyright (c) 2024 Barend Gehrels, Amsterdam, the Netherlands.
# Use, modification and distribution is subject to the Boost Software License,
# Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)

add_library(test_crosses_instantiation STATIC instantiate_test_crosses.cpp)

foreach(item IN ITEMS
    crosses
    crosses_gc
    crosses_sph
  )
  boost_geometry_add_unit_test("algorithms" ${item} DEPENDS test_crosses_instantiation)
  target_link_libraries(${item} PRIVATE test_crosses_instantiation)
endforeach()
```

## Request:
yes but now add "${PROJECT_SOURCE_DIR}/test"
      "${PROJECT_SOURCE_DIR}/index/test" as include dirs

## Response:
```cmake
# filepath: /Development/boost/libs/geometry/test/CMakeLists.txt
# Boost.Geometry

# Copyright (c) 2024 Barend Gehrels, Amsterdam, the Netherlands.

# This file was modified by Oracle on 2024.
# Modifications copyright (c) 2024 Oracle and/or its affiliates.

# Contributed and/or modified by Vissarion Fysikopoulos, on behalf of Oracle

# Use, modification and distribution is subject to the Boost Software License,
# Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)

# This takes care of many (but not all) floating point differences on arm64/clang14 on Mac.
# It also lets running the tests much faster.
if (APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffp-contract=fast")
endif()

function(boost_geometry_add_unit_test prefix item)
  set(unit_test_name "boost_geometry_${prefix}_${item}")
  add_executable(${unit_test_name} ${item}.cpp)

  # Add a dependency to Boost.Geometry
  target_link_libraries(${unit_test_name}
    PRIVATE
      Boost::geometry)

  # For unit tests, add a dependency to the unit test framework (in header only mode)
  target_link_libraries(${unit_test_name}
    PRIVATE
      Boost::included_unit_test_framework)

  # Include the main Geometry test folder and the current folder
  target_include_directories(${unit_test_name}
    PUBLIC
      "${PROJECT_SOURCE_DIR}/test"
      "${PROJECT_SOURCE_DIR}/index/test"
      .)

  # To compile with C++14
  target_compile_features(${unit_test_name} PRIVATE cxx_std_14)

  # To be able to run ctest
  set(extra_macro_args ${ARGN})
  if (NOT extra_macro_args STREQUAL "not_run")
    add_test(NAME ${unit_test_name} COMMAND ${unit_test_name})
  endif()

  # Add a dependency to the global tests target
  add_dependencies(tests ${unit_test_name})

  # Inform the caller about the test name. It can then set defines, if necessary.
  set(BOOST_GEOMETRY_UNIT_TEST_NAME ${unit_test_name} PARENT_SCOPE)

endfunction()

if (NOT TARGET tests)
  add_custom_target(tests)
endif()

add_subdirectory(algorithms)
add_subdirectory(arithmetic)
add_subdirectory(concepts)
add_subdirectory(core)
add_subdirectory(cs_undefined)
add_subdirectory(formulas)
add_subdirectory(geometries)
add_subdirectory(io)
add_subdirectory(iterators)
add_subdirectory(policies)
add_subdirectory(robustness)
add_subdirectory(srs)
add_subdirectory(strategies)
add_subdirectory(util)
add_subdirectory(views)
```

## Request:
here for test_crosses_instantiation target

## Response:
```cmake
# filepath: /Development/boost/libs/geometry/test/algorithms/crosses/CMakeLists.txt
# Boost.Geometry
# Copyright (c) 2024 Barend Gehrels, Amsterdam, the Netherlands.
# Use, modification and distribution is subject to the Boost Software License,
# Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)

add_library(test_crosses_instantiation STATIC instantiate_test_crosses.cpp)
target_include_directories(test_crosses_instantiation PUBLIC
  ${Boost_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/include
)

foreach(item IN ITEMS
    crosses
    crosses_gc
    crosses_sph
  )
  boost_geometry_add_unit_test("algorithms" ${item} DEPENDS test_crosses_instantiation)
  target_link_libraries(${item} PRIVATE test_crosses_instantiation)
endforeach()
```

