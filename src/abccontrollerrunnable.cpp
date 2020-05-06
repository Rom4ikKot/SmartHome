#include "../include/abccontrollerrunnable.h"

#include <iostream>

namespace advcpp
{
    
advcpp::ABCControllerRunnable::ABCControllerRunnable(advcpp::ABCControllerAgent &a_controlleragent)
:m_controlleragent(a_controlleragent)
{}

advcpp::ABCControllerRunnable::~ABCControllerRunnable()
{}

void advcpp::ABCControllerRunnable::Run()
{
    while (1)
    {
        std::tr1::shared_ptr<advcpp::Event> a;
        m_controlleragent.m_waitable.Dequeue(a);
        if (a->Type() == "STOP")
        {
            break;
        }
        m_controlleragent.Run(a);
    }
}

} // namespace advcpp


