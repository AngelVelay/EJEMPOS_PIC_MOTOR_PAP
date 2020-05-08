/*******************************************************************************
 *
 *    CCS PIC_002: Encender/Apagar LED con pulsador
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC16F887
 * Complier:        PIC C v5.025
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Encender/Apagar un LED cada que se presiona un boton, 
                    conectado en RB0, resistencia de pull-up activado
 *******************************************************************************
 * Rev.         Date            Comment
 *   v1.00      30/10/2017      Creación del firmware
 ******************************************************************************/
 
//Directivas del microcontrolador
#include <16f887.h>
#fuses XT, NOWDT
#use delay(clock = 4000000) // Reloj  de 4 MHz

//Declaracion del microcontrolador
#use fast_io(A)   //Perpara para el uso de puerto A

//Nombrar puerto
#byte PORTA = 0x05      // PORTA en 05h.
#byte TRISB = 0x86      // TRISB en 86h.
#byte PORTB = 0x06      // PORTB en 06h.
#byte OPTION_REG = 0x81 //OPTION_REG en 81h.

//Funcion para inicializacion del PIC
void MCU_Init(){
   bit_clear(OPTION_REG,7);   // Habilitación Pull-up
   bit_set(TRISB,0);          //B0 como entrada
   set_tris_A(0x00);    //Declara como salida el puerto A
   PORTA = 0x00;        //Limpiamos el puerto A
}

void main(){
   MCU_Init();
   while(TRUE){
   if (bit_test(PORTB,0) == 1 )  //Si RB0 es 1 apaga el LED
      bit_clear(PORTA,0);
   else
      bit_set(PORTA,0);         //Si RB0=0 enciende el LED
   }
}
