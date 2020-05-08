void main()
{
    CMCON = 0x07;   // To turn off comparators
    ADCON1 = 0x06;  // To turn off analog to digital converters

    TRISB = 0;        // PORT B as output port
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