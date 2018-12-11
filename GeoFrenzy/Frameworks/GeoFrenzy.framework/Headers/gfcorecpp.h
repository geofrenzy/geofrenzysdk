//       1         2         3         4         5         6         7         8         9        10        11        12        13
//3456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012
//**********************************************************************************************************************************
//
//    This is the C interface.
// 
//**********************************************************************************************************************************

#ifndef GFCORECPP_HEADER
#define GFCORECPP_HEADER

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

    // typedef's
    typedef double float_type;
    
    // enumerations
    enum Projection { GnomonicSpherical, GnomonicEllipsoidal };
    enum EarthModel { Spherical, Ellipsoidal };
    enum AngularUnits { Radians, Degrees };
    
    // interface structures
    struct Geodetic
    {
        float_type latitude;  // the geodetic latitude in degrees North
        float_type longitude; // the geodetic longitude in degrees East
    };
    
    struct Cartesian
    {
        float_type x;  // x coordinate
        float_type y;  // y coordinate
    };
    
    struct CartesianLine
    {
        struct Cartesian start;
        struct Cartesian end;
    };
    
    struct GeodeticPolygon
    {
        const struct Geodetic *verticies;
        uint16_t count;
    };
    
    struct GroupedHexPolygon
    {
        const char* const* groupedHexVerticies;
        uint16_t count;
    };
    
    

    // interface functions

    // calculate the destination point of an offset from the origin coordinate along a true north bearing in degrees and a distance
    // in kilometers.  It returns true on success.
    bool pOffsetFromLocation(const struct Geodetic* const pOrigin, const float_type distanceKm, const float_type bearing,
                             struct Geodetic* const pDestination, const enum EarthModel model);// = Ellipsoidal
    bool offsetFromLocation(const struct Geodetic origin, const float_type distanceKm, const float_type bearing,
                            struct Geodetic* const pDestination, const enum EarthModel model);// = Ellipsoidal

    // calculate the distance in meters and bearing in radians/degrees from true north of a geodetic line originating at the origin
    // point to a destination point.  It returns true on success.
    bool pDistanceBearing(const struct Geodetic* const pOrigin, const struct Geodetic* const pDestination, float_type* const pDistanceMeters,
                          float_type* const pBearing, const enum AngularUnits angularUnits, const enum EarthModel model);// = Degrees = Ellipsoidal
    bool distanceBearing(const struct Geodetic origin, const struct Geodetic destination, float_type* const pDistanceMeters,
                         float_type* const pBearing, const enum AngularUnits angularUnits, const enum EarthModel model);// = Degrees = Ellipsoidal

    // calculate the cartesian projection of the point from the origin in the specified projection model.  It returns true on
    // success.
    bool pProjectFromOrigin(const struct Geodetic* const pOrigin, const struct Geodetic* const pPoint, struct Cartesian* const pCartesian,
                            const enum Projection projection);// = GnomonicEllipsoidal
    bool projectFromOrigin(const struct Geodetic origin, const struct Geodetic point, struct Cartesian* const pCartesian,
                           const enum Projection projection);// = GnomonicEllipsoidal

    // calculate the geodetic point from the cartesian projection of the point from the origin in the specified projection model.
    // It returns true on success.
    bool pPointFromProjection(const struct Geodetic* const pOrigin, const struct Cartesian* const pCartesian, struct Geodetic* const pPoint,
                              const enum Projection projection);// = GnomonicEllipsoidal
    bool pointFromProjection(const struct Geodetic origin, const struct Cartesian cartesian, struct Geodetic* const pPoint,
                             const enum Projection projection);// = GnomonicEllipsoidal

    // this returns the centroid of the geodetic polygon.  It returns true on success.
    bool pCentroidOfPolygon(const struct GeodeticPolygon* const pPolygon, struct Geodetic* const pCentroid, const enum EarthModel model);// = Ellipsoidal
    bool centroidOfPolygon(const struct GeodeticPolygon polygon, struct Geodetic* const pCentroid, const enum EarthModel model);// = Ellipsoidal

    // this returns whether the point is inside the geodetic polygon.  It returns true on success.
    bool pInsidePolygon(const struct GeodeticPolygon* const pPolygon, const struct Geodetic* const pPoint, bool* const pInside,
                        const enum EarthModel model);// = Ellipsoidal
    bool insidePolygon(const struct GeodeticPolygon polygon, const struct Geodetic point, bool* const pInside,
                       const enum EarthModel model);// = Ellipsoidal

    // this returns the geodetic polygon is self intersecting.  It returns true on success.
    bool pSelfIntersectingPolygon(const struct GeodeticPolygon* const pPolygon, bool* const pSelfIntersecting,
                                  const enum EarthModel model);// = Ellipsoidal
    bool selfIntersectingPolygon(const struct GeodeticPolygon polygon, bool* const pSelfIntersecting,
                                 const enum EarthModel model);// = Ellipsoidal

    // this returns the closest edge of geodetic polygon to the given point.  It returns true on success.
    bool pClosestPolygonEdgeToPoint(const struct GeodeticPolygon* const pPolygon, const struct Geodetic* const pPoint,
                                    uint16_t* const pClosestEdge, const enum EarthModel model);// = Ellipsoidal
    bool closestPolygonEdgeToPoint(const struct GeodeticPolygon polygon, const struct Geodetic point, uint16_t* const pClosestEdge,
                                   const enum EarthModel model);// = Ellipsoidal

    // this takes the grouped hex quad number and returns the equivalent geodetic location.  It returns true on success.
    bool groupedHexToPoint(const char* const groupedHex, struct Geodetic* const pPoint);

    // this takes the hex quad number and returns the equivalent geodetic location.  It returns true on success.
    bool hexToPoint(const char* const hex, struct Geodetic* const pPoint);

    // calculate the grouped hex representation of the morton number of the specified level from [1, 32].  The returned grouped hex
    // is null terminated.  It returns true on success.
    bool pPointToGroupedHex(const struct Geodetic* const pPoint, const uint8_t level, char(*const pGroupedHex)[20]);
    bool pointToGroupedHex(const struct Geodetic point, const uint8_t level, char(*const pGroupedHex)[20]);

    // calculate the hex representation of the morton number of the specified level from [1, 32].  The returned hex is null
    // terminated.  It returns true on success.
    bool pPointToHex(const struct Geodetic* const pPoint, const uint8_t level, char(*const pHex)[17]);
    bool pointToHex(const struct Geodetic point, const uint8_t level, char(*const pHex)[17]);

    // This take the geodetic point and converts it to a morton number of the specified level from [1, 32].  The returned morton
    // number is null terminated.  It returns true on success.
    bool pPointToMorton(const struct Geodetic* const point, const uint8_t level, char(*const pMorton)[65]);
    bool pointToMorton(const struct Geodetic point, const uint8_t level, char(*const pMorton)[65]);
//
    // calculate the bounding box of an offset from the origin coordinate a distance in kilometers.  It returns true on success.
//    bool pBoundingBoxFromLocation(const struct Geodetic* const pOrigin, const float_type distance, Geodetic(*const pBoundingBox)[4],
//                                  const enum EarthModel model);// = Ellipsoidal
//    bool boundingBoxFromLocation(const struct Geodetic origin, const float_type distance, Geodetic(*const pBoundingBox)[4],
//                                 const enum EarthModel model);// = Ellipsoidal

    // this returns whether the point is inside the grouped hex polygon.  It returns true on success.
    bool pInsideGroupedHexPolygon(const struct GroupedHexPolygon* const pPolygon, const struct Geodetic* const pPoint, bool* pInside,
                                  const enum EarthModel model);// = Ellipsoidal
    bool insideGroupedHexPolygon(const struct GroupedHexPolygon polygon, const struct Geodetic point, bool* pInside,
                                 const enum EarthModel model);// = Ellipsoidal

    // this returns whether the two cartesian lines line1 and line2 have an intersect point.  It returns true on success.
    bool pLineIntersection(const struct CartesianLine* const pLine1, const struct CartesianLine* const pLine2, struct Cartesian* const pIntersect);
    bool lineIntersection(const struct CartesianLine line1, const struct CartesianLine line2, struct Cartesian* const pIntersect);

    // this takes the grouped hex record and adds an optional prefix and suffix to form an IPV6 string and returns the reverse DNS
    // record.  It returns true on success.
    bool groupedHexToIPV6ReverseDNS(char(*const pReverseDNS)[73], const char* const groupedHex,
                                    const char* const prefix, const char* const suffix);

    // this takes the geodetic point and returns the earth-centered, earth-fixed X, Y, Z coordinate.  If unitRaidus is true then
    // the results are scaled such that the earth radius at the equator is 1.  It returns true on success.
    bool pPointToECEF(const struct Geodetic* const pPoint, float_type(*const pECEF)[3], const enum EarthModel model,
                     const bool unitRadius);// = Ellipsoidal  = false
    bool pointToECEF(const struct Geodetic point, float_type(*const pECEF)[3], const enum EarthModel model,
                     const bool unitRadius);// = Ellipsoidal  = false

    // this takes the earth-centered, earth-fixed X, Y, Z coordinates and returns the geodetic point and height in meters in the 
    // the given model.  If unitRaidus is true then the X, Y, Z coordinates are assumed scaled such that the earth radius at the
    // equator is 1.  It returns true on success.
    bool pECEFToPoint(const float_type(*const pECEF)[3], struct Geodetic* const pPoint, float_type* const pHeight,
                      const enum EarthModel model, const bool unitRadius);// = Ellipsoidal = false
    bool ECEFToPoint(const float_type ECEF[3], struct Geodetic* const pPoint, float_type* const pHeight,
                     const enum EarthModel model, const bool unitRadius);// = Ellipsoidal = false
    
    // this takes two Geodetic lines, i.e. [start1, end1] and [start2, end2], and returns the geodetic intersection point.  It
    // returns true on success.
    bool pGeodeticLineIntersection(const struct Geodetic* const pStart1, const struct Geodetic* const pEnd1, const struct Geodetic* const pStart2,
                                   const struct Geodetic* const pEnd2, struct Geodetic* const pPoint, const enum EarthModel model);  //Elipsoidal
    bool geodeticLineIntersection(struct Geodetic start1, struct Geodetic end1, struct Geodetic start2, struct Geodetic end2, struct Geodetic* const pPoint,
                                  const enum EarthModel model); //Elipsoidal
    
#ifdef __cplusplus
}
#endif

#endif // GFCORECPP_HEADER

//**********************************************************************************************************************************
//3456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012
//       1         2         3         4         5         6         7         8         9        10        11        12        13
