#pragma once

#include <Mantur.hpp>

#include <string>
#include <iostream>

const int MAX_PATIENTS = 100;

enum class ReportType {
    ////TODO: make up numbers
    Records37,
    ElevatedHemoglobinWomen,
    YoungestNormalTemperatureReducedHemoglobinMen,
    OlderThan40ElevatedHemoglobinDecreasedTemperature,
    NormalTemperaturePatients,
    GenderSortedPatients,
    EXIT
};

struct Patient {
    int ID;
    std::string surname;
    std::string name;
    int yearOfBirth;
    std::string gender; // Male/Female
    double hemoglobin, temperature;
    int getAge() const { const int presentYear = 2023; return presentYear - yearOfBirth;};
};

void displayRecords37(Patient *patients, int size);
void displayWomenWithElevatedHemoglobin(Patient *patients, int size);
void displayYoungestMenWithNormalTemperatureAndReducedHemoglobin(Patient *patients, int size);
void displayOlderThan40WithElevatedHemoglobinAndDecreasedTemperature(Patient *patients, int size);
void displayPatientsWithNormalTemperature(Patient *patients, int size);
void sortByGender(Patient *patients, int size);
