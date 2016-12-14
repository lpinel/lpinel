#include "ratethread.hpp"

int main(void) {

	/** Check yarp network**/
	yarp::os::Network yarp;

	printf("Checking network...\n");
    if (!yarp.checkNetwork()) {
        printf("Please start a yarp name server first\n");
       return(-1);
    }
    printf("Network ok\n");

 	/** Opening YARP ports**/
    port2.open("/jr3ch2:i"); //Opening port associated to jr3 channel 2 (RIGHT ARM)
    port3.open("/jr3ch3:i"); //Opening port associated to jr3 channel 3 (LEFT ARM)

    /** Connecting I/O YARP ports**/
    yarp::os::Time::delay(0.5);
    yarp.connect("/jr3ch2:o","/jr3ch2:i");
    yarp::os::Time::delay(0.5);
    yarp.connect("/jr3ch3:o","/jr3ch3:i");

    MyRateThread jr3Thread;
	jr3Thread.start();

	char c;
	do {
		c=getchar();
	} while (c != '\n');

	jr3Thread.stop();
	port2.close();
	port3.close();

    return 0;
}
