#include <iostream>
#include <vector>

// Function to amplify the audio signal
std::vector<double> amplifySignal(const std::vector<double>& signal, double amplificationFactor) {
    std::vector<double> amplifiedSignal;
    for (const auto& sample : signal) {
        amplifiedSignal.push_back(sample * amplificationFactor);
    }
    return amplifiedSignal;
}

int main() {
    // Sample audio signal
    std::vector<double> audioSignal = {0.1, 0.2, 0.3, 0.4, 0.5};

    // Amplification factor
    double amplificationFactor = 2.0;

    // Amplify the audio signal
    std::vector<double> amplifiedSignal = amplifySignal(audioSignal, amplificationFactor);

    // Print the amplified signal
    for (const auto& sample : amplifiedSignal) {
        std::cout << sample << " ";
    }
    std::cout << std::endl;

    return 0;
}