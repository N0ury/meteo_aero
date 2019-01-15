#include "LowPower.h"
#include <arduinoUtils.h>
#include <arduinoSigfox.h>
#include <Adafruit_BMP280.h>
#include <SoftwareSerial.h>
#include "MLX90316.h"

#define BMP_POWER 5 // pin pour alimenter le module BMP280 (µc 11)
#define debugPin 9
#define SLEEP_10MINS 75 // Pour un power down de 10 minutes environ
#define SLEEP_1MINS 7 // Pour des intervalles de 1 minute (vent)

int res;
MLX90316 mlx_1  = MLX90316();

// variable qui contiendra les données à envoyer à Sigfox
uint8_t data[12]; // 12 octets max
uint8_t size; // taille utilisée

int16_t temperature=0;
uint32_t pression=0;
int16_t direction=0;

Adafruit_BMP280 bmp; // I2C

int16_t sum_angle = 0;
uint8_t nb_angle = 0;
int16_t angle = 0;
  
uint8_t debug = 0;

SoftwareSerial mySerial(2, 3); // RX, TX

// define error variable
uint8_t error;

union{
  uint8_t  value1[4];
  uint32_t value2;
}pression_union;

union{
  uint8_t  value1[2];
  uint16_t value2;
}temp_union;

union{
  uint8_t  value1[2];
  uint16_t value2;
}direction_union;


