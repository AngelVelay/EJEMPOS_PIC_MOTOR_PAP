/*******************************************************************************
 *
 *    CCS PIC_003: Efecto luces auto fantastico
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC16F887
 * Complier:        PIC C v5.025
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Cuando se presiona un boton conectado en RB0, realiza el 
                    efecto del auto fantastico y enciende el LED en RA0, si se 
                    vuelve a presionar se detiene y apaga e LED, resistencia de 
                    pull-up activado, oscilador externo de 4MHz
 *******************************************************************************
 * Rev.         Date            Comment
 *   v1.00      06/11/2017      Creación del firmware
 ******************************************************************************/
 
//Directivas del microcontrolador
#include <16f887.h>
#fuses XT, NOWDT
#use delay(clock = 4000000) // Reloj  de 4 MHz

//Declaracion del microcontrolador
#use fast_io(A)   //Perpara para el uso de puerto A

//Nombrar puerto
#byte TRISB = 0x86      // TRISB en 86h.
#byte PORTA = 0x05      // PORTA en 05h.
#byte PORTB = 0x06      // PORTB en 06h.
#byte PORTD = 0x08      // PORTB en 08h.
#byte OPTION_REG = 0x81 //OPTION_REG en 81h.

#define button PIN_B0
#define ledStatus PIN_A0

unsigned char flagBoton;

//Funcion para inicializacion del PIC
void MCU_Init(){
   bit_clear(OPTION_REG,7);   // Habilitación Pull-up
   bit_set(TRISB,0);          //B0 como entrada
   set_tris_A(0x00);    //Declara como salida el puerto A
   set_tris_D(0x00);  //Puerto D como salida
   PORTA = 0x00;        //Limpiamos el puerto A
   PORTD = 0x00; //Limpiamos puerto D
   flagBoton = 0;
}

void main(){
   MCU_Init();
   while(TRUE){
   if(input(button)==0){
   flagBoton^=0xFF;
   if(flagBoton){
      output_high(ledStatus);
      PORTD = 1;
   }
   else{ 
      output_low(ledStatus);
      PORTD = 0;
   }
   while(input(button)==0);
   delay_us(50);
   }
   
   if(flagBoton){
      while(PORTD!= 128){//ejecuta mientras sea diferente a 128
        //al multiplicar por 2 va generando 2,4,8,16,32,64,128
         PORTD= PORTD *2; 
         delay_ms(50); //espera 50 milisegundos
      }  
       while(PORTD!= 1){//ejecuta mientras sea diferente a 1
        //al dividir entre 2 va generando 64,32,16,8,4,2,1
         PORTD= PORTD /2 ;      
         delay_ms(50); //espera 50 milisegundos
      }    
      }
   }
}
