// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef _ratethread_H_
#define _ratethread_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <cmath>

#include <yarp/os/all.h>
#include <yarp/dev/all.h>

#define PI  3.141592
#define TS 0.03
#define L   0.8927 // Pendulum Longitude
#define M   62.589 // Robot mass
#define g   9.81 // Gravity in m/s²

using namespace std;

/**
 * @ingroup zmpTEOwrist
 *
 * @brief ZMP_tray computation from left arm FT sensor
 *
 */

class MyRateThread : public yarp::os::RateThread
{
public:
    MyRateThread() : yarp::os::RateThread(TS*1000.0){
        _d =  0.025;
    }
	void run();
	void ReadFTSensor();
	void AxesTransform();
    void ZMPcomp();
    /** set language in speechRecognition port */
    bool setPorts(yarp::os::Port port2, yarp::os::Port port3);

private:
	struct SensorData {
		double fx, fy, fz;
		double mx, my, mz;
		yarp::os::Bottle bottle;
	} _sensor2, _sensor3;

	struct TrayData {
		double fx, fy, fz;
		double mx, my, mz;
		double xzmp, yzmp;
	} _tray;	

    float _d;  //distance in mm between the plate center and the sensor center in the X axis

    yarp::os::Port _port2;
    yarp::os::Port _port3;
};


#endif //_ratethread_H_
