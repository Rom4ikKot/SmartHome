#ifndef PUBLISHER_H__
#define PUBLISHER_H__

#include "igetsub.h"
#include "event.h"
#include "thread.h"
#include "ideq.h"
#include "publisherrun.h"

#include <vector>

namespace advcpp
{
    class PublisherRun;
    class Publisher 
    {
    public:
        friend class PublisherRun;

        Publisher(IdeQ& a_dequeue  , IGetSub& a_getsub );
        ~Publisher();
        
        void Run();    //  check for future upgrades

    private:
        
        IdeQ&                                                    m_dequeu;
        IGetSub&                                                 m_getsub;
        bool                                                     m_run;
        std::vector<std::tr1::shared_ptr<advcpp::Thread> >       m_threads;  
    };

}

#endif //end PUBLISHER_H
