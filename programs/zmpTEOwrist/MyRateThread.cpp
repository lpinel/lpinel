#include "MyRateThread.hpp"

/************************************************************************/
ratethread::MyRateThread() : yarp::os::RateThread(TS*1000.0){
	_d =  0.025;
}

/************************************************************************/
void ratethread::run(){
	ReadFTSensor();
	AxesTransform();
	ZMPcomp();
}

/************************************************************************/
void ratethread::ReadFTSensor(){

	port2.read(_sensor2.bottle);
    port3.read(_sensor3.bottle);

    _sensor2.fx = _sensor2.bottle.get(0).asDouble();
    _sensor2.fy = _sensor2.bottle.get(1).asDouble();
    _sensor2.fz = _sensor2.bottle.get(2).asDouble();
    _sensor2.mx = _sensor2.bottle.get(3).asDouble();
    _sensor2.my = _sensor2.bottle.get(4).asDouble();
    _sensor2.mz = _sensor2.bottle.get(5).asDouble();

    _sensor3.fx = _sensor3.bottle.get(0).asDouble();
    _sensor3.fy = _sensor3.bottle.get(1).asDouble();
    _sensor3.fz = _sensor3.bottle.get(2).asDouble();
    _sensor3.mx = _sensor3.bottle.get(3).asDouble();
    _sensor3.my = _sensor3.bottle.get(4).asDouble();
    _sensor3.mz = _sensor3.bottle.get(5).asDouble();
}

/************************************************************************/
void ratethread::AxesTransform(){ 
	//Transformation matrix between TEO_body_axes (world)  and Jr3_axes with horizontal tray (waiter)
	_tray.fx = + _sensor2.fz;
	_tray.fy = - _sensor2.fy;
	_tray.fz = + _sensor2.fx;
	_tray.mx = + _sensor2.mz;
	_tray.my = - _sensor2.my;
	_tray.mz = + _sensor2.mx;
}

/************************************************************************/
void ratethread::ZMPcomp(){
	/** ZMP Equations **/
    _tray.xzmp = (- (_tray.my) / _tray.fz)) + _d;
    _tray.yzmp = (_tray.mx) / _tray.fz;

    cout << "ZMP: [" << _sensor2.xzmp << ", " << _sensor2.yzmp << "]" << endl;
}
