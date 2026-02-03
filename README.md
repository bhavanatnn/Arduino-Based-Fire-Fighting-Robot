# Arduino Based Firefighting Robot 🔥🤖

## Description
This project implements a basic firefighting robot using Arduino.  
The robot detects fire using a flame sensor and automatically moves toward the fire source. Once the fire is detected, a water pump is activated to extinguish the fire.  
This project is designed for beginners in Arduino, robotics, and embedded systems.

---

## Features
- Fire detection using flame sensor  
- Automatic robot movement  
- Water pump activation to extinguish fire  
- Simple and low-cost design  
- Beginner-friendly project  

---

## Components Required
- Arduino Uno  
- Flame Sensor  
- L298N Motor Driver Module  
- DC Motors  
- Robot Chassis  
- Water Pump  
- Relay Module  
- Water Tank  
- Jumper Wires  
- Battery (9V / 12V)  

---

## Circuit Connections
- Flame sensor output connected to Arduino digital pin  
- Motor driver connected to Arduino motor control pins  
- DC motors connected to motor driver  
- Relay module connected to Arduino  
- Water pump connected through relay  
- Battery used for motor and pump power  

![ckt connection](https://github.com/user-attachments/assets/44075c24-fb39-4927-bd19-c679b25ab0b5)

---

## Working Principle
1. Flame sensor continuously monitors the surroundings  
2. If fire is detected, the sensor sends a signal to Arduino  
3. Arduino controls the motors to move toward the fire  
4. When the fire is close, Arduino activates the relay  
5. Relay turns ON the water pump  
6. Water is sprayed to extinguish the fire  

---

## Algorithm
1. Start the system  
2. Read flame sensor values  
3. If no fire is detected, robot moves forward  
4. If fire is detected, stop movement  
5. Turn ON the water pump  
6. Spray water for few seconds  
7. Turn OFF the pump  
8. Stop the robot  

---

## Arduino Code
- Code written using Arduino IDE  
- Flame sensor used as digital input  
- Motor driver used for motor control  
- Relay used for pump control  

-> OUTPUT of the project

![fire figiting ROBOT](https://github.com/user-attachments/assets/bc6845cd-3132-44c0-925c-c28d88472bc6)
![final output](https://github.com/user-attachments/assets/c23b0d0d-b180-49a5-82a9-3e7ba78017d4)


---

## How to Upload Code
1. Install Arduino IDE  
2. Connect Arduino Uno to PC using USB cable  
3. Select correct Board and COM Port  
4. Open the project `.ino` file  
5. Click Upload  

---

## Applications
- Fire detection systems  
- Industrial safety  
- Educational robotics projects  
- Embedded systems learning  

---

## Future Enhancements
- Smoke sensor integration  
- Obstacle avoidance using ultrasonic sensor  
- Wireless control using Bluetooth or WiFi  
- Camera module for live monitoring  

---

## Author
**Bhavana TN**
  

---

## License
This project is open-source and free to use for educational purposes.
