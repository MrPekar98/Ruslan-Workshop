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

struct http
{
    unsigned port;
    char *url, *header_name, *header_value;
};

#ifdef __cplusplus
}
#endif

// Prototypes.
struct http http_set_port(unsigned port);
const char *http_str(struct http request);
void http_set_url(struct http *RESTRICT request, const char *url);
void http_add_header(struct http *RESTRICT request, const char *name, const char *value);
const char *http_get(struct htttp request);
void http_post(struct http request, const char *body);

#endif
