# Obstacle Avoidance Robot using Arduino and IR Sensors 🤖

This project demonstrates the design and implementation of an **intelligent mobile robot** that can detect and avoid obstacles using **IR sensors**, controlled by an **Arduino** and an **L298N motor driver**.

The robot is capable of:
- Moving forward when the path is clear
- Stopping immediately when an obstacle is detected
- Turning away from obstacles detected on one side
- Reversing safely when obstacles are detected on both sensors

---

## 🔧 Components Used

- Arduino UNO
- L298N Motor Driver
- DC Gear Motors (2)
- IR Sensors (2)  
  - Left IR Sensor  
  - Front IR Sensor
- Battery (7–12V)
- Robot Chassis
- Jumper Wires

---

## ⚙️ Working Principle

1. The IR sensors continuously monitor obstacles around the robot.
2. Sensor data is sent to the Arduino for processing.
3. Based on sensor inputs:
   - The robot moves forward if no obstacle is detected.
   - Stops immediately when an obstacle is detected.
   - Turns left or right if an obstacle is detected on only one sensor.
   - Reverses for 3 seconds if obstacles are detected on both sensors.
4. Motor speed is controlled using **PWM (Pulse Width Modulation)** for smooth and safe movement.

---

## 🧠 Decision Logic

| Left Sensor | Front Sensor | Robot Action |
|------------|-------------|--------------|
| No Obstacle | No Obstacle | Move Forward |
| Obstacle | No Obstacle | Stop → Turn Right |
| No Obstacle | Obstacle | Stop → Turn Left |
| Obstacle | Obstacle | Stop → Reverse (3 sec) |

---

## 🔌 Circuit Diagram

The circuit consists of:
- IR sensors connected to Arduino analog pins (A0, A1)
- L298N motor driver connected to Arduino digital pins
- Motors connected to the output pins of L298N
- Battery powering the motor driver
- Common ground between Arduino and motor driver


---

## 💻 Code

The Arduino program:
- Reads IR sensor values
- Applies obstacle detection logic
- Controls motor direction and speed using PWM
- Ensures immediate stopping and safe turning

👉 The full source code is available in this repository.

---

## 🧪 Observations

- The robot moves smoothly in obstacle-free conditions.
- Immediate stopping prevents collisions.
- Timed turning avoids the robot getting stuck near obstacles.
- PWM control provides stable and slow movement.

---

## 🚀 Applications

- Obstacle avoiding robots
- Line following and wall following robots
- Indoor autonomous navigation
- Educational robotics projects
- Beginner robotics learning

---

## ⚠️ Precautions

- Ensure common ground between Arduino and L298N.
- Use an external battery for motors (do not power motors from Arduino).
- Adjust IR sensor threshold values based on environment.
- Ensure motors receive sufficient PWM to avoid stalling.

---



## 👨‍💻 Author

**E.Abishek**  
Mechatronics And Automation Engineering  
---

⭐ If you like this project, don’t forget to star the repository!
