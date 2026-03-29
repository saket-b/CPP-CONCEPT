#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string line = "John,28,Engineer";
    std::stringstream ss(line);
    std::string name, ageStr, occupation;
    int age;

    // Use getline with a comma delimiter
    std::getline(ss, name, ',');
    std::getline(ss, ageStr, ',');
    std::getline(ss, occupation, ',');

    // Convert string to integer
    try {
        age = std::stoi(ageStr);
        std::cout << "Name: " << name << ", Age: " << age << ", Occupation: " << occupation << std::endl;
    } catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << std::endl;
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << std::endl;
    }

    return 0;
}
