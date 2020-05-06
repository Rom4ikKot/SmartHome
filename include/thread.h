#ifndef THREAD_H__
#define THREAD_H__

#include <pthread.h>
#include <tr1/memory>

#include "runnable.h"

#include "uncopyable.h"

namespace advcpp
{
    
class Thread :private Uncopyable
{
public:
    typedef enum
    {
        TRD_JOIN=0
        ,TRD_DETATCH
        ,TRD_OK
    }threadState;
    typedef void* (*ActionFunc) (void *);
    typedef void* Context;

    typedef enum
    {
        DEADLOCK = 0 
         ///add here later
    }type;

    Thread(ActionFunc a_func, Context a_arg);  //default attr

    Thread(std::tr1::shared_ptr<Runnable>& a_obj);

    ~Thread();
    
    static void* StartWorkRutine(void* a_obj);

    void ThreadJoin();  ///not getting retval
    void ThreadDetach();

private:

    pthread_t  m_thread;
    std::tr1::shared_ptr<Runnable> m_sharedPointer;
    threadState         m_state;

};

} // namespace advcpp

#endif //THREAD_H