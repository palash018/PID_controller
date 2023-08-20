#include "PID.h"
#include <iostream>
PID::PID(double kp,double ki,double kd){
  kp=kp;
  ki=ki;
  kd=kd;
  curr_time=time(NULL);
  prev_time=time(NULL);
  prev_error=0;
}

double PID::compute(double curr_value,double expected_value){
  double curr_error=expected_value-curr_value;
  prev_time=curr_time;
  curr_time=time(NULL);
  unsigned int time_diff=curr_time-prev_time;
  error_sum+=curr_error*(time_diff);
  double diff_error=curr_error-prev_error;
  prev_error=curr_error;
  return kp*curr_error+ki*error_sum+kd*diff_error/time_diff;
}
void PID::reset(double kp,double ki,double kd){
  kp=kp;
  ki=ki;
  kd=kd;
}
