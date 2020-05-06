#include <iostream>
#include <dlfcn.h>
#include <unistd.h>  //sleep

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

using namespace advcpp;

UNIT(NEW)

    SubScriptor* sub = new SubScriptor;
    Publisher*  pub = new Publisher(*sub);
     // Activate Publisher
    pub->Run();
    Params    fire;
    Params    tempreture;
    advcpp::ABCSensorAgent::Publish(pub);
    advcpp::ABCControllerAgent::SubScribe(sub);
    // fire ini for both sensor and controller # doesnot have to be the same
    fire.Name("FIRESENSOR");
    fire.Location(1,1);
    fire.Type("FIRESENSOR");
    fire.Config("FIREDETECT");
    // tempreture ini for both sensor and controller # doesnot have to be the same
    tempreture.Name("TEMPRETURE");
    tempreture.Location(2,2);
    tempreture.Type("TEMPRETURE SENSOR");
    tempreture.Config("f -5 55 1 TEMP");
    // Create fire sensor and controller
    FireContA*  fireController = new FireContA(fire );
    fireController -> RunThread();
    FireSensA* fireSensor = new FireSensA(fire );
    fireSensor->RunThread();
    // Create temp sensor and controller
    TempContA* tempretureController = new TempContA(tempreture );
    tempretureController -> RunThread();
    TempSensA* tempretureSensor = new TempSensA(tempreture);
    tempretureSensor -> RunThread();
    
   
   
    // wait threads
    // pthread_join(temp_thread_id, 0);
    sleep(30);

    fireSensor -> Stop();
    tempretureSensor -> Stop();
    pub -> Stop ();
    fireController ->Stop();
    tempretureController -> Stop();
    
    
    delete fireSensor;
    delete tempretureSensor;
    delete pub;
    delete fireController;
    delete tempretureController;
    delete sub;
    

    // std::vector<IAgent*>::iterator it = agentContainer->begin();
    
    
    // for(; it < agentContainer ->end() ; ++it)
    // {
    //    std::cout << typeid(**it).name() <<std::endl;
    // }


END_UNIT




TEST_SUITE(SMARTHOME)
	
    TEST(NEW)
		
END_SUITE