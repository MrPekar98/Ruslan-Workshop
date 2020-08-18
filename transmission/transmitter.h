#ifndef TRANSMITTER_H
#define TRANSMITTER_H

// Defines record of groups.
typedef struct
{
    char *name;
    unsigned balance, stock_count, stock_value, total_value;
} group;

// TODO: Abstract API call functions, such as buy and sell.
int *get_market_data();     // TODO: Make struct for time that is easy to use.
group get_info();
void buy();
void sell();
void set_token(const char *token);

#endif
