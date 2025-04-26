# 🌈 RGB_String_Lights

**ESP32-based IoT Controller for Addressable RGB LED Lights**  
Control your WS2812FX lights remotely via Sinric Pro, Wi-Fi, and enable OTA firmware updates!

![Platform](https://img.shields.io/badge/platform-ESP32-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Language](https://img.shields.io/badge/language-C++-brightgreen.svg)

---

## ✨ Overview

RGB_String_Lights is an open-source ESP32 project to wirelessly control addressable RGB LED strips using **Sinric Pro** cloud services.  
It features remote light control, brightness and speed adjustment, OTA firmware updates, and customizable "Round Robin" light effect cycling.

---

## 🚀 Features

- ✅ Alexa and Google Assistant integration via Sinric Pro
- ✅ 20+ beautiful lighting effects
- ✅ Brightness and speed adjustment
- ✅ Color selection (White mode, etc.)
- ✅ Manual button press handling
- ✅ Round Robin mode: automatic cycling through effects
- ✅ OTA (Over-The-Air) firmware updates
- ✅ Serial debugging support

---

## 🛠️ Hardware Required

- ESP32 Development Board
- WS2812B / SK6812 / compatible addressable RGB LED strip
- 5V Power Supply (as per your strip's requirement)
- Push Button (for manual control)
- (Optional) Logic level shifter (3.3V to 5V)

---

## 🧰 Software Setup

### 1. Install Required Libraries

Make sure to install the following libraries via Arduino IDE Library Manager or PlatformIO:

- [ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer)
- [AsyncTCP](https://github.com/me-no-dev/AsyncTCP)
- [SinricPro](https://github.com/sinricpro/esp8266-esp32-sdk)
- [WS2812FX](https://github.com/kitesurfer1404/WS2812FX)

---

### 2. Setup Secret Keys

- Copy the file `SecretKeysTemplate.h` and **rename** it to `SecretKeys.h`.
- Fill in your **Sinric Pro credentials** and **Wi-Fi details** in `SecretKeys.h`:

```cpp
// Sinric Pro Secret Keys
#define SECRET_APP_KEY      "your_app_key_here"
#define SECRET_APP_SECRET   "your_app_secret_here"
#define SECRET_DEVICE_ID    "your_device_id_here"

// Wi-Fi Secret Keys
#define SECRET_SSID         "your_wifi_ssid_here"
#define SECRET_PASSWORD     "your_wifi_password_here"
