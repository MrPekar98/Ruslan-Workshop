#include <stdlib.h>

#ifndef PACKET_H
#define PACKET_H

#ifdef __cplusplus
extern "C"
{
#endif

struct packet
{

};

// Prototypes.
struct packet init_packet();    // TODO: Insert appropriate arguments.
void *packet2buffer(struct packet p);

#ifdef __cplusplus
struct packet buffer2packet(void* buffer);
#else
struct packet buffer2packet(void *restrict buffer);
#endif

#ifdef __cplusplus
}
#endif

#endif
