/*******************************************************************************
 *
 *    CCS PIC_009: 	Leer ADC y mostrar numero de bits en la LCD
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC16F887
 * Complier:        PIC C v5.025
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Con este ejemplo mostraremos en la LCD el valor leido en AN0
 *******************************************************************************
 * Rev.         Date           Comment
 *   v1.00      25/11/2017     Creación del firmware
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
   
int16 valorADC;      //aqui almacenamos el valor del puerto RA0   
 
 void main(){         
   set_tris_a(0xFF);//Puerto A como entrada 
   SETUP_ADC_PORTS(sAN0);  // determina que el puerto RA0/AN0 será analógico
   SET_ADC_CHANNEL(0);
   setup_adc(ADC_CLOCK_DIV_32); //desactivamos comparadores del puerto A   
   setup_comparator(NC_NC_NC_NC);    
   lcd_init(); 
     //Mensaje inicial
   lcd_gotoxy(1,1);//Posiciona en LCD
   lcd_putc ("ADC + LCD16x2");//manda un mensaje al LCD  
   lcd_gotoxy(1,2);
   lcd_putc ("MrChunckuee!!");
   delay_ms(1000); //espera 1 segundo                     
   lcd_putc("\f"); //limpia el lcd  
   while(true){
      valorADC = read_adc();  //lee el dato de AN0
      lcd_putc("\f"); //limpia el lcd  
      printf(lcd_putc,"Valor ADC:\n %4Lu",valorADC);  //Manda el valor del ADC al LCD 
      // \n es para saltar a la siguiente linea
      // %4Lu para mostar el tipo de variable int16 con solo 4 digitos
      delay_ms(1000);//espera 1000 milisegundos
   }                                                           
 }  
