#ifndef PAQUETE_H
#define PAQUETE_H

#define CMD_GET 0x30
#define CMD_OK  0x03

typedef struct {
  char V1;      //Primeras 3 verificaciones de SEN o LUZ
  char V2;
  char V3;
  char DatoH;   //Valor alto del dato
  char DatoL;   //Valor bajo del dato
  char V4;      //Ultimas 3 verificaciones de SEN o LUZ
  char V5;
  char V6;
} SerialData; // si no anda puede ser que el tamanio no corresponda a la suma de los tamanios y se debe hacer sin vectores


#endif // PAQUETE_H
