#include <Kostya.hpp>

void showOptions() {
    std::cout << "Please choose one of the following options:\n"
        << "1. Input Patients\n"
        << "2. Read Patients from Binary File\n"
        << "3. Copy info from a .bin file to a .txt file\n"
        << "4. Records with age 37\n"
        << "5. Women with elevated Hemoglobin levels\n"
        << "6. Youngest men with normal temperature and reduced Hemoglobin levels\n"
        << "7. People over 40 with elevated Hemoglobin levels and decreased temperature\n"
        << "8. Patients with normal temperature\n"
        << "9. Gender-sorted patients\n"
        << "10. Exit\n";
}

int getOption() {
    int option;
    showOptions();
    std::cout << "Enter option: ";
    std::cin >> option;
    return option; 
}

void isNormalTemperature(double &temperature) {
    const double MAX_TEMPERATURE = 45.0;
    const double MIN_TEMPERATURE = 35.0;
    while (temperature < MIN_TEMPERATURE || temperature > MAX_TEMPERATURE) {
        std::cerr << "Error: temperature must be between " <<  MIN_TEMPERATURE << " and " << MAX_TEMPERATURE << std::endl;
        std::cout << "Enter the temperature again: ";
        std::cin >> temperature;
    }
}

void isNormalYearOfBirth(int &yearOfBirth) {
    const int MAX_YEAR = 2022;
    const int MIN_YEAR = 1900;
    while (yearOfBirth < MIN_YEAR || yearOfBirth > MAX_YEAR) {
        std::cerr << "Error: year of birth must be between " <<  MIN_YEAR << " and " << MAX_YEAR << std::endl;
        std::cout << "Enter the year of birth again: ";
        std::cin >> yearOfBirth;
    }
}

void isNormalHemoglobin(double &hemoglobin) {
    const double MAX_HEMOGLOBIN = 180;
    const double MIN_HEMOGLOBIN = 100;
    while (hemoglobin < MIN_HEMOGLOBIN || hemoglobin > MAX_HEMOGLOBIN) {
        std::cerr << "Error: hemoglobin level must be between " << MIN_HEMOGLOBIN << " and " << MAX_HEMOGLOBIN << std::endl;
        std::cout << "Enter the hemoglobin level again: ";
        std::cin >> hemoglobin;
    }
}
void sortByGender(std::vector<Patient> &patients, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strlen(patients[j].sex) > strlen(patients[j + 1].sex) ) {
                Patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
    
    printHeadline();
    for(const auto patient: patients) {
        printPatient(patient);
    }

}
