/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <cstdio>

#define pinLED1 PA_10
#define pinLED2 PB_5
#define pinLED3 PB_10

#define WAIT_TIME_MS 500

#define pinBT1 PA_15
#define pinBT2 PB_7
#define pinBT3 PC_2

int cont1 = 0;
int cont2 = 0;
int cont3 = 0;
int flagBotones = 0;

InterruptIn BT1(pinBT1);
InterruptIn BT2(pinBT2);
InterruptIn BT3(pinBT3);

void pulsadoBT1();
void pulsadoBT2();
void pulsadoBT3();

int main() {
  BT1.rise(pulsadoBT1);
  BT2.rise(pulsadoBT2);
  BT3.rise(pulsadoBT3);

  while (true) {
    sleep();
    if (flagBotones & 0x2) {
      printf("Boton2 pulsado %d veces\n", cont2);
      flagBotones &= ~0x2;
    }
    if (flagBotones & 0x4) {
      printf("Boton3 pulsado %d veces\n", cont3);
      flagBotones &= ~0x4;
    }
  }
}

void pulsadoBT1() {
  cont1++;
  flagBotones |= 1;
  printf("Boton1 pulsado %d veces\n", cont1); // Es mejor no poner mensajes en las interrupciones
}

void pulsadoBT2() {
  cont2++;
  flagBotones |= 0x2;
}

void pulsadoBT3() {
  cont3++;
  flagBotones |= 0b100;
}