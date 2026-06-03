#include <iostream>
#include <algorithm> // Für std::swap

int main() {
    // Array mit 4 unsortierten Zahlen
    int zahlen[4] = {34, 12, 5, 23};
    int n = 4;

    std::cout << "Ausgangs-Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << zahlen[i] << " ";
    }
    std::cout << "\n\n";

    // Selection Sort Algorithmus
    for (int i = 0; i < n - 1; i++) {
        // Nimm an, das aktuelle Element ist das kleinste
        int min_index = i;

        // Suche das tatsächlich kleinste Element im restlichen Array
        for (int j = i + 1; j < n; j++) {
            if (zahlen[j] < zahlen[min_index]) {
                min_index = j; // Neuen Index des kleinsten Elements merken
            }
        }

        // Tausche das kleinste gefundene Element mit dem Element an der Position i
        if (min_index != i) {
            std::swap(zahlen[i], zahlen[min_index]);
        }

        // Zwischenschritt anzeigen
        std::cout << "Schritt " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            std::cout << zahlen[k] << " ";
        }
        std::cout << "\n";
    }

    // Endergebnis ausgeben
    std::cout << "\nSortiertes Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << zahlen[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}