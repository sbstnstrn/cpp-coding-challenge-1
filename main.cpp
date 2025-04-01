#include <iostream>
#include <Solver.h>

void print_invalid_input() {
    std::cerr << "Ungültige Eingabe. Bitte eine positive ganze Zahl eingeben." << std::endl;
}

int main() {
    unsigned int stages = 0;
    std::cout << "Anzahl der Etappen eingeben (n > 0):" << std::endl;
    std::cin >> stages;

    if (std::cin.fail() || stages <= 0) {
        print_invalid_input();
        return 1;
    }

    unsigned int days = 0;
    std::cout << "Anzahl der Tage eingeben (n > 0):" << std::endl;
    std::cin >> days;

    if (std::cin.fail() || days <= 0) {
        print_invalid_input();
        return 1;
    }

    std::vector<unsigned int> numbers;
    numbers.reserve(stages);

    for (auto i = 0; i < stages; ++i) {
        unsigned int number = 0;
        std::cout << "Zahl fuer Etappe " << i + 1 << " eingeben (n > 0):" << std::endl;
        std::cin >> number;

        if (std::cin.fail() || number <= 0) {
            print_invalid_input();
            return 1;
        }

        numbers.push_back(number);
    }

    Solver solver(numbers, days);
    const auto result = solver.get_partitions();

    std::cout << "Die optimale maximale Strecke ist: " << result.optimal_max << std::endl;
    std::cout << "Die Etappen sind:" << std::endl;
    for (const auto& [key, value] : result.partitions) {
        std::cout << "Etappe " << key << ": ";
        for (const auto& num : value) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
