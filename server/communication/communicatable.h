#ifndef COMMUNICATABLE_H
#define COMMUNICATABLE_H

namespace ruslan
{
    // Communication interface.
    class communicatable
    {
    public:
        virtual ~communicatable() {}
        virtual int writeto(void* buffer, unsigned len) = 0;
        virtual int readfrom(void* buffer, unsigned len) = 0;
    };
}

#endif
