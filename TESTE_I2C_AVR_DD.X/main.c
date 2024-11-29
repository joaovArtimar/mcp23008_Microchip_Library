 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
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
#include <util/delay.h>

#include "mcc_generated_files/system/system.h"
#include "mcp23008_Microchip.h"
/*
    Main application
*/
int main(void)
{
    SYSTEM_Initialize();
    MCP23008 expander[2];
    //mcp23008Init(&expander[0], 0x24);
    mcp23008Init(&expander[0], 0x25);
    mcp23008Init(&expander[1], 0x24);
    mcpSetPinMode(&expander[0], 0, INPUT);
    mcpSetPinMode(&expander[0], 1, INPUT);
    mcpSetPinMode(&expander[0], 2, INPUT);
    mcpSetPinMode(&expander[0], 3, INPUT);
    mcpSetPinMode(&expander[0], 4, INPUT);
    mcpSetPinMode(&expander[0], 5, OUTPUT);
    mcpSetPinMode(&expander[0], 6, OUTPUT);
    mcpSetPinMode(&expander[0], 7, OUTPUT);
    
    mcpSetPinMode(&expander[1], 0, INPUT);
    mcpSetPinMode(&expander[1], 1, INPUT);
    mcpSetPinMode(&expander[1], 2, INPUT);
    mcpSetPinMode(&expander[1], 3, INPUT);
    mcpSetPinMode(&expander[1], 4, INPUT);
    mcpSetPinMode(&expander[1], 5, INPUT);
    mcpSetPinMode(&expander[1], 6, INPUT);
    mcpSetPinMode(&expander[1], 7, INPUT);
    //mcpSetPinHigh(&expander[0], 3);
    //uint8_t x = 0;

    while(1)
    {
        /*x++;
        //printf("%d = ", x);
        for (int i = 7; i >= 0; i--){
            printf("Pino %d = %d\r\n", i, mcpGetPinState(&expander[1], i));
            //printf("%d", (x >> i) & 1);
        }
        printf("\r\n");
        //mcpSetPinHigh(&expander[0], 1);
        _delay_ms(1000);*/
        if(mcpGetPinState(&expander[1], 7)){
            mcpSetPinHigh(&expander[0], 7);
        }else{
            mcpSetPinLow(&expander[0], 7);
        }
        if(mcpGetPinState(&expander[1], 6)){
            mcpSetPinHigh(&expander[0], 6);
        }else{
            mcpSetPinLow(&expander[0], 6);
        }
        if(mcpGetPinState(&expander[1], 5)){
            mcpSetPinHigh(&expander[0], 5);
        }else{
            mcpSetPinLow(&expander[0], 5);
        }
        _delay_ms(100);
    }                
}
