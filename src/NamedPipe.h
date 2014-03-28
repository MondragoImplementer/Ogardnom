#ifndef NAMED_PIPE_H_
#define NAMED_PIPE_H_

typedef struct {
  const char* filePath;
  int pipeHandle;
  int errorNumber;
} NamedPipe;

enum NamedPipeMode {
	NAMED_PIPE_READ,
	NAMED_PIPE_WRITE
};

void NamedPipeInitSelf(NamedPipe* self);
int NamedPipeCreate(NamedPipe* self, const char* filePath);
int NamedPipeDestroy(NamedPipe* self);
int NamedPipeOpen(NamedPipe* self, const NamedPipeMode mode);
int NamedPipeClose(NamedPipe* self);
int NamedPipeRead(NamedPipe* self);
int NamedPipeWrite(NamedPipe* self);

#endif
