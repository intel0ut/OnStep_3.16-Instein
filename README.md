# OnStep-Instein
This repository is intended for owners of OnStep boxes made by Instein.eu and contain a copy of the custom OnStep 3.16o for ESP32 source code used by the box. I don't own any part of this code. Original source code by Howard Hutton (https://github.com/hjd1964/OnStep) with modifications by Instein.eu

/*
 * Title       OnStep
 * by          Howard Dutton
 *
 * Copyright (C) 2012 to 2020 Howard Dutton
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Description:
 *   Full featured stepper motor telescope microcontroller for Equatorial and
 *   Alt-Azimuth mounts, with the LX200 derived command set.
 *
 * Author: Howard Dutton
 *   http://www.stellarjourney.com
 *   hjd1964@gmail.com
 * Moded by Instein
 *   http://www.instein.eu
 *   instein@instein.eu
 * Revision history, and newer versions:
 *   See GitHub: https://github.com/hjd1964/OnStep / http://www.instein.eu/index.php?route=product/category&path=25
 *
 * Documentation:
 *   https://groups.io/g/onstep/wiki/home / http://www.instein.eu/index.php?route=product/category&path=25
 *
 * Discussion, Questions, ...etc
 *   https://groups.io/g/onstep
 */

//***************************************************************************************************************************************
// -THIS FIRMWARE IS ONLY VALID FOR INSTEIN ESP32 DRIVES PURCHASED FROM SEPTEMBER 6 2020, ALL DRIVES FROM THIS DATE ONWARDS HAS TMC5160 S.DRIVERS INSTALLED
// -TO USE THIS FIRMWARE THE FOLLOWING ARDUINO SOFTWARE, BOARDS AND LIBRARIES MUST BE INSTALLED, VERSION NUMBERS MUST MATCH.
//     Arduino IDE 1.8.5 Software
//     Esp32 by Espressif Systems v1.0.1 Board (required for main firmware)
//     Esp8266 by ESP8266 Community v2.4.2 Board (required for built-in wifi firmware)
//     U8G2 by Oliver v2.28.6 Library (required only for SmartHandController)
//     Ephemeris by Marscaper (single version library, required only for SmartHandController)
// - ADITIONALLY YOU MUST MADE A CHANGE on your HardwareSerial.ccp file code lines 10 & 14, this file is usually located on: 
//     C:\Users\xxxx\AppData\Local\Arduino15\packages\esp32\hardware\esp32\1.0.1\cores\esp32\HardwareSerial.ccp
//     Change the lines "#define RX1 9" & "#define TX1 10" by "#define RX1 21" & "#define TX1 22" respectively.
//     This change is mandatory for this firmware to work and in this way, OnStep AUX port will work as second serial port an enable
//     a set of conectivity options: aditional wifi, bluetooth or USB, RF Link, ethernet or future serial devices.     
// -THIS IS MAIN MCU FIRMWARE FOR ESP32 INSTEIN ONSTEP DRIVES, FOR WIFI AND SMARTHANDCONTROLLER FIRMWARE EDITING OPEN:
//     WiFi firmware: addons/WiFi-Bluetooth/WiFi-Bluetooth.ino -> set your preferences in Config.h tab
//     SmartHandController firmware: addons/St4Serial/SmartHandController/SmartHandController.ino -> set your preferences in Config.h tab
//     If all above steps are well done this firmware with its defaults settings should compile and work ok, if not, you may need to make
//     a clean install by uninstalling arduino software, manually deleting all arduino folders, pass CCleaner and restart computer.
//***************************************************************************************************************************************
