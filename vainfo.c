#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <va/va_str.h>

#include "va_display.h"

int open_and_close()
{
  VADisplay va_dpy;
  VAStatus va_status;
  int major_version, minor_version;
  int ret_val = 0;

  va_dpy = va_open_display();
  if (NULL == va_dpy)
  {
      return 2;
  }

  va_status = vaInitialize(va_dpy, &major_version, &minor_version);
  if (va_status != VA_STATUS_SUCCESS) {
      ret_val = 3;
  }

  vaTerminate(va_dpy);
  va_close_display(va_dpy);

  return ret_val;
}

int main(int argc, const char* argv[])
{
    for(;;)
    {
        open_and_close();
    }
}