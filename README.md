# RocketFlightController
I decided to design a custom flight controller because i wanted to learn more about custom PCBs and overall sensors and microcontrollers workflow, while trying to master soldering along the way :p

# Components
- **ESP32-WROOM-32E** - i used this model in Kicad, it is a great microcontroller which can be accessed remotely because of its wifi/bluetooth modules.
- **BMP280** - pressure sensor which can be used to approximate height which is crucial for drones, rockets and etc.
- **MPU-6050** - simple accelerometer which also has a gyroscope used to determine tilt/angle
I also decided to make spaces or pins for 4 servos, as i planned to allocate 2 of them for TVC(thrust vector control), and other 2 for an active recovery system.

And there is a bunch of capacitors, resistors, some buttons which are all used on a single custom PCB, all parts of which i will list in BOM list in the end.

### The entire board can be powered from a standard 5 V battery pack or USB power bank. I did not include it in the BOM because it is a common off-the-shelf item that users can easily purchase separately.
## Electronics and PCB

| Schematic | PCB Layout | 3D Render |
|----------|------------|-----------|
| <img width="820" height="790" alt="Schematic" src="https://github.com/user-attachments/assets/36ee5b82-a565-44b6-810b-d0dc6b299e04" /> | <img width="829" height="790" alt="PCB layout" src="https://github.com/user-attachments/assets/a67f90a4-6002-4b17-8b16-7a8ff7722644" /> | <img width="946" height="752" alt="PCB 3D render" src="https://github.com/user-attachments/assets/045a8e83-6705-43f9-9edb-bf12653fbb98" /> |

All parts will be hand soldered by me. PCB contains smd and tht components:
<img src="./assets/pcbrender (1).png" alt="PCB render" width="2000">

## BOM List

| Name | Purpose | Qty | Total (USD) | Link | Distributor |
|---|---|---:|---:|---|---|
|Custom PCB|Plate which will store and connect all components|5|2|--|JLCPCB|
| 03EC0575 (C2831775) | Large servo rail capacitor to reduce voltage dips during servo movement. | 10 | 0.47 | [Link](https://www.lcsc.com/product-detail/C2831775.html) | LCSC |
| DB128L-5.08-2P-GN-S (C395868) | Power input terminals for logic and servo power connections. | 5 | 0.99 | [Link](https://www.lcsc.com/product-detail/C395868.html) | LCSC |
| 2.54-1*3P (C49257) | 3-pin servo headers for servo power, ground, and PWM signal. | 50 | 1.06 | [Link](https://www.lcsc.com/product-detail/C49257.html) | LCSC |
| 2.54-1x6P (C37208) | UART programming header for flashing and debugging the ESP32. | 20 | 0.88 | [Link](https://www.lcsc.com/product-detail/C37208.html) | LCSC |
| 1206B106K500NT (C303950) | Bulk/decoupling capacitors for the stable 3.3 V regulator input/output and logic power. | 5 | 0.43 | [Link](https://www.lcsc.com/product-detail/C303950.html) | LCSC |
| 0805W8F4701T5E (C17673) | I2C pull-up resistors for SDA and SCL lines. | 100 | 0.22 | [Link](https://www.lcsc.com/product-detail/C17673.html) | LCSC |
| 0805W8F1002T5E (C17414) | Pull-up/pull-down resistors for ESP32 boot/reset and sensor address configuration. | 100 | 0.30 | [Link](https://www.lcsc.com/product-detail/C17414.html) | LCSC |
| ESP32-WROOM-32E-N8 (C701342) | Main microcontroller module for sensor reading, servo control, and wireless debugging. | 1 | 4.42 | [Link](https://www.lcsc.com/product-detail/C701342.html) | LCSC |
| MPU-6050 (C24112) | IMU sensor for acceleration and angular velocity measurement during rocket flight. | 1 | 9.99 | [Link](https://www.lcsc.com/product-detail/C24112.html) | LCSC |
| BMP280 (C83291) | Barometric pressure sensor for altitude and pressure measurement. | 1 | 6.03 | [Link](https://www.lcsc.com/product-detail/C83291.html) | LCSC |
| CC0805KRX7R9BB104 (C49678) | Decoupling capacitors for the ESP32, MPU6050, BMP280, and power rail noise filtering. | 100 | 0.53 | [Link](https://www.lcsc.com/product-detail/C49678.html) | LCSC |
| AMS1117-3.3 (C6186) | 3.3 V voltage regulator for the ESP32 and sensors. | 5 | 1.07 | [Link](https://www.lcsc.com/product-detail/C6186.html) | LCSC |
| TL1105AF160Q (C273465) | Reset and boot tactile buttons for programming and manual restart. | 5 | 0.48 | [Link](https://www.lcsc.com/product-detail/C273465.html) | LCSC |




