#include <iostream>
#include <dlfcn.h>
#include <unistd.h>  //sleep
#include <typeinfo>
#include <vector>

#include "../include/mu_test.h"
#include "../include/abcsensoragent.h"
#include "../include/params.h"
#include "../include/tempsensa.h"
#include "../include/tempconta.h"
#include "../include/event.h"
#include "../include/iagent.h"
#include "../include/subscriptor.h"
#include "../include/firesensa.h"
#include "../include/fireconta.h"
#include "../include/waitablequeue.h"
#include "../include/factory.h"
#include "../include/ienq.h"
#include "../include/ideq.h"
#include "../include/eventcontainer.h"
#include "../include/smarthome.h"
#include "../include/parser_t.h"

using namespace advcpp;

// UNIT(SYSTEM)

//    Params fireSensorParams ,tempSensorParams ,fireControllerParams ,tempControllerParams;
//    fireSensorParams.Name("SENSORFIRE");
//    fireSensorParams.Location(1,1);
//    fireSensorParams.Type("firesensor");
//    fireSensorParams.Config("FIREDETECT 1");  //typedetetect period

//    fireControllerParams.Name("SENSORFIRE");
//    fireControllerParams.Location(1,1);
//    fireControllerParams.Type("firesensor");
//    fireControllerParams.Config("FIREDETECT 0");    //typedetetect period value to alert

//    tempSensorParams.Name("SENSORTEMP");
//    tempSensorParams.Location(2,2);
//    tempSensorParams.Type("tempsensor");
//    tempSensorParams.Config("F -5 55 1 TEMP");

//    tempControllerParams.Name("SENSORTEMP");
//    tempControllerParams.Location(2,2);
//    tempControllerParams.Type("tempsensor");
//    tempControllerParams.Config("F -5 55 1 TEMP 40");


//    std::tr1::shared_ptr<EventContainer>     event ( new EventContainer);
//    std::tr1::shared_ptr<SubScriptor>        sub ( new SubScriptor);
//    std::tr1::shared_ptr<Publisher>          pub   (new Publisher(*event,*sub));    
//    pub->Run();
//    advcpp::ABCControllerAgent::SubScribe(sub.get());
//    advcpp::ABCSensorAgent::SetEventDestination(event.get());
//    std::tr1::shared_ptr<IAgent> fireSensor(new FireSensA(fireSensorParams));
//    std::tr1::shared_ptr<IAgent> tempSensor(new TempSensA(tempSensorParams));
//    std::tr1::shared_ptr<IAgent> fireController(new FireContA(fireControllerParams)); 
//    std::tr1::shared_ptr<IAgent> tempController(new TempContA(tempControllerParams)); 
//    fireController->Activate();
//    tempController->Activate();
//    fireSensor->Activate();
//    tempSensor->Activate();
//    sleep(5);
//    fireSensor->Stop();
//    tempSensor->Stop();
//    std::string payload = "a";
//    std::string type = "STOP";
//    std::pair<int,int> location;
//    location.first = 0;
//    location.second = 0;
//    std::tr1::shared_ptr<Event> stopEvent(new Event (payload, type,  location));
//    event->Enqueue(stopEvent);
//    fireController->Stop();
//    tempController->Stop();

// END_UNIT



UNIT(PARSER)

   parser_t config;
   std::queue<std::tr1::shared_ptr<Params> >* params;
   params = config.Parse("config.txt");
   std::cout << params->size() <<std::endl;
   while (!params->empty())
   {
      std::cout << params->front()->Name() <<std::endl;
      std::cout << params->front()->Location().first <<std::endl;
      std::cout << params->front()->Location().second <<std::endl;
      std::cout << params->front()->Type() <<std::endl ;
      std::cout << params->front()->Config() <<std::endl <<std::endl;
      params->pop();
   }
  

END_UNIT

UNIT(SMARTHOME)

   SmartHome* smartHome = new SmartHome("config.txt");
   sleep(1);
   smartHome->Stop();
   delete smartHome;

END_UNIT


TEST_SUITE(SMARTHOME)
	
   // IGNORE_TEST(SYSTEM)
   IGNORE_TEST(PARSER)
   TEST(SMARTHOME) //TEST SMARTHOME
   
   
		
END_SUITE