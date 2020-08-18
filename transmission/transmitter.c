#include "transmitter.h"
#include "http.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define HOST "172.17.68.206"
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
