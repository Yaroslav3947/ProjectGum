#pragma once

#include <Kohut.hpp>
#include <iomanip>
#include <string>
#include <vector>

void printHeadline();
void inputPatient(Patient &patient, const std::string &PATH);
void inputPatients(const std::string &PATH);
void printPatient(const Patient &patient);
void addPatientToBinaryFile(Patient &patient, const std::string &pathToBinaryFile);
void savePatientsToBinaryFile(Patient *patients, int size, const std::string PATH_BIN);
void readPatientsFromBinaryFile(const std::string PATH_BIN);
std::vector<Patient> getPatientsFromBinaryFile(const std::string &PATH_BIN);
void saveResultToTextFile(const std::string& PATH_BIN, const std::string& PATH_TXT);


