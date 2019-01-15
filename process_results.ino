void processResults(){

    temp_union.value2 = temperature;
    pression_union.value2 = pression;
    direction_union.value2 = direction;
    data[0] = temp_union.value1[1];
    data[1] = temp_union.value1[0];
    data[2] = pression_union.value1[2];
    data[3] = pression_union.value1[1];
    data[4] = pression_union.value1[0];
    data[5] = direction_union.value1[1];
    data[6] = direction_union.value1[0];
    size = 7;

    if (debug) {
      mySerial.print   ("sigfox:Contenu de data: ");
      PrintHex8(data,7);
      mySerial.println ("");
    }

    error = 1;
    error = Sigfox.ON(SOCKET0); // UART0
    if( error != 0 ) {
      //"Sigfox ON ERROR"
    if (debug) mySerial.println ("sigfox:erreur sur le ON");
      digitalWrite(6, HIGH);
      exit(0);
    }
    blink(6, 1);
    if (debug) {
      mySerial.print ("sigfox:valeur de la variable error apres le ON depuis le .ino: ");
      mySerial.print (error);
      mySerial.println (" =>0=OK, autre=KO");
    }
    // Send data to Sigfox
    error = 1;
//    error = Sigfox.sendACK(data,size);
    error = Sigfox.send(data,size);
    if( error != 0 ) {
      //"Sigfox packet sent ERROR"
    if (debug) mySerial.println ("sigfox:erreur sur le send");
      digitalWrite(7, HIGH);
      exit(0);
    }
    blink(7, 1);
    if (debug) {
      mySerial.print ("sigfox:valeur de la variable error apres le send depuis le .ino: ");
      mySerial.print (error);
      mySerial.println (" =>0=OK, autre=KO");
    }

    error = 1;
    error = Sigfox.OFF(SOCKET0); // UART0
    if( error != 0 ) {
      //"Sigfox OFF ERROR"
    if (debug) mySerial.println ("sigfox:erreur sur le OFF");
      digitalWrite(8, HIGH);
      exit(0);
    }
//    blink(8, 2);
    if (debug) {
      mySerial.print ("sigfox:valeur de la variable error apres le OFF depuis le .ino: ");
      mySerial.print (error);
      mySerial.println (" =>0=OK, autre=KO");
//    char state_c = reinterpret_cast<const char*>(Sigfox._ackData);
//    int state_i = (int)strtol(state_c, NULL, 16);
//    mySerial.print("resultat int:");
//    mySerial.println(state);
//    mySerial.print("resultat char:");
//    mySerial.println(reinterpret_cast<const char*>(Sigfox._ackData));
    }
}

