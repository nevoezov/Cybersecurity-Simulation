#include <iostream>
#include <string>
#include <map>
#include "../include/CyberDNS.h"
#include "../include/CyberPC.h"




	CyberDNS::CyberDNS():cyber_DNS_(){}


	void CyberDNS::AddPC(CyberPC & cyber_pc_){
		cyber_DNS_.insert(std::pair< std::string const, CyberPC &>(cyber_pc_.getName(),cyber_pc_));
	}

	CyberPC & CyberDNS::GetCyberPC(const std::string & cyber_pc_name) const{
		return cyber_DNS_.find(cyber_pc_name)->second;
	}

	std::vector<std::string> CyberDNS::GetCyberPCList(){
		std::vector<std::string> myVector;
		std::map<const std::string, CyberPC &>::reverse_iterator it;
		for(it = cyber_DNS_.rbegin(); it!=cyber_DNS_.rend(); ++it)
			myVector.push_back(it->second.getName());
		return myVector;
	}

	CyberDNS::~CyberDNS(){
		std::map<const std::string, CyberPC &>::iterator it;
		for (it=cyber_DNS_.begin(); it!=cyber_DNS_.end(); ++it) {
			delete &(it)->second;
		}
		cyber_DNS_.clear();
	}

