#include <stdlib.h>

#ifdef PACKET_H
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
struct packet buffer2packet(void *restrict buffer);

#ifdef __cplusplus
}
#endif

#endif
