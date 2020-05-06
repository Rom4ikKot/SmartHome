#include "../include/publisher.h"


#include <utility>
#include <iostream> //for testing

namespace advcpp
{

Publisher::Publisher(IdeQ& a_dequeue  , IGetSub& a_getsub)
:m_dequeu(a_dequeue)
,m_getsub(a_getsub)
{}

Publisher::~Publisher()
{
    m_threads.front()->ThreadJoin();
}

void advcpp::Publisher::Run()
{
    try
    {
        std::tr1::shared_ptr<Runnable> publisherThread(new PublisherRun(*this) ); //creates runnable obj with shared pointer
        std::tr1::shared_ptr<Thread> sharedThread(new Thread(publisherThread)) ;  //create thread with shared pointer that gets runnable
        m_threads.push_back(sharedThread);  //push
    }
    catch(...)
    {
        //log
        throw; // TODO -do i keep throwing or return my own error ??
    }
}

}