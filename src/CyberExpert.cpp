#include <iostream>
#include <string>
#include <vector>
#include "../include/CyberExpert.h"


    CyberExpert::CyberExpert():
    	cyber_expert_name_(NULL),
    	cyber_expert_work_time_ (-1),
    	cyber_expert_rest_time_ (-1),
    	cyber_expert_efficiency_ (-1),
		work_time (0),
		smoke_time (0)
		{}


    CyberExpert::CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_):
    	cyber_expert_name_ (cyber_expert_name_),
    	cyber_expert_work_time_ (cyber_expert_work_time_),
    	cyber_expert_rest_time_ (cyber_expert_rest_time_),
    	cyber_expert_efficiency_ (cyber_expert_efficiency_),
		work_time (cyber_expert_work_time_),
		smoke_time (cyber_expert_rest_time_){}


 	void CyberExpert::Clean(CyberPC & cyber_pc){
 		cyber_pc.Disinfect();
 	}

 	int CyberExpert::getEfficiency() {
 		return cyber_expert_efficiency_;
 	}
 	std::string CyberExpert::getName(){
 		return cyber_expert_name_;
 	}
 	bool CyberExpert::isNotSmoking(){
 		return (work_time>0);
 	}
 	void CyberExpert::anotherDayPassed(){
 		work_time--;
 		if(work_time==0){
 			std::cout<<"\t"<<cyber_expert_name_<<" is taking a break"<<std::endl;
 			smoke_time=cyber_expert_rest_time_;
 		}
 	}

 	void CyberExpert::imFree(){
 		smoke_time--;
 		if(smoke_time==0){
 			work_time=cyber_expert_work_time_;
 			std::cout<<"\t"<<cyber_expert_name_<<" is back to work"<<std::endl;
 		}
 	}
 	CyberExpert::~CyberExpert(){};


