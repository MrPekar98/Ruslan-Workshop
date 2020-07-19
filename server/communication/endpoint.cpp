#include "endpoint.h"
#include <unistd.h>
#include <string.h>

namespace ruslan
{
    //endpoint::endpoint(int client_fd) : fd(client_fd) {}

    /*endpoint::~endpoint()
    {
        close(this->fd);
    }*/

    // Getter to file descriptor.
    int endpoint::get_fd() const
    {
        return this->fd;
    }

    // Sends message to endpoint.
    int endpoint::writeto(void* buffer, unsigned len) const
    {
        return write(this->fd, buffer, len);
    }

    // Reads message from endpoint into buffer.
    int endpoint::readfrom(void* buffer, unsigned len) const
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

    // Assignment operator for copying.
    // Caller is responsible for closing file old descriptor.
    const endpoint& endpoint::operator=(const endpoint& rvalue)
    {
        this->fd = rvalue.get_fd();

        return *this;
    }
}
