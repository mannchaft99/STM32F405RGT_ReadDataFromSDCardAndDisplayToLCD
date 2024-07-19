
#include "stm32f4xx_hal.h"

#include <File_Handling.h>
#include "system.h"

/* =============================>>>>>>>> NO CHANGES AFTER THIS LINE
 * =====================================>>>>>>> */

FATFS   fs;       // file system
FIL     fil;      // File
FILINFO fno;
FRESULT fresult;  // result
UINT    br, bw;   // File read/write count

/**** capacity related *****/
FATFS   *pfs;
DWORD    fre_clust;
uint32_t total, free_space;

void Mount_SD(const TCHAR *path)
{
  fresult = f_mount(&fs, path, 1);
  if (fresult != FR_OK)
  {
    // TO DO
  }
  else
  {
    // TO DO
  }
}

void Unmount_SD(const TCHAR *path)
{
  fresult = f_mount(NULL, path, 1);
  if (fresult == FR_OK)
  {
    // TO DO
  }
  else
  {
    // TO DO
  }
}

/* Start node to be scanned (***also used as work area***) */
FRESULT Scan_SD(char *pat)
{
  DIR   dir;
  UINT  i;
  char *path = malloc(20 * sizeof(char));
  sprintf(path, "%s", pat);
  uint8_t index = 0;

  fresult = f_opendir(&dir, path); /* Open the directory */
  if (fresult == FR_OK)
  {
    for (;;)
    {
      fresult = f_readdir(&dir, &fno); /* Read a directory item */
      if (fresult != FR_OK || fno.fname[0] == 0)
        break;                         /* Break on error or end of dir */
      if (fno.fattrib & AM_DIR)        /* It is a directory */
      {
        if (!(strcmp("SYSTEM~1", fno.fname)))
          continue;
        i = strlen(path);
        sprintf(&path[i], "/%s", fno.fname);
        fresult = Scan_SD(path); /* Enter the directory */
        if (fresult != FR_OK)
          break;
        path[i] = 0;
      }
      else
      { /* It is a file. */
        num_max_of_file = index + 1;
        list_file[index].id   = index + 1;
        memcpy(list_file[index].name, fno.fname, sizeof(fno.fname));
        index++;
      }
    }
    f_closedir(&dir);
  }
  free(path);
  return fresult;
}

FRESULT Read_File(char *name, char *buf)
{
  /**** check whether the file exists or not ****/
  fresult = f_stat(name, &fno);
  if (fresult != FR_OK)
  {
    return fresult;
  }

  else
  {
    /* Open file to read */
    fresult = f_open(&fil, name, FA_READ);

    if (fresult != FR_OK)
    {
      return fresult;
    }

    /* Read data from the file
     * see the function details for the arguments */

    // char *buffer = malloc(sizeof(f_size(&fil)));
    fresult = f_read(&fil, buf, f_size(&fil), &br);
    if (fresult != FR_OK)
    {
      // TO DO
    }

    else
    {
      /* Close file */
      fresult = f_close(&fil);
      if (fresult != FR_OK)
      {
        // TO DO
      }
      else
      {
        // TO DO
      }
    }
    return fresult;
  }
}
