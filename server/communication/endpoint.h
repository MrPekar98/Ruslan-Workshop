#include "communicatable.h"

namespace ruslan
{
    class endpoint : public communicatable
    {
    public:
        int writeto(const communicatable& dest, void* buffer, unsigned len) override;
        int readfrom(const communicatable& src, void* buffer, unsigned len) override;
    };
}
