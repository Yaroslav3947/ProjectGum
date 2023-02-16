#include <Kohut.hpp>
#include <Mantur.hpp>
#include <Kostya.hpp>

int main() {
    const std::string PATH_BIN = "patients.bin";
    const std::string PATH_TXT = "patients.txt";

    ReportType option;

    do {
        option = static_cast<ReportType>(getOption());
        switch (option) {
            case ReportType::InputPatients: {
                logger("Calling InputPatients function: ", PATH_TXT);
                inputPatients(PATH_BIN);
                break;
            }
            case ReportType::ReadPatientsFromBinaryFile: {
                logger("Calling readPatientsFromBinaryFile function: ", PATH_TXT);
                readPatientsFromBinaryFile(PATH_BIN);
                break;
            }
            case ReportType::writeToTxtFile: {
                logger("Calling saveResultToTextFile function: ", PATH_TXT);
                saveResultToTextFile(PATH_BIN, PATH_TXT);
                break;
            }
            case ReportType::Records37: {
                logger("patients = getPatientsFromBinaryFile function: ", PATH_TXT);
                logger("Calling displayRecords37 function: ", PATH_TXT);
                std::vector<Patient> patients = getPatientsFromBinaryFile(PATH_BIN);
                int size = patients.size();
                displayRecords37(patients, size);
                break;
            }
            case ReportType::ElevatedHemoglobinWomen: {
                logger("patients = getPatientsFromBinaryFile function: ", PATH_TXT);
                logger("Calling displayWomenWithElevatedHemoglobin function: ", PATH_TXT);
                std::vector<Patient> patients = getPatientsFromBinaryFile(PATH_BIN);
                int size = patients.size();
                displayWomenWithElevatedHemoglobin(patients, size);
                break;
            }
            case ReportType::YoungestNormalTemperatureReducedHemoglobinMen: {
                logger("patients = getPatientsFromBinaryFile function: ", PATH_TXT);
                logger("Calling displayYoungestMenWithNormalTemperatureAndReducedHemoglobin function: ", PATH_TXT);
                std::vector<Patient> patients = getPatientsFromBinaryFile(PATH_BIN);
                int size = patients.size();
                displayYoungestMenWithNormalTemperatureAndReducedHemoglobin(patients, size);
                break;
            }
            case ReportType::OlderThan40ElevatedHemoglobinDecreasedTemperature: {
                logger("patients = getPatientsFromBinaryFile function: ", PATH_TXT);
                logger("Calling displayOlderThan40WithElevatedHemoglobinAndDecreasedTemperature function: ", PATH_TXT);
                std::vector<Patient> patients = getPatientsFromBinaryFile(PATH_BIN);
                int size = patients.size();
                displayOlderThan40WithElevatedHemoglobinAndDecreasedTemperature(patients, size);
                break;
            }
            case ReportType::NormalTemperaturePatients: {
                logger("patients = getPatientsFromBinaryFile function: ", PATH_TXT);
                logger("Calling displayPatientsWithNormalTemperature function: ", PATH_TXT);

                std::vector<Patient> patients = getPatientsFromBinaryFile(PATH_BIN);
                int size = patients.size();
                displayPatientsWithNormalTemperature(patients, size);
                break;
            }
            case ReportType::GenderSortedPatients: {
                logger("patients = getPatientsFromBinaryFile function: ", PATH_TXT);
                logger("Calling sortByGender function: ", PATH_TXT);

                std::vector<Patient> patients = getPatientsFromBinaryFile(PATH_BIN);
                int size = patients.size();
                sortByGender(patients, size);
                break;
            }
            case ReportType::EXIT: {
                logger("Ending program", PATH_TXT);
                break;
            }
            default: {
                logger("Bad input...", PATH_TXT);
                std::cerr << "We don't have this option\n";
                break;
            }
        }
    } while (option != ReportType::EXIT);

    return 0;
}
