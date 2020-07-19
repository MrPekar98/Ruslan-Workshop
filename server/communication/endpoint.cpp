#include "endpoint.h"
#include <unistd.h>
#include <string.h>

namespace ruslan
{
    //endpoint::endpoint(int client_fd) : fd(client_fd) {}

    // Sends message to endpoint.
    int endpoint::writeto(void* buffer, unsigned len)
    {
        return write(this->fd, buffer, len);
    }

    // Reads message from endpoint into buffer.
    int endpoint::readfrom(void* buffer, unsigned len)
    {
        return read(this->fd, buffer, len);
    }

    // Simple writing operator.
    const endpoint& endpoint::operator<<(const std::string& str) const
    {
        write(this->fd, str.c_str(), str.length());
        return *this;
    }

    // Simple reading operator.
    template<typename T>
    int endpoint::operator>>(T& buffer) const
    {
        T* buffer_read = new T[sizeof(T)];
        int ret = read(this->fd, buffer_read, sizeof(buffer));

        if (ret < 0)
        {
            delete[] buffer_read;
            return ret;
        }

        buffer = *buffer_read;
        delete[] buffer_read;

        return ret;
    }
}
