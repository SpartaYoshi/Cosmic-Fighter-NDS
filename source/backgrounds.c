/********************************************************** 
 * backgrounds.c
 *
 * Este codigo se ha implementado basandose en el ejemplo 
 * "Simple sprite demo" de dovoto y otro de Jaeden Amero
 **********************************************************/

#include <nds.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#include "back01.h"
#include "back01_f01.h"
#include "back01_f02.h"
#include "back01_f03.h"
#include "back01_f04.h"
#include "back01_f05.h"
#include "back01_f06.h"
#include "back01_f07.h"
#include "back01_f08.h"
#include "back01_f09.h"
#include "back01_f10.h"
#include "back01_f11.h"
#include "back01_f12.h"

#include "back02_f01.h"
#include "back02_f02.h"
#include "back02_f03.h"
#include "back02_f04.h"
#include "back02_f05.h"
#include "back02_f06.h"
#include "back02_f07.h"
#include "back02_f08.h"
#include "back02_f09.h"
#include "back02_f10.h"
#include "back02_f11.h"
#include "back02_f12.h"

#include "back03_f01.h"
#include "back03_f02.h"
#include "back03_f03.h"
#include "back03_f04.h"
#include "back03_f05.h"
#include "back03_f06.h"
#include "back03_f07.h"
#include "back03_f08.h"

#include "kirbo1.h"
#include "kirbo3.h"
#include "kirbo5.h"
#include "kirbo7.h"
#include "kirbo9.h"


/* 
 * Seleccionar un canal DMA para copiar a memoria las imágenes
 **/
static const int DMA_CHANNEL = 3;


/* 
 * Para cada imagen que se quiera llevar a pantalla hay que hacer una de estas funciones
 **/


void display_back01_f01() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back01_f01Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_back01_f02() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back01_f02Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_back01_f03() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back01_f03Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_back01_f04() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back01_f04Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_back01_f05() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back01_f05Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_back01_f06() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back01_f06Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_back01_f07() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back01_f07Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_back01_f08() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back01_f08Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_back01_f09() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back01_f09Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_back01_f10() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back01_f10Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_back01_f11() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back01_f11Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

void display_back01_f12() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back01_f12Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
}

// ##########################################################

void display_back02_f01() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back02_f01Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back02_f02() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back02_f02Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back02_f03() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back02_f03Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back02_f04() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back02_f04Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back02_f05() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back02_f05Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back02_f06() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back02_f06Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back02_f07() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back02_f07Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back02_f08() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back02_f08Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back02_f09() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back02_f09Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back02_f10() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back02_f10Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back02_f11() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back02_f11Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back02_f12() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back02_f12Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

// ##########################################################

void display_back03_f01() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back03_f01Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back03_f02() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back03_f02Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back03_f03() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back03_f03Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back03_f04() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back03_f04Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back03_f05() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back03_f05Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back03_f06() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back03_f06Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back03_f07() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back03_f07Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_back03_f08() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     back03_f08Bitmap,          // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

// ##########################################################

void display_kirbo_f01() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     kirbo1Bitmap,   	        // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_kirbo_f03() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     kirbo3Bitmap,      	    // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_kirbo_f05() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     kirbo5Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_kirbo_f07() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     kirbo7Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}

void display_kirbo_f09() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     kirbo9Bitmap,              // Variable generada automáticamente
                     (uint16 *)BG_BMP_RAM(0),   // Dirección del fondo 3 principal 
                     back01BitmapLen);          // Longitud (en bytes) generada automáticamente 
					 
}


// ##########################################################


/* 
 * Definir el sistema de video
 **/
void init_video() {
    /* 
     * Mapear la memoria VRAM para mostrar graficos en las dos pantallas
     **/
    vramSetMainBanks(VRAM_A_MAIN_BG_0x06000000,
                     VRAM_B_MAIN_BG_0x06020000,
                     VRAM_C_SUB_BG_0x06200000,
                     VRAM_E_LCD);
    vramSetBankE(VRAM_E_MAIN_SPRITE);
    vramSetBankD(VRAM_D_SUB_SPRITE);

    /* 
     * Establecer el modo de video de la pantalla principal
     **/
    videoSetMode(MODE_5_2D | // Establecer el modo grafico 5
                 DISPLAY_BG2_ACTIVE | // Activar el fondo 2
                 DISPLAY_BG3_ACTIVE); // Activar el fondo 3

    /* 
     * Establecer el modo de video de la pantalla secundaria
     **/
        videoSetModeSub(MODE_5_2D | // Establecer el modo grafico 5
                    DISPLAY_BG3_ACTIVE); // Activar el fondo 3
} // init_video()


/* 
 * Procedimiento para configurar el sistema de fondos
 **/
void init_background() {
    /* 
     * Establecer la afinidad del fondo 3 de la pantalla principal con color de 16 bits
     **/
    REG_BG3CNT = BG_BMP16_256x256 |
                 BG_BMP_BASE(0) |   // La dirección inicial de memoria
                 BG_PRIORITY(3);    // Baja prioridad

    /* 
     * Establecer la matriz de transformación afin del fondo 3 de la pantalla principal
     * a la matriz de identidad
     **/
    REG_BG3PA = 1 << 8;
    REG_BG3PB = 0;
    REG_BG3PC = 0;
    REG_BG3PD = 1 << 8;

    /* 
     * Definir la situación del fondo 3 de la pantalla principal. 
     * Esto deberá cambiar según la posición en la que se quiera poner el gráfico
     **/
    REG_BG3X = 0;
    REG_BG3Y = 0;

    /* 
     * Establecer la afinidad del fondo 2 de la pantalla principal con color de 16 bits
     **/
    REG_BG2CNT = BG_BMP16_128x128 |
                 BG_BMP_BASE(8) |   // La dirección inicial de memoria
                 BG_PRIORITY(2);    // Baja prioridad

    /* 
     * Establecer la matriz de transformación afin del fondo 2 de la pantalla principal 
     * a la matriz de identidad
     **/
    REG_BG2PA = 1 << 8;
    REG_BG2PB = 0;
    REG_BG2PC = 0;
    REG_BG2PD = 1 << 8;

    /* 
     * Definir la situación del fondo 2 de la pantalla principal. 
     * Esto deberá cambiar según la posición en la que se quiera poner el gráfico
     **/
    REG_BG2X = -(SCREEN_WIDTH / 2 - 32) << 8;
    REG_BG2Y = -32 << 8;

    /* 
     * Establecer la afinidad del fondo 3 de la pantalla secundaria con color de 16 bits
     **/
    REG_BG3CNT_SUB = BG_BMP16_256x256 |
                     BG_BMP_BASE(0) |   // La dirección inicial de memoria
                     BG_PRIORITY(3);    // Baja prioridad

    /* 
     * Establecer la matriz de transformación afin del fondo 3 de la pantalla secundaria
     * a la matriz de identidad
     **/
    REG_BG3PA_SUB = 1 << 8;
    REG_BG3PB_SUB = 0;
    REG_BG3PC_SUB = 0;
    REG_BG3PD_SUB = 1 << 8;

    /* 
     * Definir la situación del fondo 3 de la pantalla secundaria
     * Esto deberá cambiar según la posición en la que se quiera poner el gráfico
     **/
    REG_BG3X_SUB = 0;
    REG_BG3Y_SUB = 0;

} // init_background()
