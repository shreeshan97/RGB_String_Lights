# RGB_String_Lights

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

---

## 🧰 Software Setup

### 1. Install Required Libraries

Make sure to install the following libraries via Arduino IDE Library Manager or PlatformIO:

- [SinricPro](https://github.com/sinricpro/esp8266-esp32-sdk)
- [WS2812FX](https://github.com/kitesurfer1404/WS2812FX)

---

### 2. Configure Secret Keys

- Locate the file `SecretKeysTemplate.h` in the project directory.
- **Rename** it to `SecretKeys.h`.
- Open `SecretKeys.h` and fill in your **Sinric Pro credentials** and **Wi-Fi details**:

```cpp
// Sinric Pro Secret Keys
#define SECRET_APP_KEY      "your_app_key_here"
#define SECRET_APP_SECRET   "your_app_secret_here"
#define SECRET_DEVICE_ID    "your_device_id_here"

// Wi-Fi Secret Keys
#define SECRET_SSID         "your_wifi_ssid_here"
#define SECRET_PASSWORD     "your_wifi_password_here"
```

> ⚠️ **Important:** Never expose your real secret keys publicly.  
> ✅ Add `SecretKeys.h` to your `.gitignore` if you push this project to GitHub:

```gitignore
# Ignore secrets
SecretKeys.h
```

---

### 3. Upload the Firmware

- Set up the correct board and port in Arduino IDE.
- Flash the firmware to your ESP32.
- Open the Serial Monitor to see connection logs and OTA readiness.

---

## 📲 Usage Instructions

- The ESP32 connects automatically to your Wi-Fi network on boot.
- It registers itself with the Sinric Pro cloud.
- You can now control the lights via:
  - Sinric Pro Mobile App
  - Alexa voice commands ("Set [Device Name] mode to Rainbow")
  - Google Assistant
- Use the physical button to cycle through effects manually (short press action).

---

## 🌟 Supported Lighting Modes

| Mode Name           | Description                   |
|---------------------|-------------------------------|
| Off                 | Turn off LEDs                 |
| White               | Solid white color             |
| Maximum_Brightness  | Full brightness               |
| Medium_Brightness   | Medium brightness             |
| Minimum_Brightness  | Dimmed LEDs                   |
| Rainbow             | Rainbow flowing animation     |
| Rainbow_Cycle       | Rainbow cycle around strip    |
| Theatre             | Theater chasing lights        |
| Twinkle             | Random sparkle effect         |
| Blink               | Simple blinking               |
| Colour_Sweep        | Smooth color sweep            |
| Ambulance           | Emergency flashing            |
| Firework            | Firework sparkle              |
| Merry_Christmas     | Christmas-themed colors       |
| Halloween           | Halloween colors              |
| Circus              | Vibrant rotating colors       |
| Random              | Random flicker                |
| Running             | Running pixel                 |
| Multi_Dynamic       | Multicolor dynamic            |
| Round_Robin         | Auto-cycling effects          |

---

## 📡 OTA (Over-the-Air) Updates

- ArduinoOTA is automatically initialized.
- You can upload firmware updates over Wi-Fi after the first flash.
- Open Arduino IDE ➔ Select Network Port ➔ Upload sketch wirelessly.

---

## 🧠 Code Structure

| File                  	| Purpose                             			   |
|---------------------------|--------------------------------------------------|
| `RGBController.h` 		| Handle Sinric Pro interactions      			   |
| `RGBControllerInit.h/cpp` | Initialization helpers                           |
| `Defaults.h`          	| LED strip, button, debounce timing constants     |
| `SecretKeysTemplate.h`	| Template for user-provided credentials           |
| `SecretKeys.h`        	| (User-generated) Secret keys for cloud and Wi-Fi |
| `RGB_String_Lights.ino`	| Core logic (setup, loop, effect handling)        |

---

## 🛠️ Sinric Pro Integration

To enable voice control and remote management of your RGB lights, we'll create a custom device template on Sinric Pro.

### 1. Import the Device Template

For convenience, you can import the device template directly from a text file:

- **Download** the device template file: `RGBControllerTemplate.txt`.
- **Log in** to your [Sinric Pro dashboard](https://sinric.pro/).
- Navigate to **Device Templates** and click on **Add Device Template**.
- **Paste** the contents of `RGBControllerTemplate.txt` into the template editor.
- Click **Save** to store your new device template.

### 2. Create a Device from the Template

- Navigate to **Devices** and click on **Add Device**.
- Select the `RGBController` template.
- Fill in the device details and save.
- Click on **Code Generator** to generate the code for your ESP32 project.

---

## 📜 License

This project is licensed under the [MIT License](LICENSE).

---

## 🙌 Credits

- Thanks to [Sinric Pro](https://sinric.pro/) for simplifying smart home integration.
- Thanks to [WS2812FX](https://github.com/kitesurfer1404/WS2812FX) for the amazing LED effects library.
- Inspired by the open-source maker community!
