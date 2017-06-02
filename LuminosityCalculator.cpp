/* Ian Annase
 * January 21, 2017
 * Calculate the luminosity, precise star type, and habitable zone of a star based on
 * its surface temperature and radius.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

void getStarType(double starTemp, double luminosity);

int main() {
    const double SUNTEMP = 5778.0;
    const double SUNRAD = 432288.0;
    double starTemp = 0.0;
    double starRadius = 0.0;
    double luminosity = 0.0;
    double tempCompare = 0.0;
    double radiusCompare = 0.0;
    int choice = 1;
    
    // ask for user input
    do {
        // menu
        std::cout << "* Luminosity and Star Type Calculator *" << std::endl << std::endl;
        std::cout << "* Luminosity is the total amount of energy that a star radiates each second." << std::endl;
        std::cout << "* Our sun sets the standard with a luminosity of exactly 1." << std::endl;
        std::cout << "* Star Types Range (hot to cold): *--O-B-A-F-G-K-M--*" << std::endl << std::endl;
        std::cout << "Star surface temp range: 2,400 to 60,000 Kelvin" << std::endl;
        std::cout << "Star radius range: 4,000 to 40,000,000 Miles" << std::endl << std::endl;
        std::cout << "What is the surface temperature (in kelvin)?: ";
        std::cin >> starTemp;
        std::cout << "What is the radius (in miles)?: ";
        std::cin >> starRadius;
        std::cout << std::endl;
    
        // calulate luminosity
        tempCompare = pow(starTemp / SUNTEMP, 4);
        radiusCompare = pow(starRadius / SUNRAD, 2);
        luminosity = tempCompare * radiusCompare;
    
        getStarType(starTemp, luminosity);
        
        std::cout << "Enter 0 to quit, or 1 to try again: ";
        std::cin >> choice;
        std::cout << std::endl;
        
        if (choice == 1)
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }
    while (choice != 0);
    
    std::cout << "Thanks for using the luminosity and star type calculator!" << std::endl << std::endl;
    
    return 0;
}

void getStarType(double starTemp, double luminosity)
{
    char type = '\0';
    double percentile = 0.0;
    double habitableInner = 0.0;
    double habitableOuter = 0.0;
    std::string color;
    
    // get star info
    if (starTemp > 2400 && starTemp <= 3500)
    {
        type = 'M';
        percentile = 1 - starTemp / 3500.0;
        color = "Red";
    }
    if (starTemp > 3500 && starTemp <= 5000)
    {
        type = 'K';
        percentile = (starTemp - 3500.0) / 1500.0;
        color = "Orange";
    }
    if (starTemp > 5000 && starTemp <= 6000)
    {
        type = 'G';
        percentile = 1 - (starTemp - 5000.0) / 1000.0;
        color = "Yellow";
    }
    if (starTemp > 6000 && starTemp <= 7500)
    {
        type = 'F';
        percentile = 1 - (starTemp - 6000.0) / 1500.0;
        color = "Yellowish White";
    }
    if (starTemp > 7500 && starTemp <= 10000)
    {
        type = 'A';
        percentile = 1 - (starTemp - 7500.0) / 2500.0;
        color = "White";
    }
    if (starTemp > 10000 && starTemp <= 30000)
    {
        type = 'B';
        percentile = 1 - (starTemp - 10000.0) / 20000.0;
        color = "Bluish White";
    }
    if (starTemp > 30000 && starTemp <= 60000)
    {
        type = 'O';
        percentile = 1 - (starTemp - 30000.0) / 30000.0;
        color = "Blue";
    }
    
    // calculate habitable zone
    habitableInner = sqrt(luminosity/1.1);
    habitableOuter = sqrt(luminosity/0.53);
    
    std::cout << std::setw(15) << "Star type: " << type << std::endl;
    std::cout << std::setw(15) << "Precise Type: " << type << percentile * 10 << std::endl;
    std::cout << std::setw(15) << "Luminosity: " << luminosity << std::endl;
    std::cout << std::setw(15) << "Star color: " << color << std::endl << std::endl;
    
    // human readable form
    std::cout << "Your star is a " << color << " " << type << " type star that is " << luminosity << " times as luminous as our sun." << std::endl;
    std::cout << "The habitable zone for this star is " << habitableInner << " AU to " << habitableOuter << " AU." << std::endl <<std::endl;
    return;
}