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
    std::vector<int> applicantIds;
};
struct Candidate {
    int id;
    std::string fullName;
    std::string contactInfo;
    std::string resume;
    std::vector<int> appliedVacancyIds;
};
struct Employer {
    int id;
    std::string companyName;
    std::string industry;
    std::vector<int> createdVacancyIds;
};
#endif 
