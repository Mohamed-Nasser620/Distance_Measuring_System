/******************************************************************************
 *
 * Module: ULTRASONIC
 *
 * File Name: ultrasonic.h
 *
 * Author: Mohamed Nasser
 *
 * Date Created: Oct 13, 2022
 *
 * Description: Header file for the ultrasonic Module driver
 *
 *******************************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Static Configurations */
#define ULTRASONIC_TRIG_PORT                PORTB_ID
#define ULTRASONIC_TRIG_PIN                 PIN5_ID

#define ULTRASONIC_ECHO_PORT                PORTD_ID
#define ULTRASONIC_ECHO_PIN                 PIN6_ID

/* Parameters Definitions */
#define ULTRASONIC_MIN_RANGE                2
#define ULTRASONIC_MAX_RANGE                400

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * 1. Initialize the ICU driver as required.
 * 2. Setup the ICU call back function.
 * 3. Setup the direction for the trigger pin as output pin through the GPIO driver.
 */
void Ultrasonic_init(void);

/*
 * Description:
 * 1. Send the trigger pulse by using Ultrasonic_Trigger function.
 * 2. Start the measurements by the ICU from this moment.
 */
uint16 Ultrasonic_readDistance(void);

#endif /* ULTRASONIC_H_ */
