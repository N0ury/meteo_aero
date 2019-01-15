void getTempPress(){

    digitalWrite (BMP_POWER, HIGH); // On met le BMP280 sous tension
    pinMode (BMP_POWER, OUTPUT);
    delay(400); // On attend un peu que le BMP280 soit sous tension

    if (!bmp.begin()) {
      // Si le bmp280 ne démarre pas, on fait clignoter la led indéfiniment (1 fois par sec)
      while (1) {
        digitalWrite(13, HIGH);
        delay(1000);
        digitalWrite(13, LOW);
        delay(1000);
      }
    }

    temperature = bmp.readTemperature()*100;
    pression = (bmp.readPressure());
    delay(40);
    // Workaround: must read twice, otherwice results are wrong
    temperature = bmp.readTemperature()*100;
    pression = (bmp.readPressure());
    pinMode (BMP_POWER, INPUT);
    digitalWrite (BMP_POWER, LOW); // On remet hors tension le BMP280 

    // Arrêt I2C (à conserver)
    TWCR &= ~(bit(TWEN) | bit(TWIE) | bit(TWEA));
    twi_disable();
    
    if (debug) {
      mySerial.print("temperature:");
      mySerial.println(temperature);
      mySerial.print("pression:");
      mySerial.println(pression);
    }
}

