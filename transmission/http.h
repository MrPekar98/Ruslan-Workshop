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
}

struct http
{
    unsigned port, property_count;
    char *url, *header_name, *header_value;
    struct property *header_properties;
};

#ifdef __cplusplus
}
#endif

// Prototypes.
struct http http_set_port(unsigned port);
const char *http_str(struct http request);
void http_set_url(struct http *RESTRICT request, const char *url);
void http_add_header_property(struct http *RESTRICT request, const char *name, const char *value);
const char *http_get(struct http request);
void http_post(struct http request, const char *body);

#endif
