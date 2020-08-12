#ifndef HTTP_H
#define HTTP_H

#define POST 1
#define GET 2

#ifdef __cplusplus
#define RESTRICT
#else
#define RESTRICT restrict
#endif

typedef unsigned short req_t;

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
struct http http_init(unsigned port);
const char *http_str(struct http request, req_t type, const char *post_args);
void http_add_header_property(struct http *RESTRICT request, const char *name, const char *value);

#endif
