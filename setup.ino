void setup () {
  pinMode(debugPin, INPUT_PULLUP);
  debug = !digitalRead(debugPin); // Par défaut l'état est à HIGH:debug=off à cause de la résistance de pull-up interne
  if (debug) {
    mySerial.begin(9600);
    mySerial.println("======================= begin setup ======================");
  }
  
  // Arrêt I2C
//  TWCR &= ~(bit(TWEN) | bit(TWIE) | bit(TWEA));

  //Initializes the SPI bus by setting SCK, MOSI, and SS to outputs, pulling SCK and MOSI low, and SS high.
  mlx_1.attach(10, 13, 11 ); // pin_SS=10, pinSCLK=13, pinMOSI=11
  res = mlx_1.readAngle();
  
  blink(13, 5);

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  if (debug) mySerial.println("======================== end setup =======================");
}
