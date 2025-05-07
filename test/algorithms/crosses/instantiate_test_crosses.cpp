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