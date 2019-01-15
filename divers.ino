void blink(uint8_t pin, uint8_t times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
    delay(1000);
  }
}

void twi_disable(void)
{
  // disable twi module, acks, and twi interrupt
  TWCR &= ~(_BV(TWEN) | _BV(TWIE) | _BV(TWEA));

  // deactivate internal pullups for twi.
  digitalWrite(SDA, 0);
  digitalWrite(SCL, 0);
}

/*
 PrintHex routines for Arduino: to print byte or word data in hex with
 leading zeroes.
 Copyright (C) 2010 Kairama Inc
*/
void PrintHex8(uint8_t *data, uint8_t length) // prints 8-bit data in hex with leading zeroes
{
  mySerial.print("0x");
  for (int i=0; i<length; i++) {
    if (data[i]<0x10) {mySerial.print("0");} 
    mySerial.print(data[i],HEX); 
    mySerial.print(" ");
  }
}

