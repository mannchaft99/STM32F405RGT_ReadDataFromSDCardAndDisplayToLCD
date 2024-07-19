
/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_SD_CARD_H
#define __BSP_SD_CARD_H

/* Includes ----------------------------------------------------------- */
#include "File_Handling.h"
/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
typedef struct
{
  uint8_t id;        /**< Index of file */
  char name[100];    /**< Name of the file */
} manage_file_t;

/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
extern manage_file_t list_file[10];    // Array to store file information

/* Public function prototypes ----------------------------------------- */

/**
 * Mount the SD card.
 */
void bsp_sd_card_mount(void);

/**
 * Unmount the SD card.
 */
void bsp_sd_card_unmount(void);

/**
 * Read the content of a text file from the SD card.
 * 
 * @param name: Name of the text file to read.
 * @param buf: Buffer to store the content of the text file.
 */
void bsp_sd_card_read_file_txt(char *name, char *buf);

/**
 * Scan the SD card for available files and populate the list_file array with file information.
 */
void bsp_sd_card_scan_file(void);

#endif // __BSP_SD_CARD_H

/* End of file -------------------------------------------------------- */
