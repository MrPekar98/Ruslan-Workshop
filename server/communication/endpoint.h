#include "communicatable.h"
#include <string>
#include <unistd.h>

namespace ruslan
{
    class endpoint : public communicatable
    {
    public:
        endpoint(int client_fd): fd(client_fd) {}
        ~endpoint()
        {
            close(this->fd);
        }


        int get_fd() const;
        int writeto(void* buffer, unsigned len) const override;
        int readfrom(void* buffer, unsigned len) const override;
        const endpoint& operator=(const endpoint& rvalue);
        const endpoint& operator<<(const std::string& str) const;

        template<typename T>
        int operator>>(T& buffer) const;

    private:
        int fd;
    };
}
