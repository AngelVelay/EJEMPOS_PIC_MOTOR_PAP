/*******************************************************************************
 *
 *    CCS PIC_004: Control de matriz de LEDs 8x8
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC16F887
 * Complier:        PIC C v5.025
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Matriz de LEDs con un interrupcion externa, muestra una 
                    cara triste y cuando se presiona el boton cambia a feliz
 *******************************************************************************
 * Rev.         Date           Comment
 *   v1.00      0/11/2017      Creación del firmware
 ******************************************************************************/
 
//Direvtivas del microcontrolador
#include <16f887.h>  //Libreria del PIC
#fuses XT, NOWDT     //Fuses del PIC
#use delay(clock=4000000) //Especifica la velocidad de reloj

//Declaracion del microcontrolador
#use fast_io(B)   //Prepara para el uso de puerto B
#use fast_io(C)   //Prepara para el uso de puerto C
#use fast_io(D)   //Prepara para el uso de puerto D

//Nombrar puertos
#bit  ENTER    = 0x06.0 //Nombra a un solo pin ENTER en este caso RB0
#byte FILAS    = 0x07   //Nombra FILA al PORTC
#byte COLUMNAS = 0x08   //Nombra COLUMNA al PORTD 

//Inicializar el PIC
void MCU_Init(){
   //Entradas y Salidas
   set_tris_b(0x01); //RB0 como entrada
   set_tris_c(0x00); //PORTC=COLUMNAS como salidas
   set_tris_d(0x00); //PORTD=FILAS como salida
   
   //Configuraos interrupcion externa
   enable_interrupts(GLOBAL); //Habilita las interrupciones
   ext_int_edge(L_TO_H); //Se activa con flanco de subida
   enable_interrupts(INT_EXT); //Expecifica interrupcion externa
}

void CaraEnojada(){
   COLUMNAS= 0b00000001;
   FILAS=    0b11000011;
   delay_ms(1);
   COLUMNAS= 0b00000010;
   FILAS=    0b10111101;
   delay_ms(1);
   COLUMNAS= 0b00000100;
   FILAS=    0b01011010;
   delay_ms(1);
   COLUMNAS= 0b00001000;
   FILAS=    0b01110110;
   delay_ms(1);
   COLUMNAS= 0b00010000;
   FILAS=    0b01110110;
   delay_ms(1);
   COLUMNAS= 0b00100000;
   FILAS=    0b01011010;;
   delay_ms(1);
   COLUMNAS= 0b01000000;
   FILAS=    0b10111101;
   delay_ms(1);
   COLUMNAS= 0b10000000;
   FILAS=    0b11000011;
   delay_ms(1);
}

void CaraFeliz(){
   COLUMNAS= 0b00000001;
   FILAS=    0b11000011;
   delay_ms(1);
   COLUMNAS= 0b00000010;
   FILAS=    0b10111101;
   delay_ms(1);
   COLUMNAS= 0b00000100;
   FILAS=    0b01010110;
   delay_ms(1);
   COLUMNAS= 0b00001000;
   FILAS=    0b01111010;
   delay_ms(1);
   COLUMNAS= 0b00010000;
   FILAS=    0b01111010;
   delay_ms(1);
   COLUMNAS= 0b00100000;
   FILAS=    0b01010110;
   delay_ms(1);
   COLUMNAS= 0b01000000;
   FILAS=    0b10111101;
   delay_ms(1);
   COLUMNAS= 0b10000000;
   FILAS=    0b11000011;
   delay_ms(1);
}

#INT_EXT
void Atender(){
   while(ENTER){ //Si se presiona el boton
      CaraFeliz();   //llama cara feliz
   }
}

void main(){
   MCU_Init(); //Llama inicializar el PIC
   while(TRUE){
      CaraEnojada(); //Llama cara enojada   
   }
}
