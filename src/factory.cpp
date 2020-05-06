#include "../include/factory.h"
#include "../include/params.h"


#include <typeinfo>
#include <iostream> //for debugging

namespace advcpp
{
    Factory::Factory()
    {}
    
    Factory::~Factory()
    {}

    std::string const& advcpp::Factory::adder(std::string const& a_obj) const
    {
        std::string  temp = "../lib/" +  a_obj + ".so";
        return const_cast<std::string&> (a_obj) = temp;
    }

    std::vector<advcpp::IAgent *> *advcpp::Factory::GetAgents(std::queue<std::tr1::shared_ptr<Params> >&  a_params)
    {
        
        std::vector<advcpp::IAgent *>* container = new std::vector<advcpp::IAgent *>;
        Params  local;
        while (!a_params.empty())
        {
            local = (*(a_params.front()));
            IAgent* a = m_open.GetFunc(adder(local.Type()))(local);
            container->push_back(a);
            a_params.pop();
        }
        
        //send file name to parser //return params array // simulate config parser
        
            /////for testing 
            // Params fireSensorParams ,tempSensorParams ,fireControllerParams ,tempControllerParams;
            // fireSensorParams.Name("SENSORFIRE");
            // fireSensorParams.Location(1,1);
            // fireSensorParams.Type("firesensa");
            // fireSensorParams.Config("FIREDETECT 5");  //typedetetect period

            // fireControllerParams.Name("SENSORFIRE");
            // fireControllerParams.Location(1,1);
            // fireControllerParams.Type("fireconta");
            // fireControllerParams.Config("FIREDETECT 8");    //typedetetect  value to alert

            // tempSensorParams.Name("SENSORTEMP");
            // tempSensorParams.Location(2,2);
            // tempSensorParams.Type("tempsensa");
            // tempSensorParams.Config("F -5 55 5 TEMP"); 

            // tempControllerParams.Name("SENSORTEMP");
            // tempControllerParams.Location(2,2);
            // tempControllerParams.Type("tempconta");
            // tempControllerParams.Config("F -5 55 5 TEMP 60"); // "80 " if below activate heating

            // advcpp::DLOpen::Func func = m_open.GetFunc(adder(fireControllerParams.Type()));
            // IAgent*  a = func(fireControllerParams);
            // container->push_back(a);

            // func = m_open.GetFunc(adder(tempControllerParams.Type()));
            // a = func(tempControllerParams);
            // container->push_back(a);

            // func = m_open.GetFunc(adder(fireSensorParams.Type()));
            // a = func(fireSensorParams);
            // container->push_back(a);

            // func = m_open.GetFunc(adder(tempSensorParams.Type()));
            // a = func(tempSensorParams);
            // container->push_back(a);
        
        return container;
    }

} // namespace advcpp
