
#include "Clock.h"
#include <cstdlib>
#include <stdlib.h>

Clock::Clock() {
	Clock(0, 0);
}
Clock::~Clock() {};

Clock::Clock(int currentTime, int x) {
	Clock::currentTime = currentTime;
	Clock::x = x;//x serves as the max value
}
int Clock::generateArrival()
{
	int random;
	random = rand()%x + 1;
	random = random + currentTime;
	return random; // returns a value between 0 and x and adds it to the clock.  This is the actual arrival time
}
int Clock::generateServiceTime()
{
	return (rand()%1 + x);  //returns a value between 0 and x.  This is the actual service time
}
int Clock::getCurrentTime() { return currentTime; }
void Clock::setCurrentTime(int C)
{
	currentTime = C;
}
void Clock::setX(int input) { x = input; }