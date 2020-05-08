 /*******************************************************************************
 *
 *    CCS PIC_005: Uso basico del ADC
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC16F887
 * Complier:        PIC C v5.025
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Leemos el valor del potenciometro en RA0 y mostramos en el 
                    puerto D (de forma binaria)
 *******************************************************************************
 * Rev.         Date           Comment
 *   v1.00      22/11/2017     Creación del firmware
 ******************************************************************************/
 
//Direvtivas del microcontrolador
#include <16f887.h>  //Libreria del PIC
#fuses XT, NOWDT     //Fuses del PIC
#use delay(clock=4000000) //Especifica la velocidad de reloj

//Declaracion del microcontrolador
#use fast_io(A)   //Prepara para el uso de puerto A
#use fast_io(D)   //Prepara para el uso de puerto D
   
 int valorAnalogo;      //aqui almacenamos el valor del puerto RA0   
 
 void main(){         
   set_tris_a(0xFF);//Puerto A como entrada
   set_tris_d(0x00);//Puerto D como salida para Leds  
   SETUP_ADC_PORTS(sAN0);  // determina que el puerto RA0/AN0 será analógico
   SET_ADC_CHANNEL(0);
   setup_adc(ADC_CLOCK_DIV_32); //desactivamos comparadores del puerto A   
   setup_comparator(NC_NC_NC_NC);    
   while(true){
      valorAnalogo=read_adc();  //leemos el ADC
      output_D(valorAnalogo);//asignamos el valor análogo al puerto D
      delay_ms(100); //espera 100 milisegundos 
   }                                                           
 }   
