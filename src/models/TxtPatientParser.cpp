#include "TxtPatientParser.h"

TxtPatientParser::TxtPatientParser(char delim) : _delim(delim) {}

Object* TxtPatientParser::parse(const std::string& str) const {
    std::stringstream stream(str);
    std::string buffer;
    auto patient = new Patient();

    std::getline(stream, buffer, _delim);
    patient->setId(buffer);

    std::getline(stream, buffer, _delim);
    patient->setName(buffer);

    std::getline(stream, buffer, _delim);
    patient->setGender(buffer);

    std::getline(stream, buffer, _delim);
    patient->setAddress(buffer);

    std::getline(stream, buffer, _delim);
    patient->setPhone(buffer);

    std::getline(stream, buffer, _delim);
    patient->setDob(buffer);

    std::getline(stream, buffer, _delim);
    if (buffer != "null") {
        std::stringstream substream(buffer);
        std::string subbuffer;
        std::unique_ptr<HealthInsurance> insurance = std::make_unique<HealthInsurance>();
        std::getline(substream, subbuffer, ',');
        insurance->setCardNumber(subbuffer);
        std::getline(substream, subbuffer, ',');
        insurance->setIssueDate(subbuffer);
        std::getline(substream, subbuffer, ',');
        insurance->setExpiryDate(subbuffer);
        std::getline(substream, subbuffer, ',');
        insurance->setCoveragePercent(std::stoi(subbuffer));
        patient->setInsuranceCard(std::move(insurance));
    }
    else {
        patient->setInsuranceCard(nullptr);
    }

    std::getline(stream, buffer, _delim);
    if (buffer != "") {
        std::stringstream substream(buffer);
        std::string subbuffer;
        std::vector<std::string> symptoms;
        while (std::getline(substream, subbuffer, ',')) {
            symptoms.push_back(subbuffer);
        }
        patient->setSymptoms(symptoms);
    }
    else
    {
        patient->setSymptoms({});
    }
    return patient;
}
