#include <Kohut.hpp>
#include <iomanip>

void printHeadline();
void inputPatients();
void printPatient(const Patient &patient);
void addPatientToBinaryFile(Patient patient, const std::string &pathToBinaryFile);
void savePatientsToBinaryFile(Patient *patients, int size, const std::string PATH_BIN);
void readPatientsFromBinaryFile(const std::string &pathToBinaryFile);
void saveResultToTextFile(const Patient *patients, int size, const std::string &pathToTxtFile);