#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <string>
#include <vector>
#include <boost/foreach.hpp>
#include "../include/CyberDNS.h"
#include "../include/CyberPC.h"
#include "../include/CyberWorm.h"
#include "../include/CyberExpert.h"

using boost::property_tree::ptree;

int main(){

	unsigned int currDay = 0, endDay=-1, pcIndex = 0, expertIndex, efficiency;
	std::vector<CyberExpert *> Experts;
	std::vector<std::string> Pcs;
	CyberDNS * server = new CyberDNS();

    boost::property_tree::ptree pt1;
    boost::property_tree::read_xml( "computers.xml", pt1  );

    BOOST_FOREACH( boost::property_tree::ptree::value_type const& node, pt1.get_child("") )
    {
    	CyberPC * pc = new CyberPC(node.second.get<std::string>("os"),node.second.get<std::string>("name"));
    	std::cout<< "Adding to server: " << pc->getName()<<"\n";
    	server->AddPC(*pc);
    	std::cout<< pc->getName()<< " connected to server\n";
    }

    boost::property_tree::ptree pt2;
    boost::property_tree::read_xml( "network.xml", pt2);
    BOOST_FOREACH( boost::property_tree::ptree::value_type const& node, pt2.get_child("") )
        {
        std::string pointA = node.second.get<std::string>("pointA");
        std::string pointB = node.second.get<std::string>("pointB");
        std::cout<<"Connecting "<<pointA<<" to "<< pointB<<"\n";
    	server->GetCyberPC(pointA).AddConnection(pointB);
    	server->GetCyberPC(pointB).AddConnection(pointA);

        }
    boost::property_tree::ptree pt3;
    boost::property_tree::read_xml( "events.xml", pt3);
    Pcs=server->GetCyberPCList();
    BOOST_FOREACH( boost::property_tree::ptree::value_type const& node, pt3.get_child("") )
    {
    	std::cout<<"Day : "<<currDay<<"\n";
    	if (node.first == "hack"){
    		std::string wormOs = node.second.get<std::string>("wormOs");
    		std::string wormName = node.second.get<std::string>("wormName");
    		int wormDormancy = node.second.get< int>("wormDormancy");
    		CyberWorm * worm = new CyberWorm(wormOs,wormName,wormDormancy);
    		std::string pc = node.second.get<std::string>("computer");
    		std::cout<<"\tHack occurred on "<< pc<< "\n";
    		server->GetCyberPC(pc).Infect(*worm);
    		delete worm;
    	}
    	if (node.first == "clock-in"){
    		std::string name = node.second.get<std::string>("name");
    		int workTime = node.second.get<int>("workTime");
    		int restTime = node.second.get<int>("restTime");
    		int efficiency = node.second.get<int>("efficiency");
    		CyberExpert * expert = new CyberExpert (name, workTime,restTime,efficiency);
    		std::cout<<"\tClock-In: "<<expert->getName()<< " began working\n";
    		Experts.push_back(expert);
    		}
    	if (node.first == "termination"){
    		endDay = node.second.get<int>("time");
    	}
    	for(expertIndex = 0; expertIndex<Experts.size();expertIndex++){
    		if(Experts.at(expertIndex)->isNotSmoking()){
    			for(efficiency = Experts.at(expertIndex)->getEfficiency(); pcIndex<Pcs.size()&&efficiency>0; pcIndex++, efficiency--){
    				std::cout <<"\t"<< Experts.at(expertIndex)->getName() << " examining "<< Pcs.at(pcIndex) <<std::endl;
    				server->GetCyberPC(Pcs.at(pcIndex)).Disinfect();
        		}
    			Experts.at(expertIndex)->anotherDayPassed();
        	}
    		else
    			Experts.at(expertIndex)->imFree();
    	}
    	for(pcIndex=0;pcIndex<Pcs.size();pcIndex++){
    		server->GetCyberPC(Pcs.at(pcIndex)).Run(*server);
    	}
       	currDay++;
       	pcIndex = 0;
    }
    for(;currDay<=endDay;currDay++){
    	std::cout<<"Day : "<<currDay<<"\n";
    	for(expertIndex = 0; expertIndex<Experts.size();expertIndex++){
    	    		if(Experts.at(expertIndex)->isNotSmoking()){
    	    			for(efficiency = Experts.at(expertIndex)->getEfficiency(); pcIndex<Pcs.size()&&efficiency>0; pcIndex++, efficiency--){
    	    				std::cout <<"\t"<< Experts.at(expertIndex)->getName() << " examining "<< Pcs.at(pcIndex) <<std::endl;
    	    				server->GetCyberPC(Pcs.at(pcIndex)).Disinfect();
    	        		}
    	    			Experts.at(expertIndex)->anotherDayPassed();
    	        	}
    	    		else
    	    			Experts.at(expertIndex)->imFree();
    	    	}
    	    	for(pcIndex=0;pcIndex<Pcs.size();pcIndex++){
    	    		server->GetCyberPC(Pcs.at(pcIndex)).Run(*server);
    	    	}
    	       	pcIndex = 0;
    }

    for(expertIndex = 0; expertIndex<Experts.size();expertIndex++){
    	delete Experts.at(expertIndex);
    }
    delete server;

	return 0;
}


