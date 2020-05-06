#ifndef IAGENT_H__
#define IAGENT_H__

namespace advcpp
{
    
    class IAgent
    {
    public:
        virtual ~IAgent() = 0;

        void Activate();
        void Stop();
    };
}

#endif //end IAGENT_H