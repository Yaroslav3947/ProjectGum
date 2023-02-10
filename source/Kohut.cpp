#include <Kohut.hpp>

void displayRecords37(Patient *patients, int size) {
    const double TEMPERATURE_LIMIT = 37.2;
    bool hasRecords37 = false;

    for (int i = 0; i < size; i++) {
        if (patients[i].temperature > TEMPERATURE_LIMIT) {
            hasRecords37 = true;
            break;
        }
    }
    if(hasRecords37) {
        printHeadline();
        for (int i = 0; i < size; i++) {
            if(patients[i].temperature > TEMPERATURE_LIMIT) {
                printPatient(patients[i]);
            }
        }
    } else {
        std::cout << "No records with temperature greater than" << TEMPERATURE_LIMIT << "were found." << std::endl;
        return;
    }
}

void displayWomenWithElevatedHemoglobin(Patient *patients, int size) {
    const double HEMOGLOBIN_LIMIT = 110.0;
    int hasWomen = false;
    for (int i = 0; i < size; i++) {
        if(patients[i].gender == "Female" && patients[i].hemoglobin > HEMOGLOBIN_LIMIT) {
            hasWomen = 1;
            break;
        }
    }

    if(hasWomen) {
        printHeadline();
        for (int i = 0; i < size; i++) {
            if (patients[i].gender == "Female" && patients[i].hemoglobin > HEMOGLOBIN_LIMIT) {
                printPatient(patients[i]);
            }
        }
    } else {
        std::cout << "No women found with elevated hemoglobin." << std::endl;
        return;
    }
}
void displayYoungestMenWithNormalTemperatureAndReducedHemoglobin(Patient *patients, int size) {
    const double MIN_TEMPERATURE = 36.0;
    const double MAX_TEMPERATURE = 37.2;
    const double MIN_HEMOGLOBIN = 110.0;

    int youngestAge = patients[0].getAge();
    int youngestIndex = patients[0].ID;

    for (int i = 0; i < size; i++) {
        if (patients[i].gender == "Male" && patients[i].temperature >= MIN_TEMPERATURE 
            && patients[i].temperature <= MAX_TEMPERATURE && patients[i].hemoglobin < MIN_HEMOGLOBIN) {
            if (patients[i].getAge() < youngestAge) {
                youngestAge = patients[i].getAge();
                youngestIndex = i;
            }
        }
    }

    if (youngestIndex == -1) {
        std::cout << "No men found with normal temperature and reduced hemoglobin." << std::endl;
        return;
    }

    printHeadline();
    printPatient(patients[youngestIndex]);
}
void displayOlderThan40WithElevatedHemoglobinAndDecreasedTemperature(Patient *patients, int size) {
    const double MIN_HEMOGLOBIN = 110.0;
    const double MIN_TEMPERATURE = 36.0;
    const int MIN_AGE = 40;

    bool hasOlderPatients = false;
    for (int i = 0; i < size; i++) {
        if (patients[i].getAge() > MIN_AGE && patients[i].hemoglobin > MIN_HEMOGLOBIN && patients[i].temperature < MIN_TEMPERATURE) {
            hasOlderPatients = true;
            break;
        }
    }

    if (hasOlderPatients) {
        printHeadline();
        for (int i = 0; i < size; i++) {
            if (patients[i].getAge() > MIN_AGE && patients[i].hemoglobin > MIN_HEMOGLOBIN && patients[i].temperature < MIN_TEMPERATURE) {
                printPatient(patients[i]);
            }
        }
    } else {
        std::cout << "No patients older than " << MIN_AGE << " found with elevated hemoglobin and decreased temperature." << std::endl;
    }
}
int getAgeLimit() {
    int ageLimit;
    std::cout << "Enter age limit: ";
    std::cin >> ageLimit;
    return ageLimit;
}
void displayPatientsWithNormalTemperature(Patient *patients, int size) {
    const int ageLimit = getAgeLimit();
    const double MIN_TEMPERATURE = 36.0;
    const double MAX_TEMPERATURE = 37.2;

    bool hasPeople = false;
    for (int i = 0; i < size; i++) {
        if (patients[i].getAge() < ageLimit && patients[i].temperature >= MIN_TEMPERATURE && patients[i].temperature <= MAX_TEMPERATURE) {
            hasPeople = true;
            break;
        }
    }

    if (hasPeople) {
        printHeadline();
        for (int i = 0; i < size; i++) {
            if (patients[i].getAge() < ageLimit && patients[i].temperature >= MIN_TEMPERATURE && patients[i].temperature <= MAX_TEMPERATURE) {
                std::cout << patients[i].surname << ", good job!" << std::endl;
            }
        }
    } else {
        std::cout << "No patients found with normal temperature." << std::endl;
    }

}
void sortByGender(Patient *patients, int size) {
    printHeadline();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (patients[j].gender > patients[j + 1].gender) {
                Patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
}