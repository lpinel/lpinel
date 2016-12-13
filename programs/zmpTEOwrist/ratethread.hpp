#ifndef _ratethread_H_
#define _ratethread_H_

#include "global.h"

yarp::os::Port port2;
yarp::os::Port port3;

class MyRateThread : public yarp::os::RateThread
{
public:
    MyRateThread() : yarp::os::RateThread(TS*1000.0){
		_d =  0.025;

	}

	void run(){

		ReadFTSensor();
		_angle = 90.0;
		AxesTransform(_angle);
        printf("1\n");
		ZMPcomp();
        printf("2\n");
	}

	void ReadFTSensor(){

        port2.read(_sensor2.bottle);
        port3.read(_sensor3.bottle);

        _sensor2.fx = _sensor2.bottle.get(0).asDouble();
        _sensor2.fy = _sensor2.bottle.get(1).asDouble();
        _sensor2.fz = _sensor2.bottle.get(2).asDouble();
        _sensor2.mx = _sensor2.bottle.get(3).asDouble();
        _sensor2.my = _sensor2.bottle.get(4).asDouble();

        _sensor3.fx = _sensor3.bottle.get(0).asDouble();
        _sensor3.fy = _sensor3.bottle.get(1).asDouble();
        _sensor3.fz = _sensor3.bottle.get(2).asDouble();
        _sensor3.mx = _sensor3.bottle.get(3).asDouble();
        _sensor3.my = _sensor3.bottle.get(4).asDouble();

	}

	void AxesTransform(float angle){ 
		// angle is the rotation angle between rest state (all joints 0 deg) and the final position 

		// first we make a transformation between TEO_body_axes (world)  and Jr3_axes
		_teo.fx = + _sensor2.fx;
		_teo.fy = - _sensor2.fy;
		_teo.fz = - _sensor2.fz;
		_teo.mx = + _sensor2.mx;
		_teo.my = - _sensor2.my;

		// second, we make the tranformation between rest state to waiter state (horizontal tray)
		_teo.fx = cos(angle)*_teo.fx + sin(angle)*_teo.fz;
        _teo.fy = _teo.fy;
        _teo.fz = -sin(angle)*_teo.fx + cos(angle)*_teo.fz;
		_teo.mx = cos(angle)*_teo.mx + sin(angle)*_teo.mz;
        _teo.my = _teo.my;
	}


	void ZMPcomp(){
		/** ZMP Equations **/
        _sensor2.xzmp = -(_teo.my) / _teo.fz;
        _sensor2.yzmp = (_teo.mx) / _teo.fz;


        cout << _sensor2.xzmp << "," << _sensor2.yzmp << endl;

	}

private:
	struct SensorData {
		double fx, fy, fz;
		double mx, my, mz;
		yarp::os::Bottle bottle;
		double xzmp, yzmp;
	} _sensor2, _sensor3;

	struct TEOData {
		double fx, fy, fz;
		double mx, my, mz;
	} _teo;	

	float _d;  //distance in mm between the plate center and the sensor center
	float _angle;
};


#endif //_ratethread_H_
