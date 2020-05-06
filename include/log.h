#ifndef LOG_H__
#define LOG_H__

#include <iostream>
#include <fstream>

#include "uncopyable.h"

namespace advcpp
{

class Log : private Uncopyable
{
public:
    Log(std::string const& a_fileName);
    ~Log();

    //FUNCTION
    void AddEnrty(std::string const& a_data);

private:
    std::fstream m_fs;
    unsigned int m_counter;
    struct tm m_time;
};

} // namespace advcpp


#endif //end LOG_H