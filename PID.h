#ifndef PID_H
#define PID_H
class PID{
  public:
      PID(double,double,double);
      double compute(double,double);
      void reset(double,double,double);
  private:
    double kp;
    double ki;
    double kd;
    unsigned long curr_time;
    unsigned long prev_time;
    double error_sum;
    double prev_error;
};
#endif