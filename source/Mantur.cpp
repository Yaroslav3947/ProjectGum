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
    binaryFile.write((char*)&patients, sizeof patients);

    binaryFile.close();
}

void addPatientToBinaryFile(Patient patient, const std::string &pathToBinaryFile) {
    // const std::string pathToBinaryFile = "patients.bin";
    std::ofstream binaryFile(pathToBinaryFile, std::ios::binary | std::ios::app);
    if (!binaryFile) {
        std::cerr << "Can't open binary file\n";
        return;
    }
    binaryFile.write((char*)&patient, sizeof patient);

    binaryFile.close();
}
void inputPatients(Patient patient, const std::string PATH) {
    patient.ID = getLastID(PATH);

    std::cin.ignore();
    std::cout << "Input surname: "; getline(std::cin, patient.surname);
    std::cout << "Input name: "; getline(std::cin, patient.name);
    std::cout << "Input year of birth: "; std::cin >> patient.yearOfBirth; std::cin.ignore();
    std::cout << "Input sex: "; getline(std::cin, patient.sex);
    std::cout << "Input temperature: "; std::cin >> patient.temperature;
    std::cout << "Input hemoglobin: "; std::cin >> patient.hemoglobin;

    addPatientToBinaryFile(patient);

    ////TODO: DONE

    /*
        1. Ask for number of patients to input and save them to the binaryfile with for loop
        2. Use here function void savePatientsToBinaryFile(Patient *patients, int size)
    */
}

void saveResultToTextFile(const Patient *patients, int size, ReportType reportType, const std::string PATH_TXT) {
    std::ofstream textFile(PATH_TXT, std::ios::out);

    if (!textFile) {
        std::cerr << "Can't open text file\n";
        return;
    }

    ////TODO: implement the rest of function
    textFile.close();
}

void readPatientsFromBinaryFile(Patient patient, const std::string PATH_BIN) {

    std::ifstream binaryFile(PATH_BIN, std::ios::binary);

    if (!binaryFile.is_open()) {
        std::cerr << "Error opening file: " << std::endl;
        return;
    }
    while (binaryFile.read((char*)&patient, sizeof patient)) {
        printPatient(patient);
    }

    binaryFile.close();
}