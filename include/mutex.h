#ifndef MUTEX_H__
#define MUTEX_H__

#include <pthread.h>
#include <stdexcept>

#include "uncopyable.h"

namespace advcpp
{
    class CondVar;
    class Mutex  : private Uncopyable
    {
        
    public:

        typedef enum 
        {
            DEFAULT = 0
            ,RECURSIVE 
        }type;

        explicit Mutex(std::string const& a_name , int const& a_type = 0); //now only default option
        ~Mutex();

        void Lock();
        void Unlock();
    
    private:
        friend class CondVar;
        pthread_mutex_t const& GetMutex() const ; 

    private:
        pthread_mutex_t	m_mutex;
        std::string     m_name;
    };

   
}

#endif //end MUTEX_H
