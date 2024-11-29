![Design sem nome](https://github.com/user-attachments/assets/59a3e555-edf6-430a-bd5a-bec007b5694d)

#mcp23008_Microchip_Library

Esta biblioteca foi desenvolvida para funcionar com o **MCP23008** da Microchip, um IO Expander com interface I2C. A biblioteca foi implementada utilizando o **AVR64DD32** da Microchip como microcontrolador base. 

⚠️ **Nota**: A biblioteca não foi testada com microcontroladores PIC.

## Índice
- [Sobre](#sobre)
- [Características](#características)
- [Requisitos](#requisitos)
- [Instruções](#Instruções)
- [Uso](#uso)

O **MCP23008** é um expansor de IO com interface I2C que oferece 8 pinos GPIO adicionais configuráveis como entrada ou saída. Esta biblioteca facilita o controle do dispositivo através de funções simples para configurar os pinos, ler estados e alterar valores.
[Pagina_MCP23008](https://www.microchip.com/en-us/product/MCP23008)

[DataSheet_MCP23008](https://ww1.microchip.com/downloads/aemDocuments/documents/APID/ProductDocuments/DataSheets/MCP23008-MCP23S08-Data-Sheet-DS20001919.pdf)

A biblioteca foi desenvolvida para uso com o **AVR64DD32**, utilizando sua interface I2C.

## Características
- Configuração de pinos como entrada ou saída.
- Leitura e escrita dos pinos GPIO.
- Suporte para registrar endereços I2C de múltiplos MCP23008.
- Comunicação I2C simplificada.


## Requisitos
- Microcontrolador **AVR64DD32**.
- Biblioteca I2C do MPLAB Code Configurator (MCC) compatível com o AVR64DD32.
- Compilador **XC8** ou ambiente similar.
- **MCP23008** conectado ao barramento I2C.

## Instruções
- Inicie um novo projeto no MPLAB X IDE 6.20v e escolha as opções que mais se adequam ao seu projeto (Nome, microcontrolador, etc.)
- Após o projeto criado, inicie o MCC (MPLAB Code Configurator)
- Adicione um driver I2C_Host
- Clique em Generate
- Abra o Arquivo "main.c"
- Adicione o arquivo mcp23008_Microchip.h na pasta header e o .c na pasta source, junto ao "main.c"
- Adicione o #include "mcp23008_Microchip.h"

## Uso
- void mcp23008Init(MCP23008 *mcp23008, uint8_t Addr) - Iniciar IOExpander. Addr = Endereço.
- void mcpSetPinMode(MCP23008 *mcp23008, uint8_t pin, PinDirection_ mode) - mode pode assumir os valores: OUTPUT, INPUT, INPUT_PULLUP
- void mcpSetPinHigh(MCP23008 *mcp23008, uint8_t pin) - Setar pino em 1
- void mcpSetPinLow(MCP23008 *mcp23008, uint8_t pin) - Setar pino em 0
- uint8_t mcpGetPinState(MCP23008 *mcp23008, uint8_t pin) - retorna o valor do pino (0 ou 1)


  

