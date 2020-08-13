#include "http.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Prototypes.
static unsigned long property_length(const struct property *RESTRICT property_list, unsigned len);
static char *properties_str(const struct property *RESTRICT properties, unsigned len);

// Setter to port number.
struct http http_init(unsigned port)
{
    return (struct http) {.property_count = 0};
}

// Converts http struct into string. This is also used for GET requests.
const char *http_str(struct http request, const char *page, req_t type, const char *post_args)
{
    char *str_request = malloc(property_length(request.header_properties, request.property_count) + (post_args != NULL ? strlen(post_args) : 0) + 100);
    char *header_properties = properties_str(request.header_properties, request.property_count);
    sprintf(str_request, "%s %s HTTP/1.1\r\n%s%s%s", type == POST ? "POST" : type == GET ? "GET" : "UNKNOWN", page, header_properties, type == POST ? "\r\n" : "", type == POST && post_args != NULL ? post_args : "");
    free(header_properties);

    return str_request;
}

// Computes length of strings in property list.
static unsigned long property_length(const struct property *RESTRICT property_list, unsigned len)
{
    unsigned long count = 0;
    unsigned i;

    for (i = 0; i < len; i++)
    {
        count += strlen(property_list[i].name) + strlen(property_list[i].value);
    }

    return count;
}

// Converts list of properties into string.
static char *properties_str(const struct property *RESTRICT properties, unsigned len)
{
    char *str = malloc(property_length(properties, len) + 1);
    unsigned i;

    for (i = 0; i < len; i++)
    {
        sprintf(str, "%s%s: %s\r\n", str, properties[i].name, properties[i].value);
    }

    return str;
}

// Adds header property to http request.
void http_add_header_property(struct http *RESTRICT request, const char *name, const char *value)
{
    if (request->property_count == 0)
        request->header_properties = malloc(sizeof(struct property));

    else
        request->header_properties = realloc(request->header_properties, (request->property_count + 1) * sizeof(struct property));

    struct property prop = {.name = malloc(strlen(name) + 1), .value = malloc(strlen(value) + 1)};
    strcpy(prop.name, name);
    strcpy(prop.value, value);
    request->header_properties[request->property_count++] = prop;
}
