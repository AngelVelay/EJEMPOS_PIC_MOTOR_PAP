/*******************************************************************************
 *
 *    CCS PIC_012: Control basico de motor paso a paso y LCD16x2
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC16F887
 * Complier:        PIC C v5.025
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Con este ejemplo giraremos un motor paso a paso, dependiendo 
 *                  de los interruptores conectados en RA0, RA1 y RA2.  
 *                  Ademas tenemos un boton de ENTER para indicarle al motor 
 *                  que es momento de moverse y mostrar en la LCD un mensaje 
 *                  Considerar que el motor PAP es de 7.5° por paso.
 *******************************************************************************
 * Rev.         Date           Comment
 *   v0.00      03/12/2017     Creación del firmware
 ******************************************************************************/
//Declaracion de directivas
#include <16f887.h> //Libreria del PIC
#fuses INTRC_IO, NOWDT, NOPROTECT,NOPUT   //Fuses del PIC

//Declaraciones del micro
#use delay(clock=4000000) //Velocidad de reloj
#use fast_io(A)//Agrega puerto A
#use fast_io(B)//Agrega puerto B
#use fast_io(C)//Agrega puerto C

#include <LCD.c> //Agrega la libreria del LCD

//Nombrar Entradas-Salidas
#byte GIRO=0x05 //PORTA con el nombre de GIRO
#byte MOTOR=0x06 //PORTB con el nombre de MOTOR
#bit ENTER=0x07.0 //RC0 con el nombre de ENTER

//Variables
int n, i, j;

//Matrices para los movimientos del motor PAP
byte VUELTA[4]    ={0b0001, 0b0010, 0b0100, 0b1000};
byte ANTIVUELTA[4]={0b1000, 0b0100, 0b0010, 0b0001};

//Funciones
void MCU_Init(){
   //Entradas y salidas
   set_tris_A(0b111); //PORTA con tres entradas (RA2, RA1, RA0)
   set_tris_B(0x00);
   set_tris_D(0b1);
   //LCD
   LCD_Init();//Inicializa la LCD
   //Valores iniciales
   //Limpiamos todo el puerto
   MOTOR=0;
   GIRO=0;
   ENTER=0;
}

void rotDer(){//Funcnion para girar a la derecha
   for (i=0; i<n; i++){ //For=ciclo controlado
      for (j=0; j<4; j++){//Inicia en un valor  
         MOTOR=VUELTA[j];//Motor gira paso a paso
         delay_ms(200);  //j es igual a la posicion del paso
      }
   }   
}

void rotIzq(){//Funcion para girar a la izquierda
     for (i=0; i<n; i++){ //For=ciclo controlado
      for (j=0; j<4; j++){  //Inicia en u valor
         MOTOR=ANTIVUELTA[j];//Motor jira paso a paso
         delay_ms(200);      //j cantidad de paso
      }
   }    
}

//Funcion main
void main(){
   MCU_Init();
   
   //Mensaje inicial
   lcd_gotoxy(1,1);//Imprime y posiciona en LCD
   printf(lcd_putc, "Control de motor\n   PAP + LCD");//Muestra texto en LCD
   delay_ms(2000); 
   lcd_gotoxy(1,1);//Imprime y posiciona en LCD
   lcd_putc("\f"); //limpia el lcd  
   printf(lcd_putc, "Selecciona RAx y \n  pulse ENTER");//Muestra texto en LCD
   
   while(TRUE){
      if(ENTER){
         switch(GIRO){
             case 0b001:
               //Mostra en el LCD el caso
               lcd_gotoxy(1,1);
               printf(lcd_putc, "Angulo=90       \n                ");
               //Orden de mover el motor
               n=3;
               rotDer();
               delay_ms(1000);
               //Llego a un angulo y muestra en LCD
               lcd_gotoxy(1,1);
               printf(lcd_putc, "Llego a 90      \n                ");
               //Regresa motor
               rotIzq();
               //Mostar que ha regresado
               lcd_gotoxy(1,1);
               printf(lcd_putc, "Regrese de 90   \n                ");  
               delay_ms(1000);
               lcd_putc("\f"); //limpia el lcd  
               printf(lcd_putc, "Selecciona RAx y \n  pulse ENTER");//Muestra texto en LCD
             break;
             case 0b010:
             //Mostra en el LCD el caso
               lcd_gotoxy(1,1);
               printf(lcd_putc, "Angulo=180       \n                ");
               //Orden de mover el motor
               n=6;
               rotDer();
               delay_ms(1000);
               //Llego a un angulo y muestra en LCD
               lcd_gotoxy(1,1);
               printf(lcd_putc, "Llego a 180      \n                ");
               //Regresa motor
               rotIzq();
               //Mostar que ha regresado
               lcd_gotoxy(1,1);
               printf(lcd_putc, "Regrese de 180   \n                ");  
               delay_ms(1000);
               lcd_putc("\f"); //limpia el lcd  
               printf(lcd_putc, "Selecciona RAx y \n  pulse ENTER");//Muestra texto en LCD
             break;
             case 0b100:
             //Mostra en el LCD el caso
               lcd_gotoxy(1,1);
               printf(lcd_putc, "Angulo=-90       \n                ");
               //Orden de mover el motor
               n=3;
               rotIzq();
               delay_ms(1000);
               //Llego a un angulo y muestra en LCD
               lcd_gotoxy(1,1);
               printf(lcd_putc, "Llego a -90      \n                ");
               //Regresa motor
               rotDer();
               //Mostar que ha regresado
               lcd_gotoxy(1,1);
               printf(lcd_putc, "Regrese de -90   \n                ");     
               delay_ms(1000);
               lcd_putc("\f"); //limpia el lcd  
               printf(lcd_putc, "Selecciona RAx y \n  pulse ENTER");//Muestra texto en LCD
             break;
             default:
               lcd_putc("\f"); //limpia el lcd  
               lcd_gotoxy(1,1);
               printf(lcd_putc, "Selecciona una  \nopcion valida  ");
             break;
         }
      }
   }
}
