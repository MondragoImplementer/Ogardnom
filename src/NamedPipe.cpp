#include "NamedPipe.h"
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

void NamedPipeInitSelf(NamedPipe* self)
{
  memset(self, 0, sizeof(NamedPipe));
}

int NamedPipeCreate(NamedPipe* self, const char* filePath)
{
  unlink(filePath); // delete fifo if already existing
  if(mkfifo(filePath, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH/*O_RDWR*/) == -1) {
    return -1;
   }

  self->filePath = filePath;

  return 0;
}

int NamedPipeDestroy(NamedPipe* self)
{
  return unlink(self->filePath);
}

int NamedPipeOpen(NamedPipe* self, const NamedPipeMode mode)
{
  int fd = -1;

  switch(mode) {
    case NAMED_PIPE_READ:
      fd = open(self->filePath, O_RDONLY);
	  break;
    case NAMED_PIPE_WRITE:
      fd = open(self->filePath, O_WRONLY);
	  break;
    default:
    	fd = -1;
	  break;
  }

  if(fd < 0) {
    self->errorNumber = errno;
  }

  self->pipeHandle = fd;
  return self->pipeHandle;
}

int NamedPipeClose(NamedPipe* self)
{
  int result = 0;
  if(self->pipeHandle >= 0) {
	result = close(self->pipeHandle);
  }

  return result;
}

int NamedPipeRead(NamedPipe* self)
{
  return -1;
}
int NamedPipeWrite(NamedPipe* self)
{
  return -1;
}
