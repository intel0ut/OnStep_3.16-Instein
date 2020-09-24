# OnStep-Instein
This repository is intended for owners of OnStep boxes made by Instein.eu and contain a copy of the custom OnStep 3.16o for ESP32 source code used in the box. I don't own any part of this code. Original source code by Howard Dutton (https://github.com/hjd1964/OnStep) with modifications by Instein.eu


# OnStep by Howard Dutton

Copyright (C) 2012 to 2020 Howard Dutton

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Description:
  Full featured stepper motor telescope microcontroller for Equatorial and
  Alt-Azimuth mounts, with the LX200 derived command set.

Author: Howard Dutton
  http://www.stellarjourney.com
  hjd1964@gmail.com
Moded by Instein
  http://www.instein.eu
  instein@instein.eu
Revision history, and newer versions:
  See GitHub: https://github.com/hjd1964/OnStep / http://www.instein.eu/index.php?route=product/category&path=25

Documentation:
  https://groups.io/g/onstep/wiki/home / http://www.instein.eu/index.php?route=product/category&path=25

Discussion, Questions, ...etc
  https://groups.io/g/onstep


* THIS FIRMWARE IS ONLY VALID FOR INSTEIN ESP32 DRIVES PURCHASED FROM SEPTEMBER 6 2020, ALL DRIVES FROM THIS DATE ONWARDS HAS TMC5160 S.DRIVERS INSTALLED
 
* TO USE THIS FIRMWARE THE FOLLOWING ARDUINO SOFTWARE, BOARDS AND LIBRARIES MUST BE INSTALLED, VERSION NUMBERS MUST MATCH.
     Arduino IDE 1.8.5 Software
     Esp32 by Espressif Systems v1.0.1 Board (required for main firmware)
     Esp8266 by ESP8266 Community v2.4.2 Board (required for built-in wifi firmware)
     U8G2 by Oliver v2.28.6 Library (required only for SmartHandController)
     Ephemeris by Marscaper (single version library, required only for SmartHandController)
     
* ADITIONALLY YOU MUST MADE A CHANGE on your HardwareSerial.ccp file code lines 10 & 14, this file is usually located on: 
     C:\Users\xxxx\AppData\Local\Arduino15\packages\esp32\hardware\esp32\1.0.1\cores\esp32\HardwareSerial.ccp
     Change the lines "#define RX1 9" & "#define TX1 10" by "#define RX1 21" & "#define TX1 22" respectively.
     This change is mandatory for this firmware to work and in this way, OnStep AUX port will work as second serial port an enable
     a set of conectivity options: aditional wifi, bluetooth or USB, RF Link, ethernet or future serial devices. 
     
* THIS IS MAIN MCU FIRMWARE FOR ESP32 INSTEIN ONSTEP DRIVES, FOR WIFI AND SMARTHANDCONTROLLER FIRMWARE EDITING OPEN:
     WiFi firmware: addons/WiFi-Bluetooth/WiFi-Bluetooth.ino -> set your preferences in Config.h tab
     SmartHandController firmware: addons/St4Serial/SmartHandController/SmartHandController.ino -> set your preferences in Config.h tab
     If all above steps are well done this firmware with its defaults settings should compile and work ok, if not, you may need to make
     a clean install by uninstalling arduino software, manually deleting all arduino folders, pass CCleaner and restart computer.


OnStep Telescope Controller
===========================
# Important Note

THERE ARE SEVERAL GITHUB BRANCHES OF ONSTEP:
* The **RELEASE BRANCHES** are well tested and what most should use.  Usually the newest (highest revision) RELEASE is recommended.  No new features are added and only bug fixes where necessary and safe.
* Tne **BETA BRANCH**, if present, is a "snap-shot" of the MASTER where we have reached a point of apparent stability.  This provides access to most new features for adventurous users.
* The **MASTER BRANCH** is the most up to date OnStep version; where new features are added.  It is the least well tested branch and should only be user by experienced users willing to test for and report bugs.

# What is OnStep?
OnStep is a computerized telescope goto controller, based on Teensy or
Arduino control of stepper motors.

It supports Equatorial Mounts (GEM, Fork, etc.) as well as Alt-Az mounts
(including Dobsonians, and the like.)

OnStep was designed, from the beginning, as a more or less general purpose
system and provisions were made in the firmware to allow for use on a variety
of mounts.

# Features
OnStep supports a wide variety of connection options.  Either two or three serial
"command channels" can be utilized. One of the these is normally devoted to a USB
connection and for the other(s) choose from the following:

* Bluetooth
* ESP8266 WiFi
* Arduino M0/Ethernet Shield
* Even another USB port or RS232 serial isn't very difficult to add.

Other software in the OnStep ecosystem include:

* an [ASCOM](http://ascom-standards.org/) driver (with IP and Serial support),
* an Android App useable over WiFi or Bluetooth equipped Phones/Tablets
  (version 2.3.3 or later),
* a "built-in" website (on the Ethernet and/or WiFi device),
* a full planetarium program that controls all features ([Sky Planetarium](http://stellarjourney.com/index.php?r=site/software_sky)).

OnStep is compatible with the LX200 protocol. This means it can be controlled
from other planetarium software, like: Sky Safari, CdC (even without ASCOM),
Stellarium, etc.

There are also [INDI](http://www.indilib.org/about.html) drivers so it can be used from Linux, with CdC or KStars.

# Documentation
Detailed documentation, including the full set of features, detailed designs for
PCBs, instructions on how to build a controller, how to configure the firmware
for your particular mount, can all be found the [OnStep Group Wiki](https://groups.io/g/onstep/wiki/home).

# Change Log
All the changes are tracking in git, and a detailed list can be accessed using the
following git command:
 
git log --date=short --pretty=format:"%h %ad %<(20)%an %<(150,trunc)%s"

# Support
Questions and discussion should be on the mailing list (also accessible via the
web) at the [OnStep Group](https://groups.io/g/onstep/).

# License
OnStep is open source free software, licensed under the GPL.

See [LICENSE.txt](./LICENSE.txt) file.

# Author
[Howard Dutton](http://www.stellarjourney.com)
