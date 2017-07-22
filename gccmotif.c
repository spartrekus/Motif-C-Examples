
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>  //define getcwd


int main( int argc, char *argv[])
{
    printf("- GCC MOTIF -\n");
    char cmdi[PATH_MAX];

    ////////////////////////////////////////////////////////
    if ( argc == 2)
      if ( strcmp( argv[1] , "" ) !=  0 ) 
      {
         strncpy( cmdi, "", PATH_MAX );
         strncat( cmdi , " " , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , " gcc  -Wall -DLITTLE_ENDIAN -DINT_64 -O2 -I/usr/X11R6/include -L/usr/X11R6/lib -lm -lMrm -lXm -lXpm -lXext -lXt -lSM -lICE -lX11 \"" , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , argv[1] , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , "\" " , PATH_MAX - strlen( cmdi ) -1 );
         strncat( cmdi , " -o a.out " , PATH_MAX - strlen( cmdi ) -1 );
         system( cmdi );
         return 0;
      }

    return 0;
}




/*
all:
	  gcc  -Wall -DLITTLE_ENDIAN -DINT_64 -O2 -I/usr/X11R6/include -L/usr/X11R6/lib -lm -lMrm -lXm -lXpm -lXext -lXt -lSM -lICE -lX11 zcard.c  -o zcard 

install:
	  apt-get install libxt-dev  libmotif-dev libxpm-dev   libxext-dev 

	  */


