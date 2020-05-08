/*******************************************************************************
 *
 *                  CCS PIC_001: Blinking LED
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC16F887
 * Complier:        PIC C v5.025
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     El LED enciende y apaga cada 2 segundos
 *******************************************************************************
 * Rev.         Date            Comment
 *   v1.00      30/10/2017      Creación del firmware
 ******************************************************************************/
 
//Directivas del microcontrolador
#include <16f887.h>
#fuses XT
#use delay(clock = 4000000) //Especifica la velocidad de operacion

//Declaracion del microcontrolador
#use fast_io(A)   //Perpara para el uso de puerto A

//Nombrar puerto
#byte PORTA = 0x05 //Nombra a todo el puerto A como LED

//Funcion para inicializacion del PIC
void MCU_Init(){
    set_tris_A(0x00); //Declara como salida el puerto A
    PORTA = 0x00;     //Limpiamos el puerto A
}

void main(){
   MCU_Init();
   while(TRUE){
      PORTA = 0b101;    //Enciende el puerto
      delay_ms(1000);   //Retardo de 1 segundo
      PORTA = 0b010;    //Apaga el puerto
      delay_ms(1000);   //Retardo de 1 segundo
   }
}
