#include "http.h"
#include <stdlib.h>
#include <string.h>

// Setter to port number.
void http_set_port(struct http *RESTRICT request, unsigned port)
{
    request->port = port;
}

// Converts http struct into string. This is also used for GET requests.
const char *http_str(struct http request)
{

}

// Setter to URL.
void http_set_url(struct http *RESTRICT request, const char *url)
{
    request->url = malloc(strlen(url) + 1);
    strcpy(request->url, url);
}

// Adds header property to http request.
void http_add_header_property(struct http *RESTRICT request, const char *name, const char *value)
{

}

// Creates a post request string from http struct and parameters.
const char *http_post(struct http request, const char *body)
{

}
