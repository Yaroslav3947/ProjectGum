#include <Kohut.hpp>
#include <iomanip>
#include <string>

int getLastID(std::string &PATH);
void printHeadline();
void inputPatients(std::string PATH);
void printPatient(Patient &patient);
void addPatientToBinaryFile(Patient patient, std::string &pathToBinaryFile);
void savePatientsToBinaryFile(Patient *patients, int size, std::string PATH_BIN);
void readPatientsFromBinaryFile(std::string PATH_BIN);
void saveResultToTextFile(Patient *patients, int size, std::string PATH_TXT);
