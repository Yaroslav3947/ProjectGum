#include <Kohut.hpp>
#include <Mantur.hpp>
#include <Kostya.hpp>

int main() {
    const std::string PATH_BIN = "patients.bin";
    const std::string PATH_TXT = "patients.txt";

    ReportType option;

    std::vector<Patient> patients;
    int size;
    do {
        option = static_cast<ReportType>(getOption());
        switch (option) {
            case ReportType::InputPatients: {
                inputPatients(PATH_BIN);
                break;
            }
            case ReportType::ReadPatientsFromBinaryFile: {
                readPatientsFromBinaryFile(PATH_BIN);
                break;
            }
            case ReportType::writeToTxtFile: {
                saveResultToTextFile(PATH_BIN, PATH_TXT);
                break;
            }
            case ReportType::Records37: {
                std::vector<Patient> patients = getPatientsFromBinaryFile(PATH_BIN);
                int size = patients.size();
                displayRecords37(patients, size);
                break;
            }
            case ReportType::ElevatedHemoglobinWomen: {
                std::vector<Patient> patients = getPatientsFromBinaryFile(PATH_BIN);
                int size = patients.size();
                displayWomenWithElevatedHemoglobin(patients, size);
                break;
            }
            case ReportType::YoungestNormalTemperatureReducedHemoglobinMen: {
                std::vector<Patient> patients = getPatientsFromBinaryFile(PATH_BIN);
                int size = patients.size();
                displayYoungestMenWithNormalTemperatureAndReducedHemoglobin(patients, size);
                break;
            }
            case ReportType::OlderThan40ElevatedHemoglobinDecreasedTemperature: {
                std::vector<Patient> patients = getPatientsFromBinaryFile(PATH_BIN);
                int size = patients.size();
                displayOlderThan40WithElevatedHemoglobinAndDecreasedTemperature(patients, size);
                break;
            }
            case ReportType::NormalTemperaturePatients: {
                std::vector<Patient> patients = getPatientsFromBinaryFile(PATH_BIN);
                int size = patients.size();
                displayPatientsWithNormalTemperature(patients, size);
                break;
            }
            case ReportType::GenderSortedPatients: {
                std::vector<Patient> patients = getPatientsFromBinaryFile(PATH_BIN);
                int size = patients.size();
                sortByGender(patients, size);
                break;
            }
            case ReportType::EXIT: {
                break;
            }
            default: {
                std::cerr << "We don't have this option\n";
                break;
            }
        }
    } while (option != ReportType::EXIT);

    return 0;
}
