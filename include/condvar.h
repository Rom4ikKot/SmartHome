#ifndef CONDVAR_H__
#define CONDVAR_H__

#include <pthread.h>
#include <stdexcept>

#include "mutex.h"
#include "uncopyable.h"


namespace advcpp
{
    class Mutex;
    class CondVar :private Uncopyable
    {
    public:
        explicit CondVar(Mutex const& a_mutex); //now only default create
        ~CondVar();

        void Signal();

        template<typename Pred>
        void Wait(Pred  a_pred);

    private:
       pthread_cond_t	  m_condVar;
       pthread_mutex_t&   m_mutex;  
    };
    
    template<class Pred> 
    void advcpp::CondVar::Wait(Pred  a_pred)
    {
        
        while(a_pred())
	    {
            if(pthread_cond_wait(&m_condVar, &m_mutex))
            {
                throw std::runtime_error("Bad condv wait");
            }
	    }
       
    }

    
}

#endif //end CONDVAR_H
