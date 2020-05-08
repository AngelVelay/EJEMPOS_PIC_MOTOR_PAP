/*******************************************************************************
 *
 *    CCS PIC_011: Sensor de temperatura con LM35
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC16F887
 * Complier:        PIC C v5.025
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Con este ejemplo mostraremos en la LCD la termperatura 
 *                  presente en el LM35
 *******************************************************************************
 * Rev.         Date           Comment
 *   v0.00      02/12/2017     Creación del firmware
 ******************************************************************************/
 
 //Direvtivas del microcontrolador
#include <16f887.h>  //Libreria del PIC
#device adc=10 //Para usar el adc de 10bits
#fuses INTRC_IO , NOWDT, NOPROTECT,NOPUT   //Fuses del PIC
#use delay(clock=4000000) //Especifica la velocidad de reloj
#include <lcd.c>
//Declaracion del microcontrolador
#use fast_io(A)   //Prepara para el uso de puerto A
#use fast_io(D)   //Prepara para el uso de puerto D
   
int16 nbitsADC;      //aqui almacenamos el valor del puerto RA0 
float temperaturaLM35; 
 
 void main(){         
   set_tris_a(0xFF);//Puerto A como entrada 
   SETUP_ADC_PORTS(sAN0);  // determina que el puerto RA0/AN0 será analógico
   SET_ADC_CHANNEL(0);
   setup_adc(ADC_CLOCK_DIV_32); //desactivamos comparadores del puerto A   
   setup_comparator(NC_NC_NC_NC);    
   lcd_init(); 
     //Mensaje inicial
   lcd_gotoxy(1,1);//Posiciona en LCD
   lcd_putc ("Sensor de");//manda un mensaje al LCD  
   lcd_gotoxy(1,2);
   lcd_putc ("temperatura LM35");
   delay_ms(1000); //espera 1 segundo                     
   lcd_putc("\f"); //limpia el lcd  
   while(true){
      nbitsADC = read_adc();  //lee el dato de AN0
      // 1bit = 0.48828125°C, aplicamos regla de tres para temperatura final
      temperaturaLM35 = nbitsADC * 0.48828125;
      lcd_putc("\f"); //limpia el lcd  
      lcd_gotoxy(1,1);
      lcd_putc ("  Temperatura:");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"    %1.2f C",temperaturaLM35);
      // %1.2f es para mostrar un entero y dos decimales de tipo floar
      delay_ms(1000);//espera 1000 milisegundos
   }                                                           
 }  
