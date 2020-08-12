#include <assert.h>
#include <string.h>
#include "../http.h"

void test_set_port();
void test_adding_header_property();

int main()
{
    test_set_port();
    test_adding_header_property();

    return 0;
}

// Tests setter to port number.
void test_set_port()
{
    struct http req;
    http_set_port(&req, 8080);
    assert(req.port == 8080);
}

// Tests adding header.
void test_adding_header_property()
{
    struct http req;
    http_add_header_property(&req, "Key1", "Value1");
    http_add_header_property(&req, "Key2", "Value2");

    assert(req.property_count == 2);
    assert(strcmp(req.header_properties[0].name, "Key1") == 0);
    assert(strcmp(req.header_properties[0].value, "Value1") == 0);
    assert(strcmp(req.header_properties[1].name, "Key2") == 0);
    assert(strcmp(req.header_properties[1].value, "Value2") == 0);
}
