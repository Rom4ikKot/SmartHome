#ifndef ABCCONTROLLERRUNNABLE_H
#define ABCCONTROLLERRUNNABLE_H

#include "abccontrolleragent.h"
#include "runnable.h"

namespace advcpp
{
    
class ABCControllerRunnable :public Runnable 
{
public:
    ABCControllerRunnable(ABCControllerAgent  & a_controlleragent);
    ~ABCControllerRunnable();

    virtual void Run();
private:
    ABCControllerAgent&  m_controlleragent;
};

} // namespace advcpp

#endif // ABCCONTROLLERRUNNABLE