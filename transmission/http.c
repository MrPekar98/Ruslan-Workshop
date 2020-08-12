#include "http.h"
#include <stdlib.h>
#include <string.h>

// Setter to port number.
struct http http_init(unsigned port)
{
    return (struct http) {.port = port, .property_count = 0};
}

// Converts http struct into string. This is also used for GET requests.
const char *http_str(struct http request)
{

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

// Creates a post request string from http struct and parameters.
const char *http_post(struct http request, const char *body)
{

}
