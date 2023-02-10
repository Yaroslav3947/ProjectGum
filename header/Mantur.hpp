#include <Kohut.hpp>
#include <iomanip>
#include <string>

void printHeadline();
void inputPatients(Patient patient, const std::string PATH);
void printPatient(const Patient &patient);
void addPatientToBinaryFile(Patient patient);
void savePatientsToBinaryFile(Patient *patients, int size, const std::string PATH_BIN);
void readPatientsFromBinaryFile();
void saveResultToTextFile(const Patient *patients, int size, ReportType reportType, const std::string PATH_TXT);
