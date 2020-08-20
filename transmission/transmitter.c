#include "transmitter.h"
#include "http.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef WINDOWS
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#endif

#define PORT 3000

#define SELL 1
#define BUY 2

#define TWOCIPHER_STR(num) ({ \
    char str_num[3]; \
    (num) >= 10 ? sprintf(str_num, "%d\0", (num)) : sprintf(str_num, "0%d\0", (num)); \
    str_num; \
})

#define ISO8601(tm) ({ \
    char str[20]; \
    sprintf(str, "%d-%s-%sT%s:%s:%s\0", (tm).tm_year, TWOCIPHER_STR((tm).tm_mon + 1), TWOCIPHER_STR((tm).tm_mday), TWOCIPHER_STR((tm).tm_hour), TWOCIPHER_STR((tm).tm_min), TWOCIPHER_STR((tm).tm_sec)) \
    str; \
})

static char *x_token = NULL;

// Prototypes.
static int sockfd_setup(const char *url, unsigned port);
static inline char *host_ip(struct hostent host);
static void execute_post(void *arg);
static inline void future(void (*job)(void *arg), void *arg);

// Stores HTTP token.
void set_token(const char *token)
{
    x_token = realloc(x_token, strlen(token) + 1);
    strcpy(x_token, token);
}

// Returns market data.
int *get_market_data(struct tm from, struct tm to)
{
    // TODO: Use ISO8601 macro to convert args into string representations.
}

// Returns record of group.
group get_info()
{

}

// Buys stock.
void buy()
{
    short opt = BUY;
    future(execute_post, &opt);
}

// Sells stock.
void sell()
{
    short opt = SELL;
    future(execute_post, &opt);
}

// Sets up socket connection and return socker file descriptor.
static int sockfd_setup(const char *url, unsigned port)
{
#ifdef WINDOWS
    WSADATA wsa;
    SOCKET sockfd;

    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
        return -1;

    if ((sockfd = socket(AF_INET, SOCK_STREM, 0)) == INVALID_SOCKET)
        return -1;
#else
    int sockfd;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return -1;
#endif
    struct sockaddr_in address;
    struct hostent *host = gethostbyname(url);

    if (host == NULL)
        return -1;

    address.sin_addr.s_addr = inet_addr(host_ip(*host));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &address, sizeof(address)) < 0)
    {
        close(sockfd);
        return -1;
    }

    return sockfd;
}

// Returns last ip of hostent address list.
static inline char *host_ip(struct hostent host)
{
    struct in_addr **addr_list = (struct in_addr **) host.h_addr_list;
    unsigned i;
    char *ip = malloc(100);

    for (i = 0; addr_list[i] != NULL; i++)
    {
        strcpy(ip, inet_ntoa(*addr_list[i]));
    }

    return ip;
}

// Executes sell and buy transmission.
static void execute_post(void *arg)
{
    if (*((short *) arg) == SELL)
    {

    }

    else if (*((short *) arg) == BUY)
    {

    }
}

// Executes procedure asynchronously.
// Does not execute asynchronously on Windows.
static inline void future(void (*job)(void *arg), void *arg)
{
#if defined(LINUX) || defined(MAC)
    if (fork() == 0)
        job(arg);
#else
    job(arg);
#endif
}
