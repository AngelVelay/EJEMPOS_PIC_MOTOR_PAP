#line 1 "F:/Electronics/Embeded/Interfacing Stepper Motor with PIC Microcontroller/Stepper Driving Bipolar.c"
void main()
{
 CMCON = 0x07;
 ADCON1 = 0x06;

 TRISB = 0;
 PORTB = 0x0F;

 do
 {
 PORTB = 0b00000001;
 Delay_ms(500);
 PORTB = 0b00000100;
 Delay_ms(500);
 PORTB = 0b00000010;
 Delay_ms(500);
 PORTB = 0b00001000;
 Delay_ms(500);
 }while(1);
}
