
# 🚑 Arduino Infusion Pump  

An open-source Arduino-based infusion pump for precise fluid delivery, integrating a **stepper motor**, **LCD display**, and **flow sensor**. Designed for biomedical applications, research, and educational purposes.  

---

## 📷 Project Overview  

![IMG_8361](https://github.com/user-attachments/assets/48783540-c604-41ca-bb96-330f708dba96)


🔹 **Microcontroller**: Arduino Uno  
🔹 **Motor**: 28BYJ-48 Stepper Motor + ULN2003 Driver  
🔹 **Display**: 16x2 LCD with I2C  
🔹 **Flow Monitoring**: Integrated flow sensor  
🔹 **User Control**: Push buttons for different infusion rates  
🔹 **Safety Alerts**: LED indicators and buzzer warnings  

---

## 📽️ Project Demo  

https://github.com/user-attachments/assets/7e004ecd-3364-460f-81a2-71c9764a257d


---

## 🛠️ Features  

✅ **Precise Fluid Control** – Stepper motor ensures accurate flow  
✅ **Real-time Flow Monitoring** – Displays flow rate on LCD  
✅ **User-friendly Interface** – Simple push-button operation  
✅ **Safety Alerts** – LED and buzzer warn of excessive flow  
✅ **Customizable Infusion Rates** – Adjustable speed settings  

---

## 🔩 Hardware & Components  

| Component         | Quantity | Description |
|------------------|---------|------------|
| Arduino Uno      | 1       | Microcontroller |
| 28BYJ-48 Stepper Motor | 1 | Infusion mechanism |
| ULN2003 Driver   | 1       | Motor controller |
| LCD 16x2 (I2C)   | 1       | Display module |
| Flow Sensor      | 1       | Flow monitoring |
| Push Buttons     | 4       | Infusion control |
| LEDs & Buzzer    | 3+1     | Visual & audio alerts |
| Power Supply     | 1       | 9V or USB |

📌 **3D Printed Parts**:  
- Infusion Pump Casing  
- Motor Mount  
- Tubing Holders  

![df0fb89283f0d13eda466152fc568ad7](https://github.com/user-attachments/assets/77fe1b9e-8413-4d7d-9731-567f2c44fa22)
![226a58613d376fa4b78dc78184a30f6c](https://github.com/user-attachments/assets/830a8e73-6864-48cf-8ae6-7e384dbf11cb)
![97c81709895de6bf37b88f17f79a40a1](https://github.com/user-attachments/assets/f73e4201-80be-4a38-8440-1d1437cd53eb)
![8ad86758e3ed1c3a325a0762bb7a03c6](https://github.com/user-attachments/assets/20515fba-fa86-4ba8-970d-d0d453ad47a5)


---

## 🔌 Circuit Diagram  

![Circuit Design 2](https://github.com/user-attachments/assets/0a020810-ebf5-48b9-97df-891d326d2dcd)

---

## 🚀 How to Set Up  

### **1️⃣ Hardware Setup**  
- Connect components as per the **circuit diagram**  
- Mount the **stepper motor and tubing** securely  
- Ensure **proper power supply**  

### **2️⃣ Software Installation**  
- Install **Arduino IDE** & required libraries:  
  ```bash
  Install Stepper.h
  Install LiquidCrystal_I2C.h

### **3️⃣ Operating the Pump**  
- **Press Button 1** → 1-second infusion  
- **Press Button 2** → 2-second infusion  
- **Press Button 3** → Reverse rotation  
- **Press Button 4** → Reset  

## 🔗 Contact & Social Media  

📩 **Email**: anas.bayoumi05@eng-st.cu.edu.eg
🌐 **LinkedIn**: [Connect with me](https://www.linkedin.com/in/anas-mohamed-716959313/)  
📱 **WhatsApp**: [201143896165](https://wa.me/+201143896165)  
