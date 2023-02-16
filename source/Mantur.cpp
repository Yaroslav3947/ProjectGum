#include <Mantur.hpp>
#include <Kostya.hpp>

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

void savePatientsToBinaryFile(Patient *patients, int size, const std::string PATH_BIN) {
    std::ofstream binaryFile(PATH_BIN, std::ios::binary | std::ios::out);
    if (!binaryFile) {
        std::cerr << "Can't open binary file\n";
        return;
    }
    binaryFile.write((char*)patients, size * sizeof(Patient));

    binaryFile.close();
}

void addPatientToBinaryFile(Patient &patient, const std::string &pathToBinaryFile) {
    std::ofstream binaryFile(pathToBinaryFile, std::ios::binary | std::ios::app);
    if (!binaryFile) {
        std::cerr << "Can't open binary file\n";
        return;
    }
    binaryFile.write((char*)&patient, sizeof patient);

    binaryFile.close();
}

void inputPatient(Patient &patient, const std::string &PATH) {
    patient.ID = getLastID(PATH);

    std::cin.ignore(); 

    std::cout << "Input surname: "; 
    std::cin.getline(patient.surname, sizeof(patient.surname));
    std::cout << patient.surname << std::endl;
    
    std::cout << "Input name: "; 
    std::cin.getline(patient.name, sizeof(patient.name));
    // std::cout << patient.name << std::endl;
    
    std::cout << "Input year of birth: "; 
    std::cin >> patient.yearOfBirth; 
    // std::cout << patient.yearOfBirth << std::endl;
    isNormalYearOfBirth(patient.yearOfBirth);
    std::cin.ignore();
    
    std::cout << "Input sex: "; 
    std::cin.getline(patient.sex, sizeof(patient.sex));    
    // std::cout << patient.sex << std::endl;
    // isSexOk(patient.sex);
    
    std::cout << "Input temperature: "; 
    std::cin >> patient.temperature;
    isNormalTemperature(patient.temperature);
    // std::cout << patient.temperature << std::endl;
    
    std::cout << "Input hemoglobin: "; 
    std::cin >> patient.hemoglobin;
    isNormalHemoglobin(patient.hemoglobin);
    // std::cout << patient.hemoglobin << std::endl;
    
    std::cout << "Patient added\n";
}


void inputPatients(const std::string &PATH) {
    int n;
    std::cout << "Enter the number of patients to input: ";
    std::cin >> n;

    Patient patient{};
    for (int i = 0; i < n; i++) {
        inputPatient(patient, PATH);
        addPatientToBinaryFile(patient, PATH);
    }
}

void saveResultToTextFile(const Patient *patients, int size, const std::string PATH_TXT) {
    std::ofstream textFile(PATH_TXT, std::ios::out);

    if (!textFile) {
        std::cerr << "Can't open text file\n";
        return;
    }

    textFile << std::setw(20) << std::right << "ID" << std::setw(20) << std::right << "surname" << std::setw(20) << std::right << "name" << std::setw(20) << std::right << "yearOfBirth" << std::setw(20) << std::right << "sex" << std::setw(20) << std::right << "temperature" << std::setw(20) << std::right << "hemoglobin" << std::endl;

    for (int i = 0; i < size; i++) {
        const Patient &patient = patients[i];
        textFile << std::setw(20) << std::right << patient.ID << std::setw(20) << std::right << patient.surname << std::setw(20) << std::right << patient.name << std::setw(20) << std::right << patient.yearOfBirth << std::setw(20) << std::right << patient.sex << std::setw(20) << std::right << patient.temperature << std::setw(20) << std::right << patient.hemoglobin << std::endl;
    }

    textFile.close();
}

void saveResultToTextFile(const std::string& PATH_BIN, const std::string& PATH_TXT) {
    std::ifstream bin_file(PATH_BIN, std::ios::binary);

    if (!bin_file) {
        std::cerr << "Error: could not open binary file." << std::endl;
        return;
    }

    // Read patient data from binary file
    std::ofstream txt_file(PATH_TXT);
    Patient patient;

    while(bin_file.read((char*)&patient, sizeof(Patient))) {
        txt_file << std::setw(20) << std::right << patient.ID << std::setw(20) << std::right 
                << patient.surname << std::setw(20) << std::right << patient.name << std::setw(20) <<
                std::right << patient.yearOfBirth << std::setw(20) << std::right << patient.sex <<
                std::setw(20) << std::right << patient.temperature << std::setw(20) << std::right <<
                patient.hemoglobin << std::endl;
    }

    bin_file.close();

    // Write patient data to text file

    txt_file.close();
    bin_file.close();

    std::cout << "Data copied from binary file to text file successfully!" << std::endl;
}

void readPatientsFromBinaryFile(const std::string PATH_BIN) {
    std::ifstream binaryFile(PATH_BIN, std::ios::binary);

    if (!binaryFile.is_open()) {
        std::cerr << "Error opening file: " << std::endl;
        return;
    }

    printHeadline();

    Patient patient;
    while (binaryFile.read((char*)&patient, sizeof patient)) {
        printPatient(patient);
    }

    binaryFile.close();
}

std::vector<Patient> getPatientsFromBinaryFile(const std::string &PATH_BIN) {
    std::ifstream bin_file(PATH_BIN, std::ios::binary);

    std::vector<Patient> patients {};

    if (!bin_file) {
        std::cerr << "Error: could not open binary file." << std::endl;
    } else {
        int num_patients{0};
        Patient patient;
        while (bin_file.read((char*)&patient, sizeof(Patient))) {
            patients.push_back(patient);
        }
        bin_file.close();
    }
    return patients;
    
}