#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>
#include <vector>

struct Vacancy {
    int id;
    std::string title;       
    std::string companyName;     
    std::string description; 
    double salary;           
};

struct Application {
    int vacancyId;
    std::string candidateName;
    std::string resumeText; 
    std::string status;      
};


struct Candidate {
    std::string fullName;
    std::string email;
    std::string skills;      
};


struct Employer {
    std::string companyName;
    std::string industry;   
    std::string contactInfo;
};

#endif 
