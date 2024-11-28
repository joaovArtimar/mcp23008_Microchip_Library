#include "mcp23008_Microchip.h"
#include <stdio.h>

void mcpInit(uint8_t Addr){
    
    uint8_t clientAdd, MSB, LSB, writeLength, transmitData[10], waitCounter;
    clientAdd = 0X25;
    MSB = 0X00;
    LSB = 0b10101111;
    writeLength = 2;
    //transmitData = {};
    transmitData[0] = MSB;
    transmitData[1] = LSB;
    //transmitData[2] = 0XAA;
    //main_i2c_scan(0X00,0X7F);
    if (I2C0_Host.Write(clientAdd, transmitData, writeLength)){
        waitCounter = 100;
        while(I2C0_Host.IsBusy()){
            //I2C0_Host.Tasks();
            waitCounter--;
        }
        if (I2C0_Host.ErrorGet() == I2C_ERROR_NONE){
            printf("Encontrado\r\n");
        }else{
            printf("Erro na Transmissao\r\n");
        }
    }   
}