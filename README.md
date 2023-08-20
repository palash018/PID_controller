# PID Controller

This repository contains the implementation of a PID controller in C++. The PID controller is a feedback control algorithm widely used in control systems to regulate a process. It calculates an output based on the error between the desired setpoint and the current value, utilizing proportional, integral, and derivative control actions.

## Usage

To use the PID controller, follow these steps:

1. Include the necessary header file in your project:

   ```c++
   #include "PID.h"
   ```

2. Create an instance of the PID controller by providing the appropriate coefficients: kp (proportional gain), ki (integral gain), and kd (derivative gain):

   ```c++
   PID pidController(kp, ki, kd);
   ```

3. Use the `compute` method to calculate the control output based on the current value and the desired setpoint:

   ```c++
   double controlOutput = pidController.compute(currValue, desiredValue);
   ```

   - `currValue` is the current value of the process being controlled.
   - `desiredValue` is the desired setpoint.

4. (Optional) Reset the PID controller coefficients to new values using the `reset` method:

   ```c++
   pidController.reset(newKp, newKi, newKd);
   ```

   - `newKp`, `newKi`, and `newKd` are the new values for the proportional, integral
