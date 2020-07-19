#include "communicatable.h"
#include <string>

namespace ruslan
{
    class endpoint : public communicatable
    {
    public:
        endpoint(int client_fd): fd(client_fd) {}
        ~endpoint() {}
        int writeto(void* buffer, unsigned len) override;
        int readfrom(void* buffer, unsigned len) override;
        const endpoint& operator<<(const std::string& str) const;

        template<typename T>
        int operator>>(T& buffer) const;

    private:
        int fd;
    };
}
