#ifndef PUBLISHERRUN_H__
#define PUBLISHERRUN_H__

#include "runnable.h"
#include "publisher.h"

namespace advcpp
{
class Publisher;
class PublisherRun :public Runnable 
{

public:
    PublisherRun(Publisher& a_obj);
    ~PublisherRun();

    virtual void Run();

private:
    Publisher&  m_publisher;
};

} // namespace advcpp

#endif //PUBLISHERRUN_H