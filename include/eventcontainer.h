#ifndef EVENTCONTAINER_H__
#define EVENTCONTAINER_H__


#include "ienq.h"
#include "ideq.h"
#include "uncopyable.h"

#include "event.h"
#include "waitablequeue.h"


namespace advcpp
{

class EventContainer :public IenQ , public IdeQ ,public Uncopyable
{

public:
    EventContainer();
    ~EventContainer();

    //FUNCTIONS
    virtual void Enqueue(std::tr1::shared_ptr<Event> const& a_obj);
    virtual void Dequeue(std::tr1::shared_ptr<Event> & a_obj);

private:
    WaitableQueue<std::tr1::shared_ptr<Event> >   m_events;
};


} // namespace advcpp


#endif //EVENTCONTAINER_H