#ifndef HTTP_H
#define HTTP_H

#ifdef __cplusplus
#define RESTRICT
#else
#define RESTRICT restrict
#endif

#ifdef __cplusplus
extern "C"
{
#endif

struct property
{
    char *name, *value;
};

struct http
{
    unsigned port, property_count;
    struct property *header_properties;
};

#ifdef __cplusplus
}
#endif

// Prototypes.
void http_set_port(struct http *RESTRICT request, unsigned port);
const char *http_str(struct http request);
void http_add_header_property(struct http *RESTRICT request, const char *name, const char *value);
const char *http_post(struct http request, const char *body);

#endif
