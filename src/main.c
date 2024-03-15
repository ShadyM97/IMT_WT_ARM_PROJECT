#include "BIT_Math.h"
#include "STD_Types.h"
#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "MSPI_interface.h"
#include "MSYSTICK_interface.h"
#include "GPTIM_interface.h"
#include "TIMER2_interface.h"
#include "HTFT_interface.h"
#include "OS_int.h"
#include "HR2RDAC_interface.h"
#include "MEXTI_interface.h"
#include "MNVIC_interface.h"
#include "HIR_interface.h"
#include "Image.h"
#include "song.h"
/*
 * Function: play
 * ---------------
 * Description: Plays different actions based on the button pressed.
 *
 * Inputs: None
 *
 * Outputs: None
 *
 * Side Effects: Executes different actions based on the value of the global variable buttonPressed.
 *
 * Notes: Displays images or plays audio based on the button pressed.
 */
void play(void)
{
	if (buttonPressed == LEFT)
	{
		HTFT_voidDisplay(u16imageArr);
	}
	else if (buttonPressed == RIGHT)
	{
		HTFT_voidDisplay(u16imageArr1);
	}
	else if (buttonPressed == UP)
	{
		HR2RDAC_voidSetData(song_raw, SONG_ARR_SIZE);
	}
	else if (buttonPressed == DOWN)
	{
		HR2RDAC_voidSetData(0, 0);
	}
}
/*
 * Function: main
 * ---------------
 * Description: Main function that initializes the microcontroller and starts the operating system.
 *
 * Inputs: None
 *
 * Outputs: None
 *
 * Side Effects: Initializes the microcontroller peripherals and starts the operating system.
 *
 * Notes: Initializes the microcontroller peripherals, creates OS tasks, and starts the OS scheduler.
 */
int main(void)
{
	/* RCC Initializations and NVIC */
	MRCC_voidInit();
	MRCC_voidEnable(AHB1, AHB1_GPIOA);
	MRCC_voidEnable(AHB1, AHB1_GPIOB);
	MRCC_voidEnable(APB2, APB2_SPI1);
	MRCC_voidEnable(APB1, APB1_TIM2);
	MRCC_voidEnable(APB1, APB1_TIM3);
	MRCC_voidEnable(APB2, APB2_SYSCFG);
	NVIC_voidEnable(6);
	NVIC_voidEnable(29);
	NVIC_voidSetInterruptGroupMode(Group2Sub8);
	NVIC_voidSetInterruptPriority(6, 0, 0);
	NVIC_voidSetInterruptPriority(29, 1, 0);

	/* TFT Pins initializations */
	MGPIO_voidSetMode(PORT_A, PIN_2, PIN_OUTPUT); // RESET
	MGPIO_voidSetOutputMode(PORT_A, PIN_2, PUSH_PULL, LOW_SPEED);
	MGPIO_voidSetMode(PORT_A, PIN_3, PIN_OUTPUT); // A0
	MGPIO_voidSetOutputMode(PORT_A, PIN_3, PUSH_PULL, LOW_SPEED);

	MGPIO_voidSetMode(PORT_A, PIN_7, PIN_ALT); // MOSI SDA PIN
	MGPIO_voidSetAlt(PORT_A, PIN_7, AF5_SPI_1_4);

	MGPIO_voidSetMode(PORT_A, PIN_6, PIN_ALT); // MISO
	MGPIO_voidSetAlt(PORT_A, PIN_6, AF5_SPI_1_4);

	MGPIO_voidSetMode(PORT_A, PIN_5, PIN_ALT); // SCK
	MGPIO_voidSetAlt(PORT_A, PIN_5, AF5_SPI_1_4);

	MGPIO_voidSetMode(PORT_A, PIN_4, PIN_ALT); // NSS CS
	MGPIO_voidSetAlt(PORT_A, PIN_4, AF5_SPI_1_4);

	/* Setting External Interrupt */

	MEXTI0_voidCallBack(HIR_voidReceiveFrame);
	MEXTI_voidInterruptSetPort(EXTI_LineZero, EXTI_PortA);
	MEXTI_voidInterruptTrigger(EXTI_LineZero, EXTI_Falling);
	MEXTI_voidInterruptEnableDisable(EXTI_LineZero, EXTI_Enable);

	/* Microcontroller Layer Initializations */
	TIM3_voidInit();
	MSYSTICK_voidInit();
	MSYSTICK_voidCtrlIntState(SYSTICKEnable);
	MSPI_voidInit();

	/* Hardware Layer Initializations */
	HTFT_voidInit();
	HR2RDAC_voidinit();

	/* Creating OS Tasks */
	OS_u8CreateTask(&play, 200, 0, 0);

	/* Starting OS */
	StartOS();
	while(1)
	{

	}

}
