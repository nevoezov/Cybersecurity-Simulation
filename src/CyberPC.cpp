#include <iostream>
#include <string>
#include <vector>
#include "../include/CyberWorm.h"
#include "../include/CyberPC.h"


using namespace std;



CyberPC::CyberPC():
    	cyber_pc_os_ (NULL),
    	cyber_pc_name_ (NULL),
    	cyber_pc_time_to_infect_ (-1),
    	cyber_worm_ (NULL),
    	cyber_pc_connections_(NULL) {}



CyberPC::CyberPC(std::string cyber_pc_os, std::string cyber_pc_name):
    	cyber_pc_os_ (cyber_pc_os),
    	cyber_pc_name_ (cyber_pc_name),
    	cyber_pc_time_to_infect_ (1),
    	cyber_worm_ (NULL){}


    const std::string CyberPC::getName(){
    	return this->cyber_pc_name_;
    }


    void CyberPC::AddConnection(std::string  second_pc){
    	cyber_pc_connections_.push_back(second_pc);
    	std::cout<<"\t"<<this->getName()<<" now connected to "<< second_pc<<"\n";
    }


    void CyberPC::Infect(CyberWorm & worm){
    	if(cyber_pc_os_== worm.getOS()){
    		if(cyber_worm_!=NULL)
    			delete cyber_worm_;
    		cyber_worm_ = new CyberWorm(worm);
    		cyber_pc_time_to_infect_ = worm.getDormancy();
    		std::cout<<"\t\t"<<cyber_pc_name_<<" now infected by "<< cyber_worm_->getWormName()<<"\n";
    		return;
    	}
    	std::cout <<"\t\tWorm "<< worm.getWormName()<<" is incompatible with "<<cyber_pc_name_<<"\n";
    }


    void CyberPC::Run(const CyberDNS & server){

    	if(cyber_pc_time_to_infect_ <=0 && cyber_worm_!= NULL){
    		cout << "\t" << cyber_pc_name_ << " infecting..." <<std::endl;
    		std::vector<std::string>::iterator it;
    		for(it = cyber_pc_connections_.begin(); it != cyber_pc_connections_.end(); ++it){
    			server.GetCyberPC(*(it)).Infect(*cyber_worm_);
    		}
    	}
    	else
    		if(cyber_worm_!= NULL)
    			cout << "\t" << cyber_pc_name_ << ": Worm " << cyber_worm_->getWormName()<< " is dormant" << std::endl;
    	cyber_pc_time_to_infect_--;
    }

    void CyberPC::Disinfect(){
    	if(cyber_worm_!=NULL){
    		std::cout << "\t\t Worm "<<cyber_worm_->getWormName()<<" successfully removed from "<< cyber_pc_name_<<std::endl;
    		delete cyber_worm_;
    		cyber_worm_ = NULL;
    		cyber_pc_time_to_infect_=-1;

    	}
    	else return;
    }
    CyberPC::~CyberPC(){
    	delete cyber_worm_;
    }




