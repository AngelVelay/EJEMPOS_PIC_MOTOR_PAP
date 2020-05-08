 /*******************************************************************************
 *
 *    CCS PIC_008: Rotando mensaje en LCD16x2
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC16F887
 * Complier:        PIC C v5.025
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Con este ejemplo rotaremos un texto en la LCD
 *******************************************************************************
 * Rev.         Date           Comment
 *   v1.00      25/11/2017     Creación del firmware
 ******************************************************************************/
 //Direvtivas del microcontrolador
#include <16f887.h>  //Libreria del PIC
#fuses INTRC_IO , NOWDT, NOPROTECT,NOPUT   //Fuses del PIC
#use delay(clock=4000000) //Especifica la velocidad de reloj
#include <LCD.c>//Agrega la libreria del LCD
unsigned int i; //Variable para controlar la línea
unsigned int j; //Variable para controlar la columna
 
 void main(){         
   lcd_init();//Inicializamos el LCD
   //Mensaje inicial
   lcd_gotoxy(1,1);//Posiciona en LCD
   lcd_putc ("Rotando mensaje");//manda un mensaje al LCD  
   lcd_gotoxy(1,2);
   lcd_putc ("en LCD 16x2");
   delay_ms(1000); //espera 1 segundo                     
   lcd_putc("\f"); //limpia el lcd  
   while(true){   
      for (i=1;i<=2;i++){                                 
         for (j=1;j<=16;j++){                                   
            lcd_gotoxy(j,i);   //asigna (columna,fila)                    
            lcd_putc("MrChunckuee!!"); //imprime mensaje
            delay_ms(300);//espera 300 milisegundos    
            lcd_putc("\f"); //limpia el lcd 
         }       
      }
   }
 }                                                                    
 
