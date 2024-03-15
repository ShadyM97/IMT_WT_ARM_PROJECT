/*
 * MEXTI_interface.h
 *
 *  Created on: Jan 18, 2024
 *      Author: Shady
 */

#ifndef MEXTI_INTERFACE_H_
#define MEXTI_INTERFACE_H_

typedef enum{
	EXTI_Enable,
	EXTI_Disable
}EXTI_ENDis;

typedef enum{
	EXTI_Rising,
	EXTI_Falling,
	EXTI_OnChange
}EXTI_Trigger;

typedef enum{
	EXTI_LineZero=0,
	EXTI_LineOne,
	EXTI_LineTwo,
	EXTI_LineThree,
	EXTI_LineFour,
	EXTI_LineFive,
	EXTI_LineSix,
	EXTI_LineSeven,
	EXTI_LineEight,
	EXTI_LineNine,
	EXTI_LineTen,
	EXTI_LineEleven,
	EXTI_LineTwelve,
	EXTI_LineThirteen,
	EXTI_LineFourteen,
	EXTI_LineFifteen

}EXTI_Line;

typedef enum{
EXTI_PortA=0,
EXTI_PortB,
EXTI_PortC,
EXTI_PortD,
EXTI_PortE,
EXTI_PortH=7,

}EXTI_Port;

/*
 * Function: MEXTI_voidInterruptSetPort
 * -------------------------------------
 * Description: Configures the port for the specified EXTI line.
 *
 * Inputs:
 *      - Copy_u8Line: EXTI line to configure the port for.
 *      - Copy_u8Port: Port to be configured for the specified EXTI line.
 *
 * Outputs: None
 *
 * Side Effects: Configures the port for the specified EXTI line.
 *
 * Notes: None
 */
void MEXTI_voidInterruptSetPort(EXTI_Line Copy_u8Line,EXTI_Port Copy_u8Port);

/*
 * Function: MEXTI_voidInterruptEnableDisable
 * ------------------------------------------
 * Description: Enables or disables the specified EXTI interrupt line.
 *
 * Inputs:
 *      - Copy_u8IntLine: EXTI line to enable or disable.
 *      - Copy_u8ENDis: Enable or disable value for the specified EXTI line.
 *
 * Outputs: None
 *
 * Side Effects: Enables or disables the specified EXTI interrupt line.
 *
 * Notes: None
 */
void MEXTI_voidInterruptEnableDisable(EXTI_Line Copy_u8IntLine , EXTI_ENDis Copy_u8ENDis);

/*
 * Function: MEXTI_voidInterruptTrigger
 * -------------------------------------
 * Description: Configures the trigger for the specified EXTI line.
 *
 * Inputs:
 *      - Copy_u8IntLine: EXTI line to configure the trigger for.
 *      - Copy_u8Trig: Trigger type for the specified EXTI line.
 *
 * Outputs: None
 *
 * Side Effects: Configures the trigger for the specified EXTI line.
 *
 * Notes: None
 */
void MEXTI_voidInterruptTrigger(EXTI_Line Copy_u8IntLine,EXTI_Trigger Copy_u8Trig);

/*
 * Function: MEXTI0_voidCallBack
 * ------------------------------
 * Description: Sets the callback function for EXTI line 0.
 *
 * Inputs:
 *      - ptr: Pointer to the callback function.
 *
 * Outputs: None
 *
 * Side Effects: Sets the callback function for EXTI line 0.
 *
 * Notes: None
 */
void MEXTI0_voidCallBack(void (*ptr)(void));

/*
 * Function: MEXTI1_voidCallBack
 * ------------------------------
 * Description: Sets the callback function for EXTI line 0.
 *
 * Inputs:
 *      - ptr: Pointer to the callback function.
 *
 * Outputs: None
 *
 * Side Effects: Sets the callback function for EXTI line 1.
 *
 * Notes: None
 */
void MEXTI1_voidCallBack(void (*ptr)(void));




#endif /* MEXTI_INTERFACE_H_ */
