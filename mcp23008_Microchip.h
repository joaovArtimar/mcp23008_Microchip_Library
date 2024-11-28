/* 
 * File:   mcp23008_Microchip.h
 * Author: joaov
 *
 * Created on November 28, 2024, 1:25 PM
 */

#ifndef MCP23008_MICROCHIP_H
#define	MCP23008_MICROCHIP_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/i2c_host/twi0.h"

void mcpInit(uint8_t Addr);
void pinMode(uint8_t pin, uint8_t mode);
void pinHigh(uint8_t pin);
void pinLow(uint8_t pin);


#ifdef	__cplusplus
}
#endif

#endif	/* MCP23008_MICROCHIP_H */

