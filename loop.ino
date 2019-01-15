void loop () {
  if (debug) mySerial.println("======================= begin loop  ======================");
  sum_angle = 0;
  nb_angle = 0;
  angle = 0;
  int j = 0;
  int iter = 0;
  // On se met en sleep pour 8*SLEEP_10MINS secondes
  for (int i = 0; i < SLEEP_10MINS; i++) {
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    j++;
    if (j >= SLEEP_1MINS) {
      // Chaque minute, on vérifie si le mode debug a été activé/désactivé
      // Et on récupère la direction du vent à cet instant là
      uint8_t debugNew = !digitalRead(debugPin);
      if (debugNew != debug) {
        debug = debugNew;
        if (debug) mySerial.begin(9600); else mySerial.end();
      }
      j = 0; iter++;
      getAngle(iter);
    }
  }
  calcAngle(); // On calcule une moyenne de direction du vent
  getTempPress();
  processResults();

  // On attend que les I/O en TX soient terminées (obligatoire)
  loop_until_bit_is_set(UCSR0A, TXC0); /* Wait until transmission ready. */

  if (debug) mySerial.println("======================== end loop  =======================");
}

