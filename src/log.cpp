#include "../include/log.h"

namespace advcpp
{

advcpp::Log::Log(const std::string &a_fileName)
:m_counter(0)
{
    m_fs.open (a_fileName.c_str(),  std::fstream::out | std::fstream::app);
    //check if succedeed other wise throw exeption
    time_t temp  = time(0);
    m_time = *localtime( &temp );
    m_fs << m_counter
    << "The date is: "<< m_time.tm_mday<<" "<< m_time.tm_mon << " " << m_time.tm_year+1900<<std::endl
    << "The time is: "<< m_time.tm_hour<<":"<< m_time.tm_min<<":"<< m_time.tm_sec<<std::endl
    << "Report for: " << a_fileName << "initialized" << std::endl;  
    ++m_counter;
}

void advcpp::Log::AddEnrty(const std::string &a_data)
{
    time_t temp  = time(0);
    m_time = *localtime( &temp );
    m_fs << m_counter
    << "The date is: "<< m_time.tm_mday<<" "<< m_time.tm_mon << " " << m_time.tm_year+1900<<std::endl
    << "The time is: "<< m_time.tm_hour<<":"<< m_time.tm_min<<":"<< m_time.tm_sec << std::endl
    << a_data << std::endl;
    ++m_counter;
}

advcpp::Log::~Log()
{
    m_fs.close();
}

} // namespace advcpp
