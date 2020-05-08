/*******************************************************************************
 *
 *    CCS PIC_013: Control basico de PWM
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC16F887
 * Complier:        PIC C v5.025
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Lee el valor en AN0 y lo coloca como Duty Cycle del PWM
                    para este ejemplo usamos la resolucion del ADC = 8bits
 *******************************************************************************
 * Rev.         Date           Comment
 *   v0.00      04/12/2017     Creación del firmware
 ******************************************************************************/
//Declaracion de directivas
#include <16f887.h> //Libreria del PIC
#fuses INTRC_IO, NOWDT, NOPROTECT,NOPUT   //Fuses del PIC
#define adc=8; //Bits de resolucion del ADC

//Declaraciones del micro
#use delay(clock=4000000) //Velocidad de reloj
#use fast_io(A)//Agrega puerto A
#use fast_io(B)//Agrega puerto B
#use fast_io(C)//Agrega puerto C

#byte PORTA = 0x05      // PORTA en 05h.
#byte PORTC = 0x07      // PORTC en 07h.

unsigned int valueADC;

//Funciones 
void MCU_Init(){
   //Enratas y salidas
   set_tris_A(0b1);
   set_tris_C(0x00);
   PORTA = 0x00;
   PORTC = 0x00;
   
   //ADC
   SETUP_ADC_PORTS(sAN0);  // determina que el puerto RA0/AN0 será analógico
   SET_ADC_CHANNEL(0);
   setup_adc(ADC_CLOCK_DIV_32); //desactivamos comparadores del puerto A   
   setup_comparator(NC_NC_NC_NC);   
   
   
   //PWM
   /*
   Calculo del periodo:
   CCP PWM periodo = [PR2 + 1]  * 4 * Tosc * TMR2 prescaler
   Donde Tosc=1/Fosc
   */
   setup_ccp1(ccp_pwm);
   setup_timer_2(T2_DIV_BY_16, 255, 1);//SETUP_TIMER_2(MODO, PERIODO, POSCALER)
}

//Funcion principal
void main(){
   MCU_Init();
   while(TRUE){
      valueADC = read_adc();
      set_pwm1_duty(valueADC);
   }
}
