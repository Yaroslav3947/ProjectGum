#include <Kohut.hpp>

void printHeadline();
void inputPatients();
void printPatient(const Patient &patient);
void addPatientToBinaryFile(Patient patient);
void savePatientsToBinaryFile(Patient *patients, int size);
void readPatientsFromBinaryFile();
void saveResultToTextFile(const Patient *patients, int size, ReportType reportType);