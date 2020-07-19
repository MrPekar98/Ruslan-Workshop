#include "communicatable.h"

namespace ruslan
{
    class endpoint : public communicatable
    {
    public:
        int writeto() override;
        int readfrom() override;
    };
}
