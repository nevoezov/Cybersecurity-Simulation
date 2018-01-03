#include <iostream>
#include <string>
#include <vector>
#include "../include/CyberWorm.h"



    	CyberWorm::CyberWorm():cyber_worm_os_ (NULL),cyber_worm_name_ (NULL),cyber_worm_dormancy_time_ (-1) {}


    	CyberWorm::CyberWorm(std::string cyber_worm_os, std::string cyber_worm_name, int cyber_worm_dormancy_time):
    		cyber_worm_os_ (cyber_worm_os),
    		cyber_worm_name_ (cyber_worm_name),
    		cyber_worm_dormancy_time_ (cyber_worm_dormancy_time){}


    	CyberWorm::CyberWorm(const CyberWorm& other): //copy constructor;
				cyber_worm_os_ (other.getOS()),
				cyber_worm_name_ (other.getWormName()),
				cyber_worm_dormancy_time_ (other.getDormancy()){}


    	std::string 	CyberWorm::getOS() const{
    		return this->cyber_worm_os_;
    	}

    	int 	CyberWorm::getDormancy() const{
    		return cyber_worm_dormancy_time_;
    	}

    	std::string 	CyberWorm::getWormName() const{
    		return this->cyber_worm_name_;
    	}

    	CyberWorm::~CyberWorm(){
    	}
