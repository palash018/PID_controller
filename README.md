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

## Compilation

To compile the PID controller code, you can follow these steps:

1. Create a new C++ source file in your preferred editor and include the required header file:

   ```c++
   #include "PID.h"
   ```

2. Implement the main function and define the PID controller parameters, current value, and desired value:

   ```c++
   int main() {
       double kp = 0.5;
       double ki = 0.2;
       double kd = 0.1;

       double currValue = 5.0;
       double desiredValue = 10.0;

       // Create an instance of the PID controller
       PID pidController(kp, ki, kd);

       // Compute the control output
       double controlOutput = pidController.compute(currValue, desiredValue);

       // Print the control output
       std::cout << "Control Output: " << controlOutput << std::endl;

       return 0;
   }
   ```

3. Save the source file with a `.cpp` extension, for example, `main.cpp`.

4. Open your terminal or command prompt and navigate to the directory where you saved the source file.

5. Compile the code using a C++ compiler, such as `g++`:

   ```shell
   g++ main.cpp PID.cpp -o pid_controller
   ```

   This command compiles the main file along with
