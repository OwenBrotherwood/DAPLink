/**************************************************************************//**
 * @file     DAP_config.h
 * @brief    CMSIS-DAP Configuration File (Template)
 * @version  V1.00
 * @date     31. May 2012
 *
 * @note
 * Copyright (C) 2012 ARM Limited. All rights reserved.
 *
 * @note
 * modifed 2 Jan 2015 for IDAP-Link
 * Copyright (C) 2015 I-SYST inc. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M
 * processor based microcontrollers.
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/

#ifndef __DAP_CONFIG_H__
#define __DAP_CONFIG_H__


//**************************************************************************************************
/** 
\defgroup DAP_Config_Debug_gr CMSIS-DAP Debug Unit Information
\ingroup DAP_ConfigIO_gr 
@{
Provides definitions about:
 - Definition of Cortex-M processor parameters used in CMSIS-DAP Debug Unit.
 - Debug Unit communication packet size.
 - Debug Access Port communication mode (JTAG or SWD).
 - Optional information about a connected Target Device (for Evaluation Boards).
*/

#include "LPC11Uxx.h"                             // Debug Unit Cortex-M Processor Header File

/// Processor Clock of the Cortex-M MCU used in the Debug Unit.
/// This value is used to calculate the SWD/JTAG clock speed.
#define CPU_CLOCK               48000000       ///< Specifies the CPU Clock in Hz

/// Number of processor cycles for I/O Port write operations.
/// This value is used to calculate the SWD/JTAG clock speed that is generated with I/O
/// Port write operations in the Debug Unit by a Cortex-M MCU. Most Cortex-M processors
/// requrie 2 processor cycles for a I/O Port Write operation.  If the Debug Unit uses
/// a Cortex-M0+ processor with high-speed peripheral I/O only 1 processor cycle might be 
/// requrired.
#define IO_PORT_WRITE_CYCLES    2               ///< I/O Cycles: 2=default, 1=Cortex-M0+ fast I/0

/// Indicate that Serial Wire Debug (SWD) communication mode is available at the Debug Access Port.
/// This information is returned by the command \ref DAP_Info as part of <b>Capabilities</b>.
#define DAP_SWD                 1               ///< SWD Mode:  1 = available, 0 = not available

/// Indicate that JTAG communication mode is available at the Debug Port.
/// This information is returned by the command \ref DAP_Info as part of <b>Capabilities</b>.
#define DAP_JTAG                0               ///< JTAG Mode: 1 = available, 0 = not available.

/// Configure maximum number of JTAG devices on the scan chain connected to the Debug Access Port.
/// This setting impacts the RAM requirements of the Debug Unit. Valid range is 1 .. 255.
#define DAP_JTAG_DEV_CNT        4               ///< Maximum number of JTAG devices on scan chain

/// Default communication mode on the Debug Access Port.
/// Used for the command \ref DAP_Connect when Port Default mode is selected.
#define DAP_DEFAULT_PORT        1               ///< Default JTAG/SWJ Port Mode: 1 = SWD, 2 = JTAG.

/// Default communication speed on the Debug Access Port for SWD and JTAG mode.
/// Used to initialize the default SWD/JTAG clock frequency.
/// The command \ref DAP_SWJ_Clock can be used to overwrite this default setting.
#define DAP_DEFAULT_SWJ_CLOCK   1000000         ///< Default SWD/JTAG clock frequency in Hz.

/// Maximum Package Size for Command and Response data.
/// This configuration settings is used to optimized the communication performance with the
/// debugger and depends on the USB peripheral. Change setting to 1024 for High-Speed USB.
#define DAP_PACKET_SIZE         64              ///< USB: 64 = Full-Speed, 1024 = High-Speed.

/// Maximum Package Buffers for Command and Response data.
/// This configuration settings is used to optimized the communication performance with the
/// debugger and depends on the USB peripheral. For devices with limited RAM or USB buffer the
/// setting can be reduced (valid range is 1 .. 255). Change setting to 4 for High-Speed USB.
#define DAP_PACKET_COUNT        4              ///< Buffers: 64 = Full-Speed, 4 = High-Speed.


/// Debug Unit is connected to fixed Target Device.
/// The Debug Unit may be part of an evaluation board and always connected to a fixed
/// known device.  In this case a Device Vendor and Device Name string is stored which
/// may be used by the debugger or IDE to configure device parameters.
#define TARGET_DEVICE_FIXED     0               ///< Target Device: 1 = known, 0 = unknown;

#if TARGET_DEVICE_FIXED
#define TARGET_DEVICE_VENDOR    "ARM"          ///< String indicating the Silicon Vendor
#define TARGET_DEVICE_NAME      "Cortex-M4"    ///< String indicating the Target Device
#endif

///@}

// IDAP-Link SWJ pin maps

#define SWDIO_TMS_DIRCTRL_PORT		0
#define SWDIO_TMS_DIRCTRL_PIN			12
#define SWDIO_TMS_PORT						0
#define SWDIO_TMS_PIN							13
#define SWCLK_TCK_PORT						0
#define SWCLK_TCK_PIN							14
#define TDI_PORT									0
#define TDI_PIN										16
#define SWO_TDO_PORT							0
#define SWO_TDO_PIN								23
#ifdef IDAP_PROTO
#define TRST_PORT									0
#define TRST_PIN									22
#define RESET_PORT								1
#define RESET_PIN									19
#else
#define TRST_PORT									0
#define TRST_PIN									20
#define RESET_PORT								0
#define RESET_PIN									17
#endif

#ifdef IDAP_PROTO
#define LED_CON_PORT		0
#define LED_CON_PIN			17		// LED1 Red
#define LED_RUN_PORT		1
#define LED_RUN_PIN			15		// LED2 Green
#else
#define LED_CON_PORT		0
#define LED_CON_PIN			9		// LED1 Red
#define LED_RUN_PORT		0
#define LED_RUN_PIN			8		// LED2 Green
#endif


//**************************************************************************************************
/** 
\defgroup DAP_Config_PortIO_gr CMSIS-DAP Hardware I/O Pin Access
\ingroup DAP_ConfigIO_gr 
@{

Standard I/O Pins of the CMSIS-DAP Hardware Debug Port support standard JTAG mode
and Serial Wire Debug (SWD) mode. In SWD mode only 2 pins are required to implement the debug 
interface of a device. The following I/O Pins are provided:

JTAG I/O Pin                 | SWD I/O Pin          | CMSIS-DAP Hardware pin mode
---------------------------- | -------------------- | ---------------------------------------------
TCK: Test Clock              | SWCLK: Clock         | Output Push/Pull
TMS: Test Mode Select        | SWDIO: Data I/O      | Output Push/Pull; Input (for receiving data)
TDI: Test Data Input         |                      | Output Push/Pull
TDO: Test Data Output        |                      | Input             
nTRST: Test Reset (optional) |                      | Output Open Drain with pull-up resistor
nRESET: Device Reset         | nRESET: Device Reset | Output Open Drain with pull-up resistor


DAP Hardware I/O Pin Access Functions
-------------------------------------
The various I/O Pins are accessed by functions that implement the Read, Write, Set, or Clear to 
these I/O Pins. 

For the SWDIO I/O Pin there are additional functions that are called in SWD I/O mode only.
This functions are provided to achieve faster I/O that is possible with some advanced GPIO 
peripherals that can independently write/read a single I/O pin without affecting any other pins 
of the same I/O port. The following SWDIO I/O Pin functions are provided:
 - \ref PIN_SWDIO_OUT_ENABLE to enable the output mode from the DAP hardware.
 - \ref PIN_SWDIO_OUT_DISABLE to enable the input mode to the DAP hardware.
 - \ref PIN_SWDIO_IN to read from the SWDIO I/O pin with utmost possible speed.
 - \ref PIN_SWDIO_OUT to write to the SWDIO I/O pin with utmost possible speed.
*/


// Configure DAP I/O pins ------------------------------

/** Setup JTAG I/O pins: TCK, TMS, TDI, TDO, nTRST, and nRESET.
Configures the DAP Hardware I/O pins for JTAG mode:
 - TCK, TMS, TDI, nTRST, nRESET to output mode and set to high level.
 - TDO to input mode.
*/ 
static __inline void PORT_JTAG_SETUP (void) {
	LPC_GPIO->SET[SWCLK_TCK_PORT] = (1 << SWCLK_TCK_PIN);
	LPC_GPIO->SET[SWDIO_TMS_DIRCTRL_PORT] = (1 << SWDIO_TMS_DIRCTRL_PIN);
	LPC_GPIO->SET[SWDIO_TMS_PORT] = (1 << SWDIO_TMS_PIN);
	LPC_GPIO->DIR[SWDIO_TMS_PORT] |= (1 << SWDIO_TMS_PORT);
	LPC_GPIO->SET[TDI_PORT] = (1 << TDI_PIN);
	LPC_GPIO->SET[TRST_PORT] = (1 << TRST_PIN);
	LPC_GPIO->SET[RESET_PORT] = (1 << RESET_PIN);
}
 
/** Setup SWD I/O pins: SWCLK, SWDIO, and nRESET.
Configures the DAP Hardware I/O pins for Serial Wire Debug (SWD) mode:
 - SWCLK, SWDIO, nRESET to output mode and set to default high level.
 - TDI, TMS, nTRST to HighZ mode (pins are unused in SWD mode).
*/ 
static __inline void PORT_SWD_SETUP (void) {
	LPC_GPIO->SET[SWCLK_TCK_PORT] = (1 << SWCLK_TCK_PIN);
	LPC_GPIO->SET[SWDIO_TMS_DIRCTRL_PORT] = (1 << SWDIO_TMS_DIRCTRL_PIN);
	LPC_GPIO->SET[SWDIO_TMS_PORT] = (1 << SWDIO_TMS_PIN);
	LPC_GPIO->DIR[SWDIO_TMS_PORT] |= (1 << SWDIO_TMS_PORT);
	LPC_GPIO->SET[RESET_PORT] = (1 << RESET_PIN);
	LPC_GPIO->CLR[TDI_PORT] = (1 << TDI_PIN);
	LPC_GPIO->CLR[TRST_PORT] = (1 << TRST_PIN);
}

/** Disable JTAG/SWD I/O Pins.
Disables the DAP Hardware I/O pins which configures:
 - TCK/SWCLK, TMS/SWDIO, TDI, TDO, nTRST, nRESET to High-Z mode.
*/
static __inline void PORT_OFF (void) {
	LPC_GPIO->CLR[SWCLK_TCK_PORT] = (1 << SWCLK_TCK_PIN);
	LPC_GPIO->CLR[SWDIO_TMS_DIRCTRL_PORT] = (1 << SWDIO_TMS_DIRCTRL_PIN);
	LPC_GPIO->CLR[SWDIO_TMS_PORT] = (1 << SWDIO_TMS_PIN);
	LPC_GPIO->DIR[SWDIO_TMS_PORT] |= (1 << SWDIO_TMS_PORT);
	LPC_GPIO->CLR[TDI_PORT] = (1 << TDI_PIN);
	LPC_GPIO->DIR[TRST_PORT] &= ~(1 << TRST_PIN);
	LPC_GPIO->DIR[RESET_PORT] &= ~(1 << RESET_PIN);
}


// SWCLK/TCK I/O pin -------------------------------------

/** SWCLK/TCK I/O pin: Get Input.
\return Current status of the SWCLK/TCK DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_SWCLK_TCK_IN  (void) {
  return (LPC_GPIO->B[SWCLK_TCK_PIN]);
}

/** SWCLK/TCK I/O pin: Set Output to High.
Set the SWCLK/TCK DAP hardware I/O pin to high level.
*/
static __forceinline void     PIN_SWCLK_TCK_SET (void) {
	LPC_GPIO->SET[SWCLK_TCK_PORT] = (1 << SWCLK_TCK_PIN);
}

/** SWCLK/TCK I/O pin: Set Output to Low.
Set the SWCLK/TCK DAP hardware I/O pin to low level.
*/
static __forceinline void     PIN_SWCLK_TCK_CLR (void) {
	LPC_GPIO->CLR[SWCLK_TCK_PORT] = (1 << SWCLK_TCK_PIN);
}


// SWDIO/TMS Pin I/O --------------------------------------

/** SWDIO/TMS I/O pin: Get Input.
\return Current status of the SWDIO/TMS DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_SWDIO_TMS_IN  (void) {
  return (LPC_GPIO->B[SWDIO_TMS_PIN]);
}

/** SWDIO/TMS I/O pin: Set Output to High.
Set the SWDIO/TMS DAP hardware I/O pin to high level.
*/
static __forceinline void     PIN_SWDIO_TMS_SET (void) {
	LPC_GPIO->SET[SWDIO_TMS_PORT] = (1 << SWDIO_TMS_PIN);
}

/** SWDIO/TMS I/O pin: Set Output to Low.
Set the SWDIO/TMS DAP hardware I/O pin to low level.
*/
static __forceinline void     PIN_SWDIO_TMS_CLR (void) {
	LPC_GPIO->CLR[SWDIO_TMS_PORT] = (1 << SWDIO_TMS_PIN);
}

/** SWDIO I/O pin: Get Input (used in SWD mode only).
\return Current status of the SWDIO DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_SWDIO_IN      (void) {
  return (LPC_GPIO->B[SWDIO_TMS_PIN]);
}

/** SWDIO I/O pin: Set Output (used in SWD mode only).
\param bit Output value for the SWDIO DAP hardware I/O pin.
*/
static __forceinline void     PIN_SWDIO_OUT     (uint32_t bit) {
	if (bit & 1)
		LPC_GPIO->SET[SWDIO_TMS_PORT] = (1 << SWDIO_TMS_PIN);
	else
		LPC_GPIO->CLR[SWDIO_TMS_PORT] = (1 << SWDIO_TMS_PIN);
}

/** SWDIO I/O pin: Switch to Output mode (used in SWD mode only).
Configure the SWDIO DAP hardware I/O pin to output mode. This function is
called prior \ref PIN_SWDIO_OUT function calls.
*/
static __forceinline void     PIN_SWDIO_OUT_ENABLE  (void) {
	LPC_GPIO->SET[SWDIO_TMS_DIRCTRL_PORT] = (1 << SWDIO_TMS_DIRCTRL_PIN);
	LPC_GPIO->DIR[SWDIO_TMS_PORT] |= (1 << SWDIO_TMS_PORT);
}

/** SWDIO I/O pin: Switch to Input mode (used in SWD mode only).
Configure the SWDIO DAP hardware I/O pin to input mode. This function is
called prior \ref PIN_SWDIO_IN function calls.
*/
static __forceinline void     PIN_SWDIO_OUT_DISABLE (void) {
	LPC_GPIO->CLR[SWDIO_TMS_DIRCTRL_PORT] = (1 << SWDIO_TMS_DIRCTRL_PIN);
	LPC_GPIO->DIR[SWDIO_TMS_PORT] &= ~(1 << SWDIO_TMS_PORT);
}


// TDI Pin I/O ---------------------------------------------

/** TDI I/O pin: Get Input.
\return Current status of the TDI DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_TDI_IN  (void) {
 return (LPC_GPIO->B[TDI_PIN]);
}

/** TDI I/O pin: Set Output.
\param bit Output value for the TDI DAP hardware I/O pin.
*/
static __forceinline void     PIN_TDI_OUT (uint32_t bit) {
	if (bit & 1)
		LPC_GPIO->SET[TDI_PORT] = (1 << TDI_PIN);
	else
		LPC_GPIO->CLR[TDI_PORT] = (1 << TDI_PIN);
}


// TDO Pin I/O ---------------------------------------------

/** TDO I/O pin: Get Input.
\return Current status of the TDO DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_TDO_IN  (void) {
  return (LPC_GPIO->B[SWO_TDO_PIN]);
}


// nTRST Pin I/O -------------------------------------------

/** nTRST I/O pin: Get Input.
\return Current status of the nTRST DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_nTRST_IN   (void) {
  return (LPC_GPIO->B[TRST_PIN]);
}

/** nTRST I/O pin: Set Output.
\param bit JTAG TRST Test Reset pin status:
           - 0: issue a JTAG TRST Test Reset.
           - 1: release JTAG TRST Test Reset.
*/
static __forceinline void     PIN_nTRST_OUT  (uint32_t bit) {
	if (bit & 1)
		LPC_GPIO->SET[TRST_PORT] = (1 << TRST_PIN);
	else
		LPC_GPIO->CLR[TRST_PORT] = (1 << TRST_PIN);
}

// nRESET Pin I/O------------------------------------------

/** nRESET I/O pin: Get Input.
\return Current status of the nRESET DAP hardware I/O pin.
*/
static __forceinline uint32_t PIN_nRESET_IN  (void) {
  return (LPC_GPIO->B[RESET_PIN]);
}

/** nRESET I/O pin: Set Output.
\param bit target device hardware reset pin status:
           - 0: issue a device hardware reset.
           - 1: release device hardware reset.
*/
static __forceinline void     PIN_nRESET_OUT (uint32_t bit) {
	if (bit & 1)
		LPC_GPIO->SET[RESET_PORT] = (1 << RESET_PIN);
	else
		LPC_GPIO->CLR[RESET_PORT] = (1 << RESET_PIN);
}

///@}


//**************************************************************************************************
/** 
\defgroup DAP_Config_LEDs_gr CMSIS-DAP Hardware Status LEDs
\ingroup DAP_ConfigIO_gr
@{

CMSIS-DAP Hardware may provide LEDs that indicate the status of the CMSIS-DAP Debug Unit.

It is recommended to provide the following LEDs for status indication:
 - Connect LED: is active when the DAP hardware is connected to a debugger.
 - Running LED: is active when the debugger has put the target device into running state.
*/

/** Debug Unit: Set status of Connected LED.
\param bit status of the Connect LED.
           - 1: Connect LED ON: debugger is connected to CMSIS-DAP Debug Unit.
           - 0: Connect LED OFF: debugger is not connected to CMSIS-DAP Debug Unit.
*/
static __inline void LED_CONNECTED_OUT (uint32_t bit) {
	if (bit & 1)
		LPC_GPIO->SET[LED_CON_PORT] = (1 << LED_CON_PIN);
	else
		LPC_GPIO->CLR[LED_CON_PORT] = (1 << LED_CON_PIN);
}

/** Debug Unit: Set status Target Running LED.
\param bit status of the Target Running LED.
           - 1: Target Running LED ON: program execution in target started.
           - 0: Target Running LED OFF: program execution in target stopped.
*/
static __inline void LED_RUNNING_OUT (uint32_t bit) {
	if (bit & 1)
		LPC_GPIO->SET[LED_RUN_PORT] = (1 << LED_RUN_PIN);
	else
		LPC_GPIO->CLR[LED_RUN_PORT] = (1 << LED_RUN_PIN);
}

///@}


//**************************************************************************************************
/** 
\defgroup DAP_Config_Initialization_gr CMSIS-DAP Initialization
\ingroup DAP_ConfigIO_gr
@{

CMSIS-DAP Hardware I/O and LED Pins are initialized with the function \ref DAP_SETUP.
*/

/** Setup of the Debug Unit I/O pins and LEDs (called when Debug Unit is initialized).
This function performs the initialization of the CMSIS-DAP Hardware I/O Pins and the 
Status LEDs. In detail the operation of Hardware I/O and LED pins are enabled and set:
 - I/O clock system enabled.
 - all I/O pins: input buffer enabled, output pins are set to HighZ mode.
 - for nTRST, nRESET a weak pull-up (if available) is enabled.
 - LED output pins are enabled and LEDs are turned off.
*/
#define FUNC0		0
#define FUNC1		1
#define FUNC2		2
#define RES_PULLUP		(2 << 3)
#define RES_PULLDOWN	(1 << 3)
static __inline void DAP_SETUP (void) {
	LPC_IOCON->TMS_PIO0_12 = FUNC1 | RES_PULLUP | 0x80;		// SWDIO_TMS_DIRCTRL
	LPC_GPIO->DIR[SWDIO_TMS_DIRCTRL_PORT] |= (1 << SWDIO_TMS_DIRCTRL_PIN);
	LPC_IOCON->TDO_PIO0_13 = FUNC1 | RES_PULLUP | 0x80;		// SWDIO_TMS
	LPC_GPIO->DIR[SWDIO_TMS_PORT] |= (1 << SWDIO_TMS_PIN);
	LPC_IOCON->TRST_PIO0_14 = FUNC1 | RES_PULLUP | 0x80;	// SWCLK_TCK
	LPC_GPIO->DIR[SWCLK_TCK_PORT] |= (1 << SWCLK_TCK_PIN);
	LPC_IOCON->PIO1_19 = FUNC0 | RES_PULLUP;				// RESET
	LPC_GPIO->DIR[RESET_PORT] |= (1 << RESET_PIN);
	LPC_IOCON->PIO0_16 = FUNC0 | RES_PULLUP;				// TDI
	LPC_IOCON->PIO0_23 = FUNC0 | RES_PULLUP;				// SWO_TDO
	LPC_IOCON->PIO0_22 = FUNC0 | RES_PULLUP;				// TRST
	LPC_IOCON->TDI_PIO0_11 = FUNC2;								// VCCSENSE Analog in
	LPC_IOCON->PIO0_17 = FUNC0;								// LED_CON
	LPC_IOCON->PIO1_15 = FUNC0;								// LED_RUN
}

/** Reset Target Device with custom specific I/O pin or command sequence.
This function allows the optional implementation of a device specific reset sequence.
It is called when the command \ref DAP_ResetTarget and is for example required 
when a device needs a time-critical unlock sequence that enables the debug port.
\return 0 = no device specific reset sequence is implemented.\n
        1 = a device specific reset sequence is implemented.
*/
static __inline uint32_t RESET_TARGET (void) {
  return (0);              // change to '1' when a device reset sequence is implemented
}

///@}


#endif /* __DAP_CONFIG_H__ */
