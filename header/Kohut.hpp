#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>

const int MAX_PATIENTS = 100;

enum class ReportType {
    InputPatients = 1,
    ReadPatientsFromBinaryFile,
    writeToTxtFile,
    Records37,
    ElevatedHemoglobinWomen,
    YoungestNormalTemperatureReducedHemoglobinMen,
    OlderThan40ElevatedHemoglobinDecreasedTemperature,
    NormalTemperaturePatients,
    GenderSortedPatients = 9,
    EXIT = 10
};

struct Patient {
    int ID;
    char surname[100];
    char name[100];
    int yearOfBirth;
    char sex[100]; // Male/Female
    double hemoglobin;
    double temperature;
    int getAge() const { const int presentYear = 2023; return presentYear - yearOfBirth;};
};

void displayRecords37(std::vector<Patient> patients, int size);
void displayWomenWithElevatedHemoglobin(std::vector<Patient> patients, int size);
void displayYoungestMenWithNormalTemperatureAndReducedHemoglobin(std::vector<Patient> patients, int size);
void displayOlderThan40WithElevatedHemoglobinAndDecreasedTemperature(std::vector<Patient> patients, int size);
void displayPatientsWithNormalTemperature(std::vector<Patient> patients, int size);
void sortByGender(std::vector<Patient> &patients, int size);

void printPatient(const Patient &patient);
void printHeadline();
