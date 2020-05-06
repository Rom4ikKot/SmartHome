#ifndef FACTORY_H__
#define FACTORY_H__

#include <string>
#include <queue>
#include <tr1/memory>

#include "iagent.h"
#include "dlopen.h"

namespace advcpp
{
    class Factory
    {
    public:
        Factory();
        ~Factory();

        // Functions 
        std::vector<IAgent*>* GetAgents(std::queue<std::tr1::shared_ptr<Params> >&  a_params);

    private:
        std::string const& adder(std::string const& a_obj) const;

    private:
        // Parser    m_parser;
        DLOpen       m_open;
        

    };
    
   
    
} // namespace advcpp



#endif //FACTORY_H