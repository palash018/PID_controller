#include "PID.h"
#include <iostream>
#include <chrono>
#include <cmath>    
PID::PID(double kp,double ki,double kd){
  this->kp=kp;
  this->ki=ki;
  this->kd=kd;
  this->curr_time=get_time();
  this->prev_time=get_time();
  this->prev_error=0;
  this->error_sum=0;
}

double PID::compute(double curr_value,double expected_value){
  double curr_error=expected_value-curr_value;
  prev_time=curr_time;
  curr_time=get_time();
  unsigned int time_diff=curr_time-prev_time;
  error_sum+=curr_error*(time_diff);
  double diff_error=curr_error-prev_error;
  prev_error=curr_error;
  double result=kp*curr_error+ki*error_sum+kd*diff_error/time_diff;
  if (std::isinf(result)) {
        return 0;
    } else {
        return result;
    }
}
unsigned long PID::get_time(){
    auto currentTime = std::chrono::system_clock::now();
    auto currentTimeMs = std::chrono::time_point_cast<std::chrono::milliseconds>(currentTime);
    auto epoch = currentTimeMs.time_since_epoch();
    unsigned long currentTimeMillisec = std::chrono::duration_cast<std::chrono::milliseconds>(epoch).count();
    return currentTimeMillisec;
}
void PID::reset(double kp,double ki,double kd){
  this->kp=kp;
  this->ki=ki;
  this->kd=kd;
}