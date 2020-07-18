#ifndef DATA_FILE_LOGGER_H
#define DATA_FILE_LOGGER_H

#include "DataLogger.h"

namespace ruslan
{
    class data_file_logger : public data_logger
    {
    public:
        data_file_logger(int fd);

    private:
        int out_fd;
    };
}

#endif
