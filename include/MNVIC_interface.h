/*
 * MNVIC_interface.h
 *
 *  Created on: Jan 17, 2024
 *      Author: Shady
 */

#ifndef MNVIC_INTERFACE_H_
#define MNVIC_INTERFACE_H_

typedef enum{
	Group16Sub0 = 3,
	Group8Sub2,
	Group4Sub4,
	Group2Sub8,
	Group0Sub16
}MNVIC_Group_t;

/*
 * Function: NVIC_voidEnable
 * --------------------------
 * Enables an interrupt using its position in the NVIC register.
 *
 * Parameters:
 *      - position: The position of the interrupt in the NVIC register.
 *
 * Returns: None
 */
void NVIC_voidEnable(uint32 Copy_u32position);

/*
 * Function: NVIC_voidDisable
 * --------------------------
 * Disables an interrupt using its position in the NVIC register.
 *
 * Parameters:
 *      - position: The position of the interrupt in the NVIC register.
 *
 * Returns: None
 */
void NVIC_voidDisable(uint32 Copy_u32position);

/*
 * Function: NVIC_voidPendingSet
 * -----------------------------
 * Sets the pending flag for an interrupt using its position in the NVIC register.
 *
 * Parameters:
 *      - position: The position of the interrupt in the NVIC register.
 *
 * Returns: None
 */
void NVIC_voidPendingSet(uint32 Copy_u32position);

/*
 * Function: NVIC_voidPendingClear
 * -------------------------------
 * Clears the pending flag for an interrupt using its position in the NVIC register.
 *
 * Parameters:
 *      - position: The position of the interrupt in the NVIC register.
 *
 * Returns: None
 */
void NVIC_voidPendingClear(uint32 Copy_position);

/*
 * Function: NVIC_voidSetInterruptGroupMode
 * ----------------------------------------
 * Sets the interrupt group mode for the NVIC.
 *
 * Parameters:
 *      - Copy_uddtGroupMode: The interrupt group mode to set.
 *
 * Returns: None
 */
void NVIC_voidSetInterruptGroupMode(MNVIC_Group_t Copy_uddtGroupMode); //AIRCR --> how many groups and sub groubs in our micro?

/*
 * Function: NVIC_voidSetInterruptPriority
 * ---------------------------------------
 * Sets the priority of an interrupt based on the configured group mode.
 *
 * Parameters:
 *      - Copy_u8IntPos: The interrupt position.
 *      - Copy_u8GroupNum: The group number.
 *      - Copy_u8SubGroupNum: The sub-group number.
 *
 * Returns: None
 */
void NVIC_voidSetInterruptPriority(uint8 Copy_u8IntPos,uint8 Copy_u8GroupNum,uint8 Copy_u8SubGroupNum);
#endif /* MNVIC_INTERFACE_H_ */
