# Biomimetic Hand using InMoov, MG996R Servos & Arduino Uno

This project implements a low-cost **biomimetic robotic hand** that replicates human finger movements using **surface EMG (Electromyography) signals**. The system is based on an **InMoov 3D printed hand**, actuated by **MG996R servo motors**, and controlled by an **Arduino Uno**. Muscle activity obtained from EMG sensors is used to detect user intent and map them to hand gestures such as grasping, pinching, and finger flexion.

***

### Features
- **3D Printed Mechanism**: Utilizes InMoov hand designs for realistic anthropomorphic structure.  
- **Actuation**: Controlled by 5 MG996R servo motors for finger flexion and grip.  
- **Control Board**: Arduino Uno as the controller for handling EMG signals and servo actuation.  
- **Sensing**: EMG sensors detect muscle contractions and transmit signals for processing.  
- **Gesture Control**: Enables different gesture sets (e.g., open hand, fist).  
- **Low-Cost & Open Source**: Made from readily available 3D models and components.  

***

### Hardware Components
- Arduino Uno   
- MG996R Servo Motors 5 
- EMG Sensors (MyoWare Muscle Sensor)
- 3D Printed **InMoov Hand** components  
- Power supply (separate supply for servos, 5–6V, 2A+)  
- Breadboard, wires, and connectors  

***

### Software Requirements
- Arduino IDE (2.0+)  
- Servo library for Arduino (included by default)  

***

### Wiring & Connections
- Each MG996R servo is connected to Arduino PWM pins (e.g., D3–D9).  
- Servo Vcc power line connected to external 5–6V power supply.  
- Common ground between Arduino and power supply is **mandatory**.  
- EMG sensor output connected to Arduino analog input pin (e.g., A0).  
- Additional EMG sensors can control multiple fingers for advanced mapping.  

***

### Basic Arduino Control Flow
1. Read EMG signal from the sensor.  
2. Apply threshold filtering to detect muscle activation.  
3. Map activation state to a predefined finger/gesture motion.  
4. Generate PWM signals to control MG996R servos.  

***

### Applications
- Prosthetic research  
- Rehabilitation robotics  
- Gesture-controlled robotic hand  
- Educational biomimicry & biorobotics projects  

***

### Future Improvements
- Add multiple EMG channels for individual finger control.  
- Implement adaptive filtering for more robust EMG signal interpretation.  
- Integrate with ROS2 for advanced robotic frameworks.  
- Explore tendon-driven actuation instead of direct servo linkage for smoother motion.  
