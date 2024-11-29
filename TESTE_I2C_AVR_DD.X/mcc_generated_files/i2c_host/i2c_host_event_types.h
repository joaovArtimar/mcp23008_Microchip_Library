/**
 * I2C Generated Driver API Header File
 *
 * @file i2c_host_event_types.h
 *
 * @defgroup i2c_host_event I2C_HOST_EVENT
 *
 * @brief This header file provides helper structures for the I2C driver implementation.
 *
 * @version TWI0 Driver Version 2.1.2
 * 
 * @version TWI0 Package Version 8.1.5
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef I2C_HOST_EVENT_TYPES_H
#define	I2C_HOST_EVENT_TYPES_H

#include "i2c_host_types.h"

#define I2C_EVENTS (9)

/**
 * @ingroup i2c_host_event
 * @typedef enum i2c_event_states_t
 * @brief Enumeration for I2C states.
 */
typedef enum
{
    I2C_STATE_IDLE = 0,
    I2C_STATE_SEND_RD_ADDR,
    I2C_STATE_SEND_WR_ADDR,
    I2C_STATE_TX,
    I2C_STATE_RX,
    I2C_STATE_NACK,
    I2C_STATE_ERROR,
    I2C_STATE_STOP,
    I2C_STATE_RESET
} i2c_event_states_t;

/**
 * @ingroup i2c_host_event
 * @typedef struct i2c_event_status_t
 * @brief I2C Event Status Structure.
 */
typedef struct
{
    bool busy;
    uint16_t address;
    uint8_t *writePtr;
    size_t writeLength;
    uint8_t *readPtr;
    size_t readLength;
    bool switchToRead;
    i2c_host_error_t errorState; 
    i2c_event_states_t state;
} i2c_event_status_t;

typedef i2c_event_states_t (*twi0eventHandler)(void);

extern volatile i2c_event_status_t twi0_Status;
extern const twi0eventHandler twi0_eventTable[I2C_EVENTS];

#endif // end of I2C_HOST_EVENT_TYPES_H