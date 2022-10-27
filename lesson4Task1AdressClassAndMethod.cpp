#include <cstring>
#include <fstream>
#include <iostream>

class Adress {

    std::string cityName;
    std::string streetName;
    int homeNumber;
    int appartNumber;

public:
    Adress() {
        cityName = "город";
        streetName = "улица", homeNumber = 0;
        appartNumber = 0;
    }

    Adress(std::string cityName, std::string streetName, int homeNumber,
        int appartNumber) {
        this->cityName = cityName;
        this->streetName = streetName, this->homeNumber = homeNumber;
        this->appartNumber = appartNumber;
    }

    std::string GetcityName() { return cityName; }

    std::string GetstreetName() { return streetName; }

    int GethomeNumber() { return homeNumber; }

    int GetappartNumber() { return appartNumber; }

    void SetcityName(std::string cityName) { this->cityName = cityName; }

    void SetstreetName(std::string streetName) { this->streetName = streetName; }

    void SethomeNumber(int homeNumber) { this->homeNumber = homeNumber; }

    void SetappartNumber(int appartNumber) { this->appartNumber = appartNumber; }

    /*void SetreadInTheFile(std::ifstream inArr1) {

      inArr >> cityName;
      inArr >> streetName;
      inArr >> homeNumber;
      inArr >> appartNumber;
    }*/
};

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Rus");

    Adress adr;

    std::ifstream inArr("in.txt");
    std::ofstream outArr("out.txt");

    if (!inArr.is_open()) {
        std::cout << "the file was opened with an error" << std::endl;
    }

    if (inArr.is_open()) {

        int numberOfCycles;
        std::string cityName;
        std::string streetName;
        int homeNumber;
        int appartNumber;

        inArr >> numberOfCycles;

        //adr.SetreadInTheFile(std::ifstream inArr);

        Adress* adressArr = new Adress[numberOfCycles];

        for (int i = 0; i < numberOfCycles; i++) {

            inArr >> cityName;
            inArr >> streetName;
            inArr >> homeNumber;
            inArr >> appartNumber;
            adr.SetcityName(cityName);
            adr.SetstreetName(streetName);
            adr.SethomeNumber(homeNumber);
            adr.SetappartNumber(appartNumber);

            adressArr[i] = Adress(cityName, streetName, homeNumber, appartNumber);
            // adressArr[i] = adr.SetreadInTheFile();
        };



        for (int i = 0; i <= numberOfCycles; i++) {
            std::cout << adr.GetcityName() << adr.GetstreetName() << adr.GethomeNumber() << adr.GetappartNumber() << std::endl;
        };

        delete[]adressArr;
    }
}