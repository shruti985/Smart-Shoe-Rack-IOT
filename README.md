# 👟 Smart Shoe Rack for Drying Shoes Using Sensors (IoT)

An IoT-based **Smart Shoe Rack** that automatically detects wet shoes and dries them using a fan or heater based on real-time sensor data. The system ensures hygiene, prevents bad odor, and protects delicate shoe materials like leather. It also provides remote monitoring and control using the **Blynk mobile application**.

---

## 📌 Project Overview

In hostels and homes, especially during the rainy season, drying shoes properly becomes difficult due to lack of sunlight and ventilation. Wet shoes lead to bad odor, bacterial growth, and reduced shoe life.

This project solves the problem by:
- Detecting moisture and humidity in shoes
- Automatically starting a fan or heater
- Providing IoT-based monitoring and alerts
- Conserving energy by auto shut-off once shoes are dry

---

## 🎯 Objectives

- Automatically detect wet shoes
- Dry shoes efficiently using fan/heater
- Provide real-time monitoring via smartphone
- Reduce manual effort and energy consumption

---

## 🛠️ Technologies Used

- **Microcontroller:** ESP32  
- **Sensors:**  
  - DHT11 / DHT22 (Temperature & Humidity)  
  - Moisture Sensor (YL-69 / Capacitive)  
- **Actuators:**  
  - Fan   
  - Buzzer  
  - LEDs  
- **IoT Platform:** Blynk App  
- **Simulation Tool:** Wokwi  

---

## ⚙️ System Features

- ✅ Automatic drying based on humidity level  
- ✅ Manual & Automatic modes  
- ✅ Material-sensitive drying (heater disabled for leather shoes)  
- ✅ Real-time temperature & humidity monitoring  
- ✅ Mobile notifications via Blynk  
- ✅ Energy-efficient auto shut-off  
- ✅ Buzzer alerts for very wet shoes  

---

## 📊 Working Principle

1. **Sensor Activation:**  
   Sensors detect moisture, temperature, and humidity inside the rack.

2. **Data Processing:**  
   ESP32 compares sensor values with predefined thresholds.

3. **Drying Process:**  
   - Fan turns ON if humidity is high  
   - Heater activates only for non-leather shoes  

4. **IoT Monitoring:**  
   Data is sent to the Blynk app for live monitoring and control.

5. **Auto Shut-Off:**  
   System turns OFF automatically when shoes are dry.

---

## 📱 IoT Integration (Blynk App)

- Monitor temperature & humidity
- Turn fan/heater ON or OFF manually
- Switch between automatic and manual modes
- Receive notifications when shoes are dry

---

## 🧩 Hardware Components

| Component | Description |
|---------|-------------|
| ESP32 | Main controller with built-in Wi-Fi |
| DHT11/DHT22 | Measures temperature & humidity |
| Moisture Sensor | Detects wetness in shoes |
| Relay Module | Controls fan and heater |
| Fan | Provides airflow for drying |
| Buzzer | Alerts when shoes are very wet |
| LEDs | Indicates drying status |

---

## 🧪 Experimental Results

- Accurate humidity detection using DHT sensors
- Average response time: **~9 seconds**
- Stable IoT communication with Blynk
- Reliable automatic & manual control modes

---

## 🚀 Future Enhancements

- 🔍 Automatic shoe material detection (RFID / sensors)
- 📲 Dedicated mobile application
- 🦠 UV sterilization for bacteria & odor removal
- 📈 Usage history and smart drying prediction
- ☁️ Cloud data storage & analytics

---

## 👥 Team Members

- **Palak Kumari** – Group Leader  
- **Shruti Jain**  
- **Jagrit Aswal**  
- **Bharatee Yadav**

---

## 📚 References

- IoT-Based Shoe Dryer Monitoring and Control System  
- Design and Fabrication of Shoe Rack with Dryer Function  
- IoT-Based Automatic Shoe Box using UV Light  

---

## 📄 License

This project is developed for academic purposes under **IoT Programming (CSPC 209)**.

---

⭐ If you like this project, feel free to star the repository!
