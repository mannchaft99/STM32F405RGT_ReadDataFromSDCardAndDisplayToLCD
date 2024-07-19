
/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __BSP_DISPLAY_H
#define __BSP_DISPLAY_H

/* Includes ----------------------------------------------------------- */
#include "st7789.h"
#include "bsp_sd_card.h"
/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */

/**
 * @brief Initializes the display module.
 */
void bsp_display_init(void);

/**
 * Display text information from buffer.
 * 
 * @param buffer: Pointer to the text buffer.
 */
void bsp_display_text(const char *buffer);

/**
 * Display text from buffer on a specific line and column.
 * 
 * @param buffer: Pointer to the text buffer.
 * @param line: Line number where the text should be displayed.
 * @param column: Column number where the text should be displayed.
 */
void bsp_display_text_line(const char *buffer, uint8_t line, uint8_t column);

/**
 * Display a list of files.
 * 
 * @param list_file: Pointer to an array of manage_file_t structures representing the list of files.
 */
void bsp_display_list_file(manage_file_t *list_file);

/**
 * Display the index for choosing a file.
 */
void bsp_display_index_choose_file(void);

/**
 * Clear the display.
 */
void bsp_display_clear(void);

/**
 * Display the title for choosing a file.
 */
void bsp_display_title_choose_file(void);

#endif // __BSP_DISPLAY_H

/* End of file -------------------------------------------------------- */
