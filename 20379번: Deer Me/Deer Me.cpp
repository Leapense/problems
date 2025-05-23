#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
    int N;
    cin >> N;

    cout << "         HERD     ADULT     ADULT     MALE     FEMALE     MALE     FEMALE\n";
    cout << "YEAR     SIZE     MALES    FEMALES    FAWNS     FAWNS    NEWBORN   NEWBORN\n";
    cout << "----   -------   -------   -------   -------   -------   -------   -------\n";

    int year = 1994;

    long long ADULT_MALES = 1703;
    long long ADULT_FEMALES = 3714;
    long long MALE_FAWNS = 2058;
    long long FEMALE_FAWNS = 1920;
    long long MALE_NEWBORN = 1372;
    long long FEMALE_NEWBORN = 1280;
    long long HERD_SIZE = 9395;

    cout << year << setw(10) << HERD_SIZE << setw(10) << ADULT_MALES << setw(10) << ADULT_FEMALES << setw(10) << MALE_FAWNS << setw(10) << FEMALE_FAWNS << setw(10) << MALE_NEWBORN << setw(10) << FEMALE_NEWBORN << endl;

    long long tempMale;
    long long fawnToAdultMale;
    long long fawnToAdultFemale;
    long long newbornTotal;

    MALE_FAWNS = 686;
    FEMALE_FAWNS = 640;

    MALE_NEWBORN = 1372;
    FEMALE_NEWBORN = 1280;

    for (int i = 1; i < N; i++) {
        tempMale = floor(ADULT_MALES * 0.9);
        ADULT_MALES = floor(tempMale * 0.25);
        ADULT_FEMALES = floor(ADULT_FEMALES * 0.9);

        fawnToAdultMale = floor(MALE_FAWNS * 0.6);
        ADULT_MALES = ADULT_MALES + fawnToAdultMale;

        fawnToAdultFemale = floor(FEMALE_FAWNS * 0.6);
        ADULT_FEMALES = ADULT_FEMALES + fawnToAdultFemale;

        MALE_FAWNS = floor(MALE_NEWBORN * 0.55);
        FEMALE_FAWNS = floor(FEMALE_NEWBORN * 0.55);

        newbornTotal = floor(ADULT_FEMALES * 1.5);

        MALE_NEWBORN = floor(newbornTotal * 0.52);
        FEMALE_NEWBORN = floor(newbornTotal * 0.48);

        HERD_SIZE = ADULT_MALES + ADULT_FEMALES + MALE_FAWNS + FEMALE_FAWNS + MALE_NEWBORN + FEMALE_NEWBORN;

        cout << (year + i) << setw(10) << HERD_SIZE << setw(10) << ADULT_MALES << setw(10) << ADULT_FEMALES << setw(10) << MALE_FAWNS << setw(10) << FEMALE_FAWNS << setw(10) << MALE_NEWBORN << setw(10) << FEMALE_NEWBORN << endl;
    }

    return 0; 
}