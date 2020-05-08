 /*******************************************************************************
 *
 *    CCS PIC_006: Contador de 00 a 99
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC16F887
 * Complier:        PIC C v5.025
 * Author:          Pedro Sánchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Conteo de 0 a 99 en display de 7 segmentos de catodo comun
 *******************************************************************************
 * Rev.         Date           Comment
 *   v1.00      22/11/2017     Creación del firmware
 ******************************************************************************/
 
//Direvtivas del microcontrolador
#include <16f887.h>  //Libreria del PIC
#fuses XT, NOWDT, NOPROTECT,NOPUT   //Fuses del PIC
#use delay(clock=4000000) //Especifica la velocidad de reloj

//Declaracion del microcontrolador
#use fast_io(D)   //Prepara para el uso de puerto A
#use fast_io(E)   //Prepara para el uso de puerto E

// Definimos constantes para el display de catodo comun
byte const display7seg[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void main(){
   byte unidad=0, decena=0;
   set_tris_D(0x00); 
   set_tris_E(0x00);
   output_D(0);
   while(true){
      for (decena=0;decena<10;decena++){  //Cuenta digito decenas
         for (unidad=0;unidad<10;unidad++){
            output_E(0x01);             //cat_D=apagado,cat_U=encendido
            output_D(display7seg[unidad]);   //Cuenta digito unidades
            delay_ms(50);            //Para evitar parpadeos
            if (decena==0) output_E(0x03);     //Si decenas=0, cat_D=apagado
            else output_E(0x02);           //Si decenas>0, cat_D=encendido
            output_D(display7seg[decena]);      //Digito decenas
            delay_ms(50);               //Para evitar parpadeos
            }
        }
   }
}
