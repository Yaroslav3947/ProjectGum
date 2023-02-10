#include <Mantur.hpp>

void printPatient(const Patient &patient) {
    ////TODO: change \t to setw() (#include <iomanip>)
    std::cout << patient.ID << "\t" << patient.surname << "\t" << patient.name << "\t" << patient.yearOfBirth
              << "\t" << patient.gender << "\t" << patient.hemoglobin << "\t" << patient.temperature << std::endl;
}

void printHeadline() {
    ////TODO: implement function
}
void savePatientsToBinaryFile(Patient *patients, int size) {
    const std::string pathToBinaryFile = "patients.bin";
    std::ofstream binaryFile(pathToBinaryFile, std::ios::binary | std::ios::out);
    if (!binaryFile) {
        std::cerr << "Can't open binary file\n";
        return;
    }

    ////TODO: implement the rest of function
    binaryFile.close();
}

void addPatientToBinaryFile(Patient patient) {
    const std::string pathToBinaryFile = "patients.bin";
    std::ofstream binaryFile(pathToBinaryFile, std::ios::binary | std::ios::app);
    if (!binaryFile) {
        std::cerr << "Can't open binary file\n";
        return;
    }

    ////TODO: implement the rest of function
    binaryFile.close();
}
void inputPatients() {

    ////TODO: implement function

    /*
        1. Ask for number of patients to input and save them to the binaryfile with for loop
        2. Use here function void savePatientsToBinaryFile(Patient *patients, int size)
    */
}
void saveResultToTextFile(const Patient *patients, int size, ReportType reportType) {
    const std::string pathToTxtFile = "patients.txt";
    std::ofstream textFile(pathToTxtFile, std::ios::out);
    if (!textFile) {
        std::cerr << "Can't open text file\n";
        return;
    }

    ////TODO: implement the rest of function
    textFile.close();
}
void readPatientsFromBinaryFile() {
    const std::string pathToBinaryFile = "patients.bin";
    std::ifstream binaryFile(pathToBinaryFile, std::ios::binary);
    if (!binaryFile.is_open()) {
        std::cerr << "Error opening file: " << std::endl;
        return;
    }
    Patient patient;
/*
    while (binaryFile.read()) {
        printPatient(patient);
    }
*/
    ////TODO: implement the rest of function
    binaryFile.close();
}