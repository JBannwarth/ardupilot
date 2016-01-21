/// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

#include "Copter.h"

#ifdef USERHOOK_INIT
void Copter::userhook_init()
{
    // put your initialisation code here
    // this will be called once at start-up

    // Airspeed
    airspeed.init();
    airspeed.calibrate(false);
}
#endif

#ifdef USERHOOK_FASTLOOP
void Copter::userhook_FastLoop()
{
    // put your 100Hz code here
}
#endif

#ifdef USERHOOK_50HZLOOP
void Copter::userhook_50Hz()
{
    // put your 50Hz code here

    // AIRSPEED
    // Update airspeed
    airspeed.read();
    // Get temperature
    float temp = 0.0f;
    airspeed.get_temperature(temp);
    // Print to console
    // hal.console->printf("Airspeed: %.3f Temp: %.3f\n",airspeed.get_airspeed(),temp);
    // Log airspeed information
    Log_Write_Airspeed(airspeed.get_airspeed(), airspeed.get_raw_airspeed(), temp, airspeed.get_airspeed_ratio());

    // WINDCOMP LOGGING
//    Log_Write_Windcomp(pos_control.get_airspeed(),
//            pos_control.get_airspeed_filt(),
//            pos_control.get_windspeed(),
//            pos_control.get_windspeed_filt_lp(),
//            pos_control.get_windspeed_filt_hp(),
//            pos_control.get_vel_bf_x());

    // POSCONTROL LOGGING
//    Log_Write_Poswind();
}
#endif

#ifdef USERHOOK_MEDIUMLOOP
void Copter::userhook_MediumLoop()
{
    // put your 10Hz code here
}
#endif

#ifdef USERHOOK_SLOWLOOP
void Copter::userhook_SlowLoop()
{
    // put your 3.3Hz code here
}
#endif

#ifdef USERHOOK_SUPERSLOWLOOP
void Copter::userhook_SuperSlowLoop()
{
    // put your 1Hz code here
}
#endif
