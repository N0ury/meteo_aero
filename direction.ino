void getAngle(int iter) {
  res = mlx_1.readAngle();
res=0;
  /* if res = -1 then no SPI signal
   * if res = -2 then signal too strong
   * if res = -3 then signal too weak
  */
  if (debug) {
    mySerial.print("direction:res lu #"); mySerial.print(iter); mySerial.print("/10: ");
    mySerial.print(res);
  }
  if (res > 1800) angle = -3600+res; else angle = res;

  if (res >= 0) {
    if (debug) {
      mySerial.print(", Angle retenu (en 1/10 degres C): ");
      mySerial.println(angle);
    }
    sum_angle+=angle;
    nb_angle++;   
  } else {
    angle = 0; // Pour avoir une instruction en mode non debug
    if (debug) mySerial.println(", Angle du capteur non retenu, on retient 0");
  }
}

void calcAngle() {
  if (nb_angle != 0)
    direction = sum_angle / nb_angle;
  else
    direction = 0;
  if (direction < 0) direction = 3600 + direction;
  if (debug) {
    mySerial.print("direction:Direction vent (en 1/10 degres C): ");
    mySerial.println(direction);
  }
}

