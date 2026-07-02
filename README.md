🚗 Event-Triggered Output Feedback MPC for Path Following of Autonomous Vehicles

Table of Contents

- "Overview" 
- "Objective" 
- "Technologies Used"
- "Hardware Components" 
- "Features" (#features)
- "Working" (#working)
- "Circuit Diagram" (#circuit-diagram)
- "Project Images" (#project-images)
- "Results" (#results)
- "Project Files" (#project-files)
- "Applications" (#applications)
- "Future Scope" (#future-scope)
- "Author" (#author)

---

Overview
This is my B.Tech Major Project developed using Raspberry Pi Pico and embedded system components. The system implements an Event-Triggered Output Feedback Model Predictive Control (MPC) mechanism for autonomous vehicle path following and obstacle detection.
The project aims to improve efficiency by reducing unnecessary controller updates while maintaining accurate path tracking.

---

Objective
- To design an autonomous vehicle path-following system.
- To reduce computational load using event-triggered control.
- To improve obstacle detection and vehicle safety.
- To enhance embedded control system performance.

---

Technologies Used
- Embedded Systems
- Raspberry Pi Pico
- MicroPython / Embedded C
- Sensor Integration
- Model Predictive Control (MPC)

---

Hardware Components
- Raspberry Pi Pico
- Ultrasonic Sensor (HC-SR04)
- Line Following Sensor
- OLED Display
- Motor Driver Circuit
- DC Motors
- Alarm/Buzzer
- Power Supply Unit

---

Features
- Autonomous path following
- Obstacle detection
- Real-time monitoring
- OLED display output
- Event-triggered control mechanism
- Reduced computational complexity

---

Working

The vehicle follows a predefined path using line sensors. The ultrasonic sensor continuously detects obstacles in front of the vehicle.
When an event occurs (path deviation or obstacle detection), the controller updates the system and adjusts the motor control accordingly.
The OLED display shows live status, and the alarm warns when obstacles are detected.

---

Results

- Successful path tracking achieved
- Effective obstacle detection
- Reduced unnecessary control updates
- Improved vehicle efficiency

---

Project Files

Major_Project/
├── README.md
├── Documentation/
├── PPT/
├── Source_Code/
├── Circuit_Diagram/
├── Images/

---
Author

K. Saikrishna
B.Tech - Electronics and Communication Engineering
