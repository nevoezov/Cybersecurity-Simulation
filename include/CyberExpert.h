#ifndef CYBER_EXPERT
#define CYBER_EXPERT
#include <iostream>
#include <string>
#include <vector>
#include "../include/CyberPC.h"


class CyberExpert
{
private:
	const std::string 	cyber_expert_name_;
    const int cyber_expert_work_time_;
    const int cyber_expert_rest_time_;
    const int cyber_expert_efficiency_;
    int work_time;
    int smoke_time;
    CyberExpert();


public:
    CyberExpert(std::string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_);
 	void Clean(CyberPC & cyber_pc);
 	std::string getName();
 	int getEfficiency();
 	bool isNotSmoking();
 	void anotherDayPassed();
 	void imFree();
 	~CyberExpert();

};


#endif
