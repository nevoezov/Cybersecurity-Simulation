#ifndef CYBER_WORM
#define CYBER_WORM
#include <iostream>
#include <string>
#include <vector>


class CyberWorm
{
private:
    const std::string 	cyber_worm_os_;
    const std::string 	cyber_worm_name_;
    const int cyber_worm_dormancy_time_;
    CyberWorm();


public:
    CyberWorm(std::string cyber_worm_os, std::string cyber_worm_name, int cyber_worm_dormancy_time);
	CyberWorm(const CyberWorm& other);
	std::string getOS() const;
	int getDormancy() const;
	std::string getWormName() const;
	~CyberWorm();

};
#endif
