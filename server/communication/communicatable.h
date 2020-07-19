#ifndef COMMUNICATABLE_H
#define COMMUNICATABLE_H

namespace ruslan
{
    // Communication interface.
    class communicatable
    {
    public:
        virtual ~communicatable() {}
        virtual int writeto() = 0;
        virtual int readfrom() = 0;
    };
}

#endif
