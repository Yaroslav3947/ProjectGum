#include <Kohut.hpp>
#include <Mantur.hpp>
#include <Kostya.hpp>

int main() {
    Patient *patients;
    int size;

    ReportType option;
    do {
        option = static_cast<ReportType>(getOption());   
        switch (option) {
            case ReportType::Records37: {
                displayRecords37(patients, size);
                break;
            }
            case ReportType::ElevatedHemoglobinWomen: {
                displayWomenWithElevatedHemoglobin(patients, size);
                break;
            }
            case ReportType::YoungestNormalTemperatureReducedHemoglobinMen: {
                displayYoungestMenWithNormalTemperatureAndReducedHemoglobin(patients, size);
                break;
            }
            case ReportType::OlderThan40ElevatedHemoglobinDecreasedTemperature: {
                displayOlderThan40WithElevatedHemoglobinAndDecreasedTemperature(patients, size);
                break;
            }
            case ReportType::NormalTemperaturePatients: {
                displayPatientsWithNormalTemperature(patients, size);
                break;
            }
            case ReportType::GenderSortedPatients: {
                sortByGender(patients, size);
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
