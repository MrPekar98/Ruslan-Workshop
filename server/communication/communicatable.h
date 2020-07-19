#ifndef COMMUNICATABLE_H
#define COMMUNICATABLE_H

namespace ruslan
{
    // Communication interface.
    class communicatable
    {
    public:
        virtual ~communicatable() {}
        virtual int writeto(const communicatable& dest, void* buffer, unsigned len) = 0;
        virtual int readfrom(const communicatable& src, void* buffer, unsigned len) = 0;
    };
}

#endif
