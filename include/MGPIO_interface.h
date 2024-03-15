/*
 * MGPIO_interface.h
 *
 *  Created on: Jan 16, 2024
 *      Author: Shady
 */

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_

typedef enum
{
	PORT_A = 0,
	PORT_B,
	PORT_C
}PORT_NAME_t;

typedef enum
{
	PIN_0 = 0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15
}PIN_NUM_t;

typedef enum
{
	PIN_INPUT = 0,
	PIN_OUTPUT,
	PIN_ALT,
	PIN_ANALOG
}PIN_MODE_t;

typedef enum
{
	PUSH_PULL = 0,
	OPEN_DRAIN
}PIN_OUTPUT_MODE_t;

typedef enum
{
	LOW_SPEED = 0,
	MID_SPEED,
	HI_SPEED,
	V_HI_SPEED
}PIN_SPEED_t;

typedef enum
{
	NO_PULLUP_PULLDOWN = 0,
	PULLUP,
	PULLDOWN
}PIN_INPUT_MODE_t;

typedef enum
{
	OUTPUT_LOW = 0,
	OUTPUT_HIGH,
}PIN_OUTPUT_t;

typedef enum
{
	PIN_RESET = 0,
	PIN_SET,
}PIN_SETRESET_t;

typedef enum
{
	AF1_TIM_1_2 = 1,
	AF2_TIM_3_5,
	AF3_TIM_9_11,
	AF4_I2C_1_3,
	AF5_SPI_1_4,
	AF6_SPI_3,
	AF7_USART_1_2,
	AF8_USART6,
	AF9_I2C_2_3,
	AF10_OTG_FS,
	AF11,
	AF12_SDIO,
	AF13,
	AF14,
	AF15_EVENOUT
}PIN_ALTERNATE_t;

/*
 * Function: MGPIO_voidSetMode
 * ----------------------------
 * Description: Configures the mode for a specific GPIO pin.
 *
 * Inputs:
 *      - enumPortName: GPIO port name.
 *      - enumPinNum: GPIO pin number.
 *      - enumPinMode: Pin mode to be configured.
 *
 * Outputs: None
 *
 * Side Effects: Configures the mode for the specified GPIO pin.
 *
 * Notes: None
 */
void MGPIO_voidSetMode(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, PIN_MODE_t enumPinMode);

/*
 * Function: MGPIO_voidSetOutputMode
 * ----------------------------------
 * Description: Configures the output mode and speed for a specific GPIO pin.
 *
 * Inputs:
 *      - enumPortName: GPIO port name.
 *      - enumPinNum: GPIO pin number.
 *      - enumOutMode: Output mode (PUSH_PULL or OPEN_DRAIN).
 *      - enumPinSpeed: Pin speed to be configured.
 *
 * Outputs: None
 *
 * Side Effects: Configures the output mode and speed for the specified GPIO pin.
 *
 * Notes: None
 */
void MGPIO_voidSetOutputMode(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, PIN_OUTPUT_MODE_t enumOutMode, PIN_SPEED_t enumPinSpeed);

/*
 * Function: MGPIO_voidSetInputMode
 * ---------------------------------
 * Description: Configures the input mode and speed for a specific GPIO pin.
 *
 * Inputs:
 *      - enumPortName: GPIO port name.
 *      - enumPinNum: GPIO pin number.
 *      - enumInputMode: Input mode to be configured.
 *      - enumPinSpeed: Pin speed to be configured.
 *
 * Outputs: None
 *
 * Side Effects: Configures the input mode and speed for the specified GPIO pin.
 *
 * Notes: None
 */
void MGPIO_voidSetInputMode(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, PIN_INPUT_MODE_t enumInputMode, PIN_SPEED_t enumPinSpeed);

/*
 * Function: MGPIO_voidWritePin
 * -----------------------------
 * Description: Writes a value to a specific GPIO pin.
 *
 * Inputs:
 *      - enumPortName: GPIO port name.
 *      - enumPinNum: GPIO pin number.
 *      - u8Data: Value to be written (OUTPUT_HIGH or OUTPUT_LOW).
 *
 * Outputs: None
 *
 * Side Effects: Writes a value to the specified GPIO pin.
 *
 * Notes: None
 */
void MGPIO_voidWritePin(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, PIN_OUTPUT_t u8Data);

/*
 * Function: MGPIO_voidReadPin
 * ----------------------------
 * Description: Reads the value of a specific GPIO pin.
 *
 * Inputs:
 *      - enumPortName: GPIO port name.
 *      - enumPinNum: GPIO pin number.
 *      - u8Data: Pointer to store the read value.
 *
 * Outputs: None
 *
 * Side Effects: Reads the value of the specified GPIO pin.
 *
 * Notes: None
 */
void MGPIO_voidReadPin(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, uint8* u8Data);

/*
 * Function: MGPIO_voidSetResetPin
 * --------------------------------
 * Description: Sets or resets a specific GPIO pin.
 *
 * Inputs:
 *      - enumPortName: GPIO port name.
 *      - enumPinNum: GPIO pin number.
 *      - u8Data: Action to perform (PIN_SET or PIN_RESET).
 *
 * Outputs: None
 *
 * Side Effects: Sets or resets the specified GPIO pin.
 *
 * Notes: None
 */
void MGPIO_voidSetResetPin(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, PIN_SETRESET_t u8Data);

/*
 * Function: MGPIO_voidSetAlt
 * ---------------------------
 * Description: Configures the alternate function for a specific GPIO pin.
 *
 * Inputs:
 *      - enumPortName: GPIO port name.
 *      - enumPinNum: GPIO pin number.
 *      - u8AltFun: Alternate function value.
 *
 * Outputs: None
 *
 * Side Effects: Configures the alternate function for the specified GPIO pin.
 *
 * Notes: None
 */
void MGPIO_voidSetAlt(PORT_NAME_t enumPortName, PIN_NUM_t enumPinNum, PIN_ALTERNATE_t u8AltFun);
#endif /* MGPIO_INTERFACE_H_ */
