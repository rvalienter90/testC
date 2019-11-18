//
// Created by nsl on 11/12/19.
//

#include "testcode.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int ch_data_valid;

}htype;
typedef struct {
       double          latDegrees;                             //!< adjusted for antenna offset
    double          longDegrees;                            //!< adjusted for antenna offset
    double          latRawDegrees;                          //!< as received from tps
    double          longRawDegrees;                         //!< as received from tps
    double          altitudeMeters;
    double          groundSpeedMPS;                         //!< in meters per second (converted from Knots by TPS)
    double          headingDegrees;                         //!< tps course from 0-360 degrees
    double          hdop;                                   //!< Horizontal Dilution of Precision - X.x
    double          pdop;                                   //!< Position dilution of precision
    double          latErrorMeters;                         //!< Latitude Error - XX.x m
    double          longErrorMeters;                        //!< Longitude Error - XX.x m
    double          altErrorMeters;                         //!< Altitude Error - XX.x m
    double          smjrError;                              //!< Standard deviation of semi-major axis of error ellipse (m) x.x
    double          smnrError;                              //!< Standard deviation of semi-minor axis of error ellipse (m) x.x
    double          smjrErrorOrient;                        //!< Orientation of semi-major axis of error ellipse (Degrees from True north)
    float           errorCircle;                            //!< Error circle, calculated based on latitude and Longitude error values
    double          differentialAgeSeconds;                 //!< Age of Differential GPS data (in seconds)
    double          solutionAgeSeconds;                     //!< diff in seconds between system time and GPS info time
    //!< GPS_SOURCE_GPS (0) = data is from tps and adjusted for antenna offsets
    //!< GPS_SOURCE_COASTED (1) = data is from tps, adjusted for antenna offsets, and
    //!<       coasted to the timeMillisecs member
    //!< Coasted data includes timeMillisecs, latDegrees, longDegrees, and altitudeMeters
    //!< Same as timeMillisecs if source is GPS_SOURCE_GPS
    //!< Data captured by tps callback from the GPS, not changed by any coasting
    double          uncoastedFilteredHeadingDegrees;        //!< Heading 0 - 360 degrees
    double          uncoastedGroundSpeedMPS;                //!< Ground speed (meters per second)
    double          uncoastedAltitudeMeters;                //!< Altitude (meters)
    double          autoDetectSampleTimeS;                  //!< Auto-detected GPS update period in seconds.
    int8_t          curLeapSecs;                            //!< Current Leap Seconds between GPS time & UTC Time
    int8_t          upcomingLeapSecChange;                  //!< Upcoming leap second change if scheduled (+1 or -1)
    int32_t         timeToLeapSecEvent_secs;                //!< Time in seconds until next leap second change, if scheduled
    unsigned long long tps_data_ind_age_msec;               //!< diff in msec between solution time and time when sdhgps gets tps data indicator
    double          hdgLatchStateUnlatchSpeedMps;           //!< Vehicle speed threshold used to make the heading unlatch decision
    double          hdgLatchStateDecisionSpeedMps;          //!< Vehicle speed used to make the heading latch decision
    double filteredHeadingDegrees;
    htype h;
} shm_sdhgps_t;


