#include "condvar.h"

#include <fstream>
#include <errno.h>

namespace advcpp
{
    
    advcpp::CondVar::CondVar(Mutex const& a_mutex)
    :m_mutex(const_cast<pthread_mutex_t&>(a_mutex.GetMutex()))
    {
        if ( pthread_cond_init(&m_condVar, 0))
	    {
		    //log
            throw std::runtime_error("Bad condv create");
	    }
    }
    
    advcpp::CondVar::~CondVar()
    {
        int r;
        std::fstream fs;
        r = pthread_cond_destroy(&m_condVar);	
        switch (r)
        {
        case EBUSY: fs.open ("test.txt",  std::fstream::out | std::fstream::app);
                fs << " EBUSY";  //add other data here orcreate logger
                fs.close();
            break;

         case EINVAL: fs.open ("test.txt",  std::fstream::out | std::fstream::app);
            fs << " EINVAL"; //add other data here orcreate logger
            fs.close();
            break;

        default://log
            break;
        }
    }
    
    void advcpp::CondVar::Signal()
    {
        if(pthread_cond_signal(&m_condVar))
        {
            //log
            throw std::runtime_error("Bad condv signal");
        }
    }
    
    
} // namespace advcpp
