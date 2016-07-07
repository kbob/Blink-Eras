ISR(TIMER1_OVF_vect)
{
  static int8_t inc = +1;
  static uint8_t brightness = 0;
  OCR1B = brightness;
  brightness += inc;
  if (brightness == 0 || brightness == 255)
    inc = -inc;
}

int main()
{
  TCCR1 = _BV(CS12);
  GTCCR = _BV(PWM1B) | _BV(COM1B0);
  TIMSK = _BV(TOIE1);
  DDRB = _BV(DDB3) | _BV(DDB4);
  MCUCR = _BV(SE);
  PRR = _BV(PRTIM0) | _BV(PRUSI) | _BV(PRADC);
  sei();

  while (1)
    __asm__ ( "sleep" );
}

