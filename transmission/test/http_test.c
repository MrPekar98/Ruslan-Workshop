#include <stdio.h>

#include <assert.h>
#include <string.h>
#include "../http.h"

void test_init();
void test_adding_header_property();

int main()
{
    test_init();
    test_adding_header_property();

    return 0;
}

// Tests setter to port number.
void test_init()
{
    struct http req = http_init();
    assert(req.property_count == 0);
}

// Tests adding header.
void test_adding_header_property()
{
    struct http req = http_init();
    http_add_header_property(&req, "Key1", "Value1");
    http_add_header_property(&req, "Key2", "Value2");

    assert(req.property_count == 2);
    assert(strcmp(req.header_properties[0].name, "Key1") == 0);
    assert(strcmp(req.header_properties[0].value, "Value1") == 0);
    assert(strcmp(req.header_properties[1].name, "Key2") == 0);
    assert(strcmp(req.header_properties[1].value, "Value2") == 0);
}
