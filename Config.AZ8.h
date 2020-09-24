
// Configuration for Instein AZ8 GoTo kit.
// http://www.instein.eu/index.php?route=product/category&path=25
// This configuration file is only valid for Instein ESP32 DRIVES with TMC5160 Stepper Drivers and supplied stepper motors (17HM15-0904S)
// Be sure you configured only single Mount type from the available ones in OnStep.ino tab first code line: #define Mount_

/*              Any question related to instein products should be posted by contact instein@instein.eu, therefore 
 *          for more information on setting OnStep up see http://www.stellarjourney.com/index.php?r=site/equipment_onstep
 *                            and join the OnStep Groups.io at https://groups.io/g/onstep
 * 
 *           *** Read the compiler warnings and errors, they are there to help guard against invalid configurations ***
*/

//***************************************************************************************************************************
//**************** TO UPLOAD THIS SETTINGS THEY MUST BE ACTIVATED IN OnStep TAB FIRST CODE LINE: #define Mount_  ************
//***************************************************************************************************************************

// SERIAL PORTS ---------------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#SERIAL
#define SERIAL_A_BAUD_DEFAULT        9600 // Instein Drive Micro USB COM Port baudrate, lowest baudrates = larguer cable lenght. 9600 Recomended
#define SERIAL_D_BAUD_DEFAULT        9600 // Instein Drive AUX COM Port baudrate, lowest baudrates = larguer cable lenght. 9600 Recomended
                                          // AUX COM Port Pinout: #1:5VdcOut #2:GND #3:RX #4:TX Many single Serial TTL devices can be conected here
// BUILT-IN BLUETOOTH
#define SERIAL_C_BAUD_DEFAULT         ON  // ON or OFF to activate or desactivate built-in ESP32 Bluetooth.                                              
#define SERIAL_C_BLUETOOTH_NAME  "OnStep" // Visible device name for ESP32 built-in Bluetooth.                                       

// MOUNT TYPE -------------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#MOUNT_TYPE
#define MOUNT_TYPE                 ALTAZM // GEM, GEM for German Equatorial, FORK for Equatorial Fork, or ALTAZM for dobsonian-style mounts.         


// GUIDING BEHAVIOR ----------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#GUIDING
#define GUIDE_TIME_LIMIT                0 //    0, No guide time limit. Or n. Where n=1 to 120 second time limit guard.
#define GUIDE_DISABLE_BACKLASH        OFF //    OFF, Disable backlash takeup during guiding at <= 1X                          

// TRACKING BEHAVIOUR -------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#TRACKING
#define TRACK_AUTOSTART               OFF //    OFF, ON Start with tracking enabled.                                          
#define TRACK_REFRACTION_RATE_DEFAULT OFF //    OFF, ON Start w/atmospheric refract. compensation (RA axis/Eq mounts only.)   
#define TRACK_BACKLASH_RATE            25 //     25, n. Where n=2..50 (x sidereal rate) during backlash takeup.               
                                          //         Too fast motors stall/gears slam or too slow and sluggish in backlash.

// SYNCING BEHAVIOUR ---------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#SYNCING
#define SYNC_CURRENT_PIER_SIDE_ONLY    ON //     ON, Disables ability of sync to change pier side, for GEM mounts.            

// SLEWING BEHAVIOUR ---------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#SLEWING
#define SLEW_RATE_BASE_DESIRED        1.25 //    1.0, n.  Desired slew rate in deg/sec.(1deg/s = 240x) Adjustable at run-time from      
                                          //    1/2 to 2x this rate, and as MCU performace considerations require.
#define SLEW_RATE_MEMORY              ON  //    OFF, ON Remembers rates set across power cycles.                              
#define SLEW_ACCELERATION_DIST        5.0 //    5.0, n, (degrees.) Distance for acceleration (and deceleration.)
#define SLEW_RAPID_STOP_DIST          2.5 //    2.0, n, (degrees.) Distance required to stop when a slew is aborted or a limit is exceeded.
#define MFLIP_SKIP_HOME               ON  //    OFF, ON Goto directly to the destination without visiting home position.      
#define MFLIP_PAUSE_HOME_MEMORY       OFF //    OFF, ON Remember meridian flip pause at home setting across power cycles.     
#define MFLIP_AUTOMATIC_MEMORY        OFF //    OFF, ON Remember automatic meridian flip setting across power cycles.         

// PARKING BEHAVIOUR ---------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#PARKING
#define STRICT_PARKING                OFF //    OFF, ON Un-parking is only allowed if successfully parked.                    

// MOTION CONTROL -------------------------------------------------- see https://onstep.groups.io/g/main/wiki/6-Configuration#MOTION
#define STEP_WAVE_FORM             SQUARE // SQUARE, PULSE Step signal wave form faster rates. SQUARE best signal integrity. 

// AXIS1 RA/AZM
// see https://onstep.groups.io/g/main/wiki/6-Configuration#AXIS1
// Stepper driver models (also see ~/OnStep/src/sd_drivers/Models.h for additional infrequently used models and more info.): 
// Instein Drives since September 6 2020 use Only TMC5160 s.drivers in _QUIET mode (StealthChop tracking) unless otherwise especified.
// For TMC5160 s.drivers use only TMC5160_QUIET mode, cause of TMC5160_VQUIET (StealChop tracking & slew) has a current overflow bug.
// If using TMC2130 s.drivers use only TMC2130_VQUIET mode with hardware Vref current limiting instead of software current limit (IHOLD IRUN IGOTO must be set to OFF for TMC2130)
// For all cases TMC5160 s.drivers is highly recomended, as it has a great current handling and can reach up to 3A current output with a well designed heatsink.

#define AXIS1_STEPS_PER_DEGREE        6400.0         // (Stepper_steps * micro_steps * overall_gear_reduction)/360.0 
#define AXIS1_STEPS_PER_WORMROT       12800          // (AXIS1_STEPS_PER_DEGREE*360)/reduction_final_stage (PEC Eq mode only, ignored for others)
#define AXIS1_DRIVER_MODEL            TMC5160_QUIET  // OFF, (See above.) Stepper driver model.
#define AXIS1_DRIVER_MICROSTEPS       32             // OFF, n. Microstep mode when tracking. 
#define AXIS1_DRIVER_MICROSTEPS_GOTO  OFF            // OFF, n. Microstep mode used during gotos.                                     
#define AXIS1_DRIVER_IHOLD            400            // OFF, n, (mA.) Current during standstill. OFF uses IRUN/2.0                    
#define AXIS1_DRIVER_IRUN             600            // OFF, n, (mA.) Current during tracking, appropriate for stepper/driver/etc.    
#define AXIS1_DRIVER_IGOTO            900            // OFF, n, (mA.) Current during slews. OFF uses same as IRUN.                    
#define AXIS1_DRIVER_REVERSE          ON             // OFF, ON Reverses movement direction, or reverse wiring instead to correct.
#define AXIS1_DRIVER_STATUS           TMC_SPI        // OFF, TMC_SPI, HIGH, or LOW.  Polling for driver status info/fault detection.  
#define AXIS1_LIMIT_UNDER_POLE        180            // 180, n. Where n=150..180 (degrees.) Max HA hour angle + or - for Eq modes.
#define AXIS1_LIMIT_MAXAZM            360            // 360, n. Where n=180..360 (degrees.) Max Azimuth + or - for AltAzm mode only.

// AXIS2 DEC/ALT
// see https://onstep.groups.io/g/main/wiki/6-Configuration#AXIS2
#define AXIS2_STEPS_PER_DEGREE        6400.0         // (Stepper_steps * micro_steps * overall_gear_reduction)/360.0
#define AXIS2_DRIVER_MODEL            TMC5160_QUIET  // OFF, (See above.) Stepper driver model.
#define AXIS2_DRIVER_MICROSTEPS       32             // OFF, n. Microstep mode when tracking.
#define AXIS2_DRIVER_MICROSTEPS_GOTO  OFF            // OFF, n. Microstep mode used during gotos.                                     
#define AXIS2_DRIVER_IHOLD            400            // OFF, n, (mA.) Current during standstill. OFF uses IRUN/2.0                    
#define AXIS2_DRIVER_IRUN             600            // OFF, n, (mA.) Current during tracking, appropriate for stepper/driver/etc.    
#define AXIS2_DRIVER_IGOTO            900            // OFF, n, (mA.) Current during slews. OFF uses same as IRUN.                    
#define AXIS2_DRIVER_POWER_DOWN       OFF            // OFF, ON Powers off 10sec after movement stops or 10min after last<=1x guide.  
#define AXIS2_DRIVER_REVERSE          OFF            // OFF, ON Reverses movement direction, or reverse wiring instead to correct.
#define AXIS2_DRIVER_STATUS           TMC_SPI        // OFF, TMC_SPI, HIGH, or LOW.  Polling for driver status info/fault detection.  
#define AXIS2_TANGENT_ARM             OFF            // OFF, ON +limit range below. Set cntr w/[Reset Home] Return cntr w/[Find Home]
#define AXIS2_LIMIT_MIN               -91            // -91, n. Where n=-91..0 (degrees.) Minimum allowed declination.
#define AXIS2_LIMIT_MAX               91             // 91, n. Where n=0..91 (degrees.) Maximum allowed declination.

// ST4 Interface and Hand Controller.
#define ST4_INTERFACE                 ON  // OFF, ON enables interface for 1X or lower guide rates unless ST4_HAND_CONTROL = ON
                                          // During goto btn press: aborts slew or continue meridian flip pause home
#define ST4_HAND_CONTROL              ON  // OFF, ON for hand controller special features and SHC support.
                                          // Hold [E]+[W] btns >2s: Guide rate   [E]-  [W]+  [N] trk on/off [S] sync
                                          // Hold [N]+[S] btns >2s: Usr cat item [E]-  [W]+  [N] goto [S] snd on/off
                                          // Instein Drives RJ12 6P6C ST4 is OnStep compliant, pinout is as follows:
                                          // #1:5VdcOut #2:GND #3:RA-(West) #4:DE-(South) #5:DE+(North) #6:RA+(East)
// THAT'S IT FOR USER CONFIGURATION!

// -------------------------------------------------------------------------------------------------------------------------
#define FileVersionConfig 3

