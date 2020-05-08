 /*******************************************************************************
 *
 *    CCS PIC_007: Control basico de LCD16x2
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC16F887
 * Complier:        PIC C v5.025
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Con este ejemplo controlaremos un display LCD16x2 con la 
                    librería LCD.C, primero un mensaje de bienvenida para despues
                    entrar en un bucle donde realizara un conteo e impimira el 
                    resultado en el display.
 *******************************************************************************
 * Rev.         Date           Comment
 *   v1.00      25/11/2017     Creación del firmware
 ******************************************************************************/
 //Direvtivas del microcontrolador
#include <16f887.h>  //Libreria del PIC
#fuses INTRC_IO , NOWDT, NOPROTECT,NOPUT   //Fuses del PIC
#use delay(clock=4000000) //Especifica la velocidad de reloj
#include <LCD.c>//Agrega la libreria del LCD
unsigned int conteo = 0;
 
 void main(){         
   lcd_init();//Inicializamos el LCD
   //Mensaje inicial
   lcd_gotoxy(1,1);//Posiciona en LCD
   lcd_putc ("Test LCD 16x2");//manda un mensaje al LCD  
   lcd_gotoxy(1,2);
   lcd_putc ("MrChunckuee!!");
   delay_ms(1000); //espera 1 segundo                     
   lcd_putc("\f"); //limpia el lcd  
   while(true){                       
      conteo++;
      if (conteo > 100)
         conteo = 0;
      lcd_putc("\f"); 
      lcd_gotoxy(1,1);
      lcd_putc ("Conteo:");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"%u ",conteo);  //imprime el contador en el LCD   
      delay_ms(500);//espera 500 milisegundos
     }
 }   
