#include "http.h"

// Setter to port number.
void http_set_port(struct http *RESTRICT request, unsigned port)
{
    request->port = port;
}

// Converts http struct into string.
const char *http_str(struct http request)
{

}

// Setter to URL.
void http_set_url(struct http *RESTRICT request, const char *url)
{

}

// Adds header property to http request.
void http_add_header_property(struct http *RESTRUCT request, const char *name, const char *value)
{

}

// Creates a post request string from http struct and parameters.
const char *http_post(struct http request, const char *body)
{

}
