#include <Kohut.hpp>
#include <iomanip>
#include <string>

int getLastID(const std::string &PATH);
void printHeadline();
void inputPatients(Patient patient, const std::string PATH);
void printPatient(const Patient &patient);
void addPatientToBinaryFile(Patient patient, const std::string &pathToBinaryFile);
void savePatientsToBinaryFile(Patient *patients, int size, const std::string PATH_BIN);
void readPatientsFromBinaryFile(Patient patient, const std::string PATH_BIN);
void saveResultToTextFile(const Patient *patients, int size, ReportType reportType, const std::string PATH_TXT);
