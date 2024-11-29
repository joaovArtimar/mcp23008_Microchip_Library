#include "mcp23008_Microchip.h"
#include <stdio.h>


void sendData(uint8_t address, uint8_t subAddress, uint8_t value){
    uint8_t MSB, LSB, writeLength, transmitData[10], waitCounter;
    MSB = subAddress;
    LSB = value;
    writeLength = 2;
    transmitData[0] = MSB;
    transmitData[1] = LSB;
    if (I2C0_Host.Write(address, transmitData, writeLength)){
        waitCounter = 100;
        while(I2C0_Host.IsBusy()){
            waitCounter--;
        }
        if (I2C0_Host.ErrorGet() == I2C_ERROR_NONE){
            /**/
        }else{
            /**/
        }
    }      
}


void mcp23008Init(MCP23008 *mcp23008, uint8_t Addr){    
    mcp23008->adress = Addr;
    mcp23008->state = 0X00;
    sendData(mcp23008->adress, 0X00, 0b01111111);
    //sendData(mcp23008->adress, 0X09, 0X00);
}

void mcpSetPinMode(MCP23008 *mcp23008, uint8_t pin, PinDirection_ mode){
    uint8_t pinos;
    if (mode == INPUT){
        pinos = pinos | (1 << pin);
    }else if (mode == OUTPUT){
        pinos = pinos & ~(1 << pin);
    }else if (mode == INPUT_PULLUP){
        pinos = pinos | (1 << pin);
        sendData(mcp23008->adress, 0X06, pinos);
    }
    sendData(mcp23008->adress, 0X00, pinos);
}
void mcpSetPinHigh(MCP23008 *mcp23008, uint8_t pin){
    uint8_t pinos;
    pinos = pinos | (1 << pin);
    sendData(mcp23008->adress, 0X09, pinos);
}
void mcpSetPinLow(MCP23008 *mcp23008, uint8_t pin){
    uint8_t pinos;
    pinos = pinos & ~(1 << pin);
    sendData(mcp23008->adress, 0X09, pinos);
}
uint8_t mcpGetPinState(MCP23008 *mcp23008, uint8_t pin){
    
    uint8_t MSB, LSB, writeLength, transmitData[10], waitCounter;
    
    MSB = 0X09;
    LSB = 0X00;
    writeLength = 1;
    transmitData[0] = MSB;
    transmitData[1] = LSB;
    uint8_t readData = 0;
    if (I2C0_Host.WriteRead(mcp23008->adress, transmitData, writeLength, &readData, 1)){
        waitCounter = 100;
        while(I2C0_Host.IsBusy()){

            waitCounter--;
        }
        if (I2C0_Host.ErrorGet() == I2C_ERROR_NONE){
            /**/
            
        }else{
            /**/
        }
    }
    readData = (readData >> pin) & 1;
    return readData;
}