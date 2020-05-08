
#include <16F887.h> 
#device ADC=8
#fuses INTRC_IO,NOWDT,NOPROTECT,NOLVP, NOMCLR, NOCPD, NOBROWNOUT, NODEBUG, NOLVP, NOIESO, NOFCMEN
#use delay(clock=4000000)

 
int16 valor=0;
void main(){

    setup_timer_2(t2_div_by_16,255,1);   //Configuracion de Timer 2 para establecer frec. PWM a 1kHz
    setup_ccp1(ccp_pwm);//Configurar modulo CCP1 en modo PWM
    setup_ccp2(ccp_pwm);
    setup_adc_ports(all_analog);        //Configurar ADC
    setup_adc(ADC_CLOCK_INTERNAL);
    
  
    while(1){
      set_adc_channel(0);
      valor=read_adc(); // Lee valor RA0
      
      
      if((valor<=129)||(valor>=127))
      {
      set_pwm1_duty(0);
      valor=read_adc();
      }
      
      
      if(valor<=126)
      {
      output_bit(PIN_B0,1);
      output_bit(PIN_B1,0);
      valor=(128-read_adc());
      set_pwm1_duty(valor);
      delay_ms(10);
      }
      
      
      
      if(valor>=130)
      {
      output_bit(PIN_B0,0);
      output_bit(PIN_B1,1);
      valor=(read_adc()-128);
      set_pwm1_duty(valor);
      delay_ms(10);
      
      }
      
      set_adc_channel(1);
      valor=read_adc();
        
        
        
        
        
   }
    


