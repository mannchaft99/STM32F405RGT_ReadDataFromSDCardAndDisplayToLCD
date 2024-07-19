
/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __SYSTEM_H
#define __SYSTEM_H

/* Includes ----------------------------------------------------------- */
#include "bsp_display.h"
#include "bsp_sd_card.h"
#include "stdbool.h"
/* Public defines ----------------------------------------------------- */
/* Public enumerate/structure ----------------------------------------- */
typedef enum 
{
  STATE_MENU,               /**< Menu state */
  STATE_DISPLAY_FILE,       /**< Display file state */
  STATE_MAX                 /**< Maximum number of states */
} system_state_t;

/* Public macros ------------------------------------------------------ */
/* Public variables --------------------------------------------------- */
extern system_state_t sys_state;             // Current system state
extern bool detect_state_change;             // Flag to indicate if a state change has been detected
extern uint8_t index_file_to_read;           // Index of the file to be read
extern uint8_t num_max_of_file;              // Maximum number of files

/* Public function prototypes ----------------------------------------- */

/**
 * Initialize the system.
 */
void system_init(void);

/**
 * Process the system logic and state transitions.
 */
void system_process(void);

/**
 * Reset system
 */
void system_reset(void);

#endif // __SYSTEM_H

/* End of file -------------------------------------------------------- */
