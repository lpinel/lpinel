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

using namespace std;

yarp::os::Port port2;
yarp::os::Port port3;


/**
 * @ingroup zmpTEOwrist
 *
 * @brief ZMP_tray computation from left arm FT sensor
 *
 */
class MyRateThread : public yarp::os::RateThread
{
public:
	void run();
	void ReadFTSensor();
	void AxesTransform();
	void ZMPcomp();

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

};


#endif //_ratethread_H_