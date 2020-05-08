#include <16f877A.h>
#fuses HS,NOWDT,NOPUT,NOPROTECT
#use standard_io(b)
#use delay(clock=4M)//especifica los 4Mhz del cristal de cuarzo

void main()
{
   set_tris_a(00111);
   set_tris_b(00000000);


do{
         
   if(input(PIN_A0)==1)    ///Paso Normal         
     {                                     
      output_high(pin_b0);
      output_high(pin_b1); 
      output_low(pin_b2);
      output_low(pin_b3);
      delay_ms(500);
//
      output_low(pin_b0);
      output_high(pin_b1); 
      output_high(pin_b2);
      output_low(pin_b3);
      delay_ms(500);
//
      output_low(pin_b0);
      output_low(pin_b1); 
      output_high(pin_b2);
      output_high(pin_b3);
      delay_ms(500);
//
      output_high(pin_b0);
      output_low(pin_b1); 
      output_low(pin_b2);
      output_high(pin_b3);
      delay_ms(500);
//
     }                   
                    
   else if(input(PIN_A1)==1)   ///Wave Drive          
     {                                     
      output_low(pin_b0);
      output_low(pin_b1); 
      output_low(pin_b2);
      output_high(pin_b3);
      delay_ms(500);
//
      output_low(pin_b0);
      output_low(pin_b1); 
      output_high(pin_b2);
      output_low(pin_b3);
      delay_ms(500);
//
      output_low(pin_b0);
      output_high(pin_b1); 
      output_low(pin_b2);
      output_low(pin_b3);
      delay_ms(500);
//
      output_high(pin_b0);
      output_low(pin_b1); 
      output_low(pin_b2);
      output_low(pin_b3);
      delay_ms(500);
//
    }

else if(input(PIN_A2)==1)             
   {                                     
      output_low(pin_b0);
      output_low(pin_b1); 
      output_low(pin_b2);
      output_high(pin_b3);
      delay_ms(500);
//
      output_low(pin_b0);
      output_low(pin_b1); 
      output_high(pin_b2);
      output_high(pin_b3);
      delay_ms(500);
//
      output_low(pin_b0);
      output_low(pin_b1); 
      output_high(pin_b2);
      output_low(pin_b3);
      delay_ms(500);
//
      output_low(pin_b0);
      output_high(pin_b1); 
      output_high(pin_b2);
      output_low(pin_b3);
      delay_ms(500);
//
      output_low(pin_b0);
      output_high(pin_b1); 
      output_low(pin_b2);
      output_low(pin_b3);
      delay_ms(500);
//
      output_high(pin_b0);
      output_high(pin_b1); 
      output_low(pin_b2);
      output_low(pin_b3);
      delay_ms(500);
//
      output_high(pin_b0);
      output_low(pin_b1); 
      output_low(pin_b2);
      output_low(pin_b3);
      delay_ms(500);
//
      output_high(pin_b0);
      output_low(pin_b1); 
      output_low(pin_b2);
      output_high(pin_b3);
      delay_ms(500);
//
     }

   else                 
     {                   
      output_low(pin_b0);
      output_low(pin_b1); 
      output_low(pin_b2);
      output_low(pin_b3);
     }

}while(true);
}

