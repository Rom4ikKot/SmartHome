#ifndef ABCSENSORRUNNABLE_H__
#define ABCSENSORRUNNABLE_H__

#include "runnable.h"
#include "publisher.h"
#include "abcsensoragent.h"

namespace advcpp
{
    
class ABCSensorRunnable :public Runnable 
{

public:
    ABCSensorRunnable(ABCSensorAgent  & a_sensoragent);
    ~ABCSensorRunnable();

    virtual void Run();

private:
    ABCSensorAgent &  m_sensoragent;
};

} // namespace advcpp

#endif //ABCSENSORRUNNABLE_H