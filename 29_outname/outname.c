#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {

  //WRITE ME
  char * name=malloc((strlen(inputName)+strlen(".counts")+1)*sizeof(*name));
  if(name!=NULL)
    {
      strcpy(name,inputName);
      strcat(name,".counts");
    }
  return name;
}
