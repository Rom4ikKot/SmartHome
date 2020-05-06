#include "thread.h"

#include <stdexcept>
#include <sstream>
#include <iostream>
#include <assert.h> 

namespace advcpp
{
    
Thread::Thread(ActionFunc a_func, Context a_arg)
:m_state(TRD_OK)
{
    int error;
    if((error = pthread_create(&m_thread,NULL,a_func,a_arg))!= 0 )
    {
        std::ostringstream temp;
        std::string ret;
        temp << "Thread join error: ";
        temp << error;
        ret = temp.str();
        throw std::runtime_error(ret);
    }
}

void advcpp::Thread::ThreadJoin() 
{
    if (m_state != TRD_OK)
    {
        std::string ret = "Thread not joinable";
        throw std::runtime_error(ret);
    }
    int error;
    if((error = pthread_join(m_thread,NULL)) != 0 )
    {
        std::ostringstream temp;
        std::string ret;
        temp << "Thread join error: ";
        temp << error;
        ret = temp.str();
        throw std::runtime_error(ret);
    }
    m_state = TRD_JOIN;
}

void advcpp::Thread::ThreadDetach()
{
    if (m_state != TRD_OK)
    {
        std::string ret = "Thread not detachable";
        throw std::runtime_error(ret);
    }
    int error;
    if((error = pthread_detach(m_thread)) != 0 )
    {
        std::ostringstream temp;
        std::string ret;
        temp << "Thread detach error: ";
        temp << error;
        ret = temp.str();
        throw std::runtime_error(ret);
    }
    m_state = TRD_DETATCH;
}

void *advcpp::Thread::StartWorkRutine(void* a_obj)
{
    Thread* self = (Thread*)a_obj;
    std::tr1::shared_ptr<advcpp::Runnable> ptr = self->m_sharedPointer;
    try
    {
        ptr->Run();
    }
    catch(const std::exception& e)
    {
        //log
        return 0;
    }
    catch(...)
    {
        //log
        return 0;
    }
    return 0;
}

advcpp::Thread::Thread(std::tr1::shared_ptr<advcpp::Runnable>& a_obj)
:m_sharedPointer(a_obj)
,m_state(TRD_OK)
{
    int error;
    if((error = pthread_create(&m_thread,NULL,StartWorkRutine, this))!= 0 )
    {
        std::ostringstream temp;
        std::string ret;
        temp << "Thread Create error: ";
        temp << error;
        ret = temp.str();
        throw std::runtime_error(ret);
    }
}

advcpp::Thread::~Thread()
{
    assert(m_state!= TRD_OK);
}

} // namespace advcpp
