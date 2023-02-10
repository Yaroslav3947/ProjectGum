#include <Mantur.hpp>

void printPatient(const Patient &patient) {
    ////TODO: change \t to setw() (#include <iomanip>)
    std::cout << patient.ID << "\t" << patient.surname << "\t" << patient.name << "\t" << patient.yearOfBirth
              << "\t" << patient.gender << "\t" << patient.hemoglobin << "\t" << patient.temperature << std::endl;
}

void printHeadline() {
    ////TODO: implement function
}
int getOption() {
    int option;
    std::cout << "Enter option: ";
    std::cin >> option;
    return option; 
}