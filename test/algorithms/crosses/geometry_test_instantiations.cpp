#include "test_crosses.hpp"
#include <boost/geometry/geometries/geometries.hpp>

namespace bg = boost::geometry;

// Explicitly instantiate test_geometry for all types used in the tests

// Cartesian 2D point
template void test_geometry<bg::model::linestring<bg::model::point<double, 2, bg::cs::cartesian>>, bg::model::polygon<bg::model::point<double, 2, bg::cs::cartesian>>>(std::string const&, std::string const&, bool);
template void test_geometry<bg::model::multi_linestring<bg::model::linestring<bg::model::point<double, 2, bg::cs::cartesian>>>, bg::model::multi_polygon<bg::model::polygon<bg::model::point<double, 2, bg::cs::cartesian>>>>(std::string const&, std::string const&, bool);

// Spherical 2D point
template void test_geometry<bg::model::multi_linestring<bg::model::linestring<bg::model::point<double, 2, bg::cs::spherical_equatorial<bg::degree>>>>, bg::model::multi_polygon<bg::model::polygon<bg::model::point<double, 2, bg::cs::spherical_equatorial<bg::degree>>>>>(std::string const&, std::string const&, bool);

// Geometry collections
template void test_geometry<bg::model::geometry_collection<boost::variant<bg::model::point<double, 2, bg::cs::cartesian>, bg::model::linestring<bg::model::point<double, 2, bg::cs::cartesian>>, bg::model::polygon<bg::model::point<double, 2, bg::cs::cartesian>>>>, bg::model::geometry_collection<boost::variant<bg::model::point<double, 2, bg::cs::cartesian>, bg::model::linestring<bg::model::point<double, 2, bg::cs::cartesian>>, bg::model::polygon<bg::model::point<double, 2, bg::cs::cartesian>>>>>(std::string const&, std::string const&, bool);

// Explicit template instantiations for Cartesian coordinates
template void test_geometry<bg::model::multi_point<bg::model::d2::point_xy<int>>, bg::model::linestring<bg::model::d2::point_xy<int>>>(std::string const&, std::string const&, bool);
template void test_geometry<bg::model::multi_point<bg::model::d2::point_xy<double>>, bg::model::linestring<bg::model::d2::point_xy<double>>>(std::string const&, std::string const&, bool);

template void test_geometry<bg::model::multi_point<bg::model::d2::point_xy<int>>, bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<int>>>>(std::string const&, std::string const&, bool);
template void test_geometry<bg::model::multi_point<bg::model::d2::point_xy<double>>, bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<double>>>>(std::string const&, std::string const&, bool);

template void test_geometry<bg::model::multi_point<bg::model::d2::point_xy<int>>, bg::model::polygon<bg::model::d2::point_xy<int>>>(std::string const&, std::string const&, bool);
template void test_geometry<bg::model::multi_point<bg::model::d2::point_xy<double>>, bg::model::polygon<bg::model::d2::point_xy<double>>>(std::string const&, std::string const&, bool);

template void test_geometry<bg::model::multi_point<bg::model::d2::point_xy<int>>, bg::model::multi_polygon<bg::model::polygon<bg::model::d2::point_xy<int>>>>(std::string const&, std::string const&, bool);
template void test_geometry<bg::model::multi_point<bg::model::d2::point_xy<double>>, bg::model::multi_polygon<bg::model::polygon<bg::model::d2::point_xy<double>>>>(std::string const&, std::string const&, bool);

template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<int>>, bg::model::linestring<bg::model::d2::point_xy<int>>>(std::string const&, std::string const&, bool);
template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<double>>, bg::model::linestring<bg::model::d2::point_xy<double>>>(std::string const&, std::string const&, bool);

template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<int>>, bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<int>>>>(std::string const&, std::string const&, bool);
template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<double>>, bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<double>>>>(std::string const&, std::string const&, bool);

template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<int>>, bg::model::ring<bg::model::d2::point_xy<int>>>(std::string const&, std::string const&, bool);
template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<double>>, bg::model::ring<bg::model::d2::point_xy<double>>>(std::string const&, std::string const&, bool);

template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<int>>, bg::model::polygon<bg::model::d2::point_xy<int>>>(std::string const&, std::string const&, bool);
template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<double>>, bg::model::polygon<bg::model::d2::point_xy<double>>>(std::string const&, std::string const&, bool);

template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<int>>, bg::model::multi_polygon<bg::model::polygon<bg::model::d2::point_xy<int>>>>(std::string const&, std::string const&, bool);
template void test_geometry<bg::model::linestring<bg::model::d2::point_xy<double>>, bg::model::multi_polygon<bg::model::polygon<bg::model::d2::point_xy<double>>>>(std::string const&, std::string const&, bool);

template void test_geometry<bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<int>>>, bg::model::multi_polygon<bg::model::polygon<bg::model::d2::point_xy<int>>>>(std::string const&, std::string const&, bool);
template void test_geometry<bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<double>>>, bg::model::multi_polygon<bg::model::polygon<bg::model::d2::point_xy<double>>>>(std::string const&, std::string const&, bool);

// Explicit template instantiations for Spherical coordinates
template void test_geometry<bg::model::linestring<bg::model::point<double, 2, bg::cs::spherical_equatorial<bg::degree>>>, bg::model::polygon<bg::model::point<double, 2, bg::cs::spherical_equatorial<bg::degree>>>>(std::string const&, std::string const&, bool);
template void test_geometry<bg::model::linestring<bg::model::point<double, 2, bg::cs::spherical_equatorial<bg::degree>>>, bg::model::ring<bg::model::point<double, 2, bg::cs::spherical_equatorial<bg::degree>>>>(std::string const&, std::string const&, bool);
template void test_geometry<bg::model::linestring<bg::model::point<double, 2, bg::cs::spherical_equatorial<bg::degree>>>, bg::model::multi_polygon<bg::model::polygon<bg::model::point<double, 2, bg::cs::spherical_equatorial<bg::degree>>>>>(std::string const&, std::string const&, bool);

// Explicit template instantiations for Geometry Collections
template void test_geometry<bg::model::linestring<bg::model::point<double, 2, bg::cs::cartesian>>, bg::model::geometry_collection<boost::variant<bg::model::point<double, 2, bg::cs::cartesian>, bg::model::linestring<bg::model::point<double, 2, bg::cs::cartesian>>, bg::model::polygon<bg::model::point<double, 2, bg::cs::cartesian>>>>>(std::string const&, std::string const&, bool);
template void test_geometry<bg::model::geometry_collection<boost::variant<bg::model::point<double, 2, bg::cs::cartesian>, bg::model::linestring<bg::model::point<double, 2, bg::cs::cartesian>>, bg::model::polygon<bg::model::point<double, 2, bg::cs::cartesian>>>>, bg::model::polygon<bg::model::point<double, 2, bg::cs::cartesian>>>(std::string const&, std::string const&, bool);
template void test_geometry<bg::model::geometry_collection<boost::variant<bg::model::point<double, 2, bg::cs::cartesian>, bg::model::linestring<bg::model::point<double, 2, bg::cs::cartesian>>, bg::model::polygon<bg::model::point<double, 2, bg::cs::cartesian>>>>, bg::model::linestring<bg::model::point<double, 2, bg::cs::cartesian>>>(std::string const&, std::string const&, bool);

// Explicit template instantiations for int
template void test_geometry<
    bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<int, bg::cs::cartesian>>>,
    bg::model::linestring<bg::model::d2::point_xy<int, bg::cs::cartesian>>>(
    std::string const&, std::string const&, bool);

template void test_geometry<
    bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<int, bg::cs::cartesian>>>,
    bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<int, bg::cs::cartesian>>>>(
    std::string const&, std::string const&, bool);

template void test_geometry<
    bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<int, bg::cs::cartesian>>>,
    bg::model::ring<bg::model::d2::point_xy<int, bg::cs::cartesian>>>(
    std::string const&, std::string const&, bool);

template void test_geometry<
    bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<int, bg::cs::cartesian>>>,
    bg::model::polygon<bg::model::d2::point_xy<int, bg::cs::cartesian>>>(
    std::string const&, std::string const&, bool);

// Explicit template instantiations for double
template void test_geometry<
    bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<double, bg::cs::cartesian>>>,
    bg::model::linestring<bg::model::d2::point_xy<double, bg::cs::cartesian>>>(
    std::string const&, std::string const&, bool);

template void test_geometry<
    bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<double, bg::cs::cartesian>>>,
    bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<double, bg::cs::cartesian>>>>(
    std::string const&, std::string const&, bool);

template void test_geometry<
    bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<double, bg::cs::cartesian>>>,
    bg::model::ring<bg::model::d2::point_xy<double, bg::cs::cartesian>>>(
    std::string const&, std::string const&, bool);

template void test_geometry<
    bg::model::multi_linestring<bg::model::linestring<bg::model::d2::point_xy<double, bg::cs::cartesian>>>,
    bg::model::polygon<bg::model::d2::point_xy<double, bg::cs::cartesian>>>(
    std::string const&, std::string const&, bool);