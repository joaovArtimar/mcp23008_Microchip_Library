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
   
    
    typedef struct{
        uint8_t adress;
        uint8_t state;
    }MCP23008;
    
typedef enum{
    OUTPUT,
    INPUT,
    INPUT_PULLUP
}PinDirection_;
    
void mcp23008Init(MCP23008 *mcp23008, uint8_t Addr);
void sendData(uint8_t address, uint8_t subAddress, uint8_t value);
void mcpSetPinMode(MCP23008 *mcp23008, uint8_t pin, PinDirection_ mode);
void mcpSetPinHigh(MCP23008 *mcp23008, uint8_t pin);
void mcpSetPinLow(MCP23008 *mcp23008, uint8_t pin);
uint8_t mcpGetPinMode(MCP23008 *mcp23008, uint8_t pin);
uint8_t mcpGetPinState(MCP23008 *mcp23008, uint8_t pin);

#ifdef	__cplusplus
}
#endif

#endif	/* MCP23008_MICROCHIP_H */

