#ifndef CYBER_PC
#define CYBER_PC
#include <iostream>
#include <string>
#include "../include/CyberWorm.h"
#include "../include/CyberDNS.h"

class CyberDNS;

class CyberPC
{
private:
    const std::string cyber_pc_os_;
    const std::string cyber_pc_name_;
    int cyber_pc_time_to_infect_;
    CyberWorm * cyber_worm_ = NULL;
    std::vector<std::string> cyber_pc_connections_;


    CyberPC();

public:
    CyberPC(std::string cyber_pc_os, std::string cyber_pc_name);
    const std::string getName();
	void AddConnection(std::string  second_pc);
	void Infect(CyberWorm & worm);
	void Run(const CyberDNS & server);
	void Disinfect();
	~CyberPC();


};


#endif
