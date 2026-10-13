# MediBot – Smart Medicine Vending Machine

MediBot is a low-cost, portable medicine dispenser that reminds a person when to take their medicine, dispenses it, and is designed to alert a caregiver when a dose is missed.

**Track:** Medical Devices and Equipments · **Problem statement:** a device that automatically dispenses medication and tracks adherence to medication schedules.

## Demo
- Demo video: <https://youtu.be/l-vJ_oNfhIQ>
- Product images: <https://drive.google.com/file/d/1zvC6wDMLBF7CzOdef0DxC-iBk70Lsm2O/view?usp=drivesdk>

## Achievements
- Finalist, BCCI & Ideathon 2023
- HACK-O-MED 2023
- FOSET 2023

## Why it matters
Elderly people, people with dementia, and people with limited mobility often miss doses or find it hard to reach a pharmacy. A machine that keeps the schedule, reminds the patient and dispenses the right medicine helps prevent missed doses and medication errors. It can also support rural areas, where clinics can follow a patient's status remotely.

## Features
- Real-time clock (RTC) keeps the medication schedule on time
- Adjustable alarm time with on/off switch
- Visual prompt on a 20x4 LCD and audio alert from a buzzer
- Touch-triggered servo that opens the medicine compartment
- Designed to alert a caregiver or family member if a dose is missed
- Easy to use, with large inputs and clear instructions

See [`docs/requirements.md`](docs/requirements.md) for the full requirement list.

## What is in this repository
| Part | Status |
|------|--------|
| RTC alarm clock with LCD display and buzzer (`firmware/Code_RTC`) | Included |
| Touch sensor with servo-controlled dispenser door (`firmware/Code_Touch`) | Included |
| GSM SMS alerts, ESP8266/IoT mobile app, keypad and motor driver | Part of the design (see [system overview](docs/images/system-overview.png)), code not in this repository |

## Hardware
| Component | Role |
|-----------|------|
| Arduino Nano (ATmega328P) | Main controller |
| NodeMCU ESP8266 | Sends the daily medicine update to the mobile app (design) |
| DS1307 RTC module | Keeps real time |
| 20x4 LCD (parallel) | Shows time, date, alarm and prompts |
| Buzzer / speaker | Audio alert |
| Servo motor and DC motors with motor driver | Open and dispense from the compartment |
| Touch sensor | Triggers dispensing |
| Push buttons | Set alarm hour and minute, alarm on/off |
| GSM module | SMS alerts to a caregiver (design) |
| Power source | Battery supply |

### Pin map (from the code)
**`Code_RTC`**

| Pin | Use |
|-----|-----|
| 12, 11, 10, 9, 8, 7 | LCD (RS, E, D4–D7) |
| A4 / A5 | RTC (I²C, standard Wire pins) |
| 4 | Alarm on/off switch |
| 3 | Increase alarm hour |
| 2 | Increase alarm minute |
| 6 | Enables the buzzer at alarm time |
| 5 | Buzzer |

**`Code_Touch`**

| Pin | Use |
|-----|-----|
| 2 | Touch sensor input |
| 4 | Indicator LED |
| 9 | Servo signal |

## Software
Arduino IDE with these libraries (install from the Library Manager):
- `Time` (TimeLib)
- `DS1307RTC`
- `LiquidCrystal` (built in)
- `Servo` (built in)

## Getting started
1. Clone this repository.
2. Open `firmware/Code_RTC/Code_RTC.ino` or `firmware/Code_Touch/Code_Touch.ino` in the Arduino IDE.
3. Select **Arduino Nano** (or your board) and the correct port, then upload.
4. If the RTC reports it is stopped, set its time first with the `SetTime` example from the DS1307RTC library.

## How it works
![Flow chart](docs/images/flowchart.png)

The controller keeps the schedule with the RTC. At the set time it shows a prompt and sounds the buzzer. After the medicine is taken the compartment closes. If there is no response, the design alerts the nearest contact.

![System overview](docs/images/system-overview.png)

## Known limitations
This is a competition prototype. Things to improve:
- In `Code_RTC`, the alarm check compares against `tm` before the RTC is read in the same loop, and a local `tm` hides the global one, so the alarm comparison may not use the current time. Reading the RTC at the top of `loop()` into the global `tm` fixes it.
- The alarm time is not saved, so it resets when power is lost, and the display does not pad minutes with a leading zero.
- Dose-taken tracking, missed-dose SMS, the mobile app and prescription verification are design goals and not yet implemented in this code.
- Real medicine dispensing needs extra safety features (locking, authentication, dose verification) before any real use. Do not use this prototype for actual medication.

## Future scope
- Companion mobile app with schedules, refill reminders and dose history
- Remote monitoring for caregivers and doctors over Wi-Fi or cellular
- Prescription verification with barcodes or QR codes
- Authentication and tamper-proof locking

## Documents
- [Round 1 presentation](docs/Hackomed_Round_1_Presentation.pptx)
- [Requirements](docs/requirements.md)

## Team
Team Robusta 2.0 (Team ID R2_HMED_C51). Add your name and teammates here.

## License
MIT – see [LICENSE](LICENSE).
