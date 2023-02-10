#include <Mantur.hpp>

int getLastID(const std::string &PATH) {
    Patient lastRecordInfo;
    int lastID = 0;
    std::fstream lastRecord(PATH, std::ios::binary | std::ios::in);
    while (lastRecord.read((char*)&lastRecordInfo, sizeof lastRecordInfo)) {
        lastID = lastRecordInfo.ID;
    }
    lastRecord.close();

    return lastID + 1;
}

void printPatient(const Patient &patient) {
    std::cout << std::setw(20) << std::right << patient.ID << std::setw(20) << std::right << patient.surname << std::setw(20) << std::right << patient.name << std::setw(20) << std::right << patient.yearOfBirth << std::setw(20) << std::right << patient.sex << std::setw(20) << std::right << patient.temperature << std::setw(20) << std::right << patient.hemoglobin << std::endl;
}

void printHeadline() {
    std::cout << std::setw(20) << std::right << "ID" << std::setw(20) << std::right << "surname" << std::setw(20) << std::right << "name" << std::setw(20) << std::right << "yearOfBirth" << std::setw(20) << std::right << "sex" << std::setw(20) << std::right << "temperature" << std::setw(20) << std::right << "hemoglobin" << std::endl;

}
void savePatientsToBinaryFile(Patient *patients, int size, const std::string PATH_BIN) {
    std::ofstream binaryFile(PATH_BIN, std::ios::binary | std::ios::out);
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