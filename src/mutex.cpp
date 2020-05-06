#include "mutex.h"
#include "condvar.h"

#include <errno.h>
#include <fstream>


namespace advcpp
{

    advcpp::Mutex::Mutex(std::string const& a_name , int const& a_type)
    :m_name(a_name)
    {
        pthread_mutexattr_t Attr;
        if(pthread_mutexattr_init(&Attr))
        {
            //log
            throw std::runtime_error("pthread_mutexattr_init");
        }
       
        if(pthread_mutexattr_settype(&Attr, a_type))
        {
            //log
            throw std::runtime_error("pthread_mutexattr_settype");
        }   

        if(pthread_mutex_init(&m_mutex, &Attr) != 0)
        {
            //log
            throw std::runtime_error("pthread_mutex_init");
        }
        
    }

    advcpp::Mutex::~Mutex()
    {
        int r;
        std::fstream fs;
        r = pthread_mutex_destroy(&m_mutex);
        switch (r)
        {
        case EBUSY: 
            fs.open ("test.txt",  std::fstream::out | std::fstream::app);
            fs << " EBUSY";  //add other data here orcreate logger
            fs.close();
            break;

        case EINVAL: fs.open ("test.txt",  std::fstream::out | std::fstream::app);
            fs << " EINVAL"; //add other data here orcreate logger
            fs.close();
            break;

        case 0:break;   

        default:
            break;
        }
    }

    void advcpp::Mutex::Lock()
    {
        if(pthread_mutex_lock(&m_mutex) != 0)
        {
            //log
            throw std::runtime_error("Bad mudex lock!");
        }
    }

    void advcpp::Mutex::Unlock()
    {
        if(pthread_mutex_unlock(&m_mutex) != 0)
        {
            //log
            throw std::runtime_error("Bad mudex unlock!");
        }
    }

    pthread_mutex_t const& advcpp::Mutex::GetMutex() const
    {
        return m_mutex;
    }
    
} // namespace advcpp
