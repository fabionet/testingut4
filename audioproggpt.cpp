#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <SFML/Graphics.hpp>    // Include the SFML graphics header for drawing shapes and text
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

// Function to select ASIO driver
void selectASIODriver(const std::string& driverName) {
    // TODO: Implement driver selection logic
    std::cout << "Selected ASIO driver: " << driverName << std::endl;
}

// Function to select input channel
void selectInputChannel(int channel) {
    // TODO: Implement input channel selection logic
    std::cout << "Selected input channel: " << channel << std::endl;
}

// Function to select output channel
void selectOutputChannel(int channel) {
    // TODO: Implement output channel selection logic
    std::cout << "Selected output channel: " << channel << std::endl;
}

int main() {
    // Initialize input, output, and gain variables
    float input = 0.0f;
    float output = 0.0f;
    float gain = 1.0f;

    // Create SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Audio Program");

    // Create SFML text for gain label
    // ...

    // Create SFML rectangle shape for gain knob
    // ...

    // Create SFML text for input label
    // ...

    // Create SFML rectangle shape for input meter
    // ...

    // Create SFML text for output label
    // ...

    // Create SFML rectangle shape for output meter
    // ...

    // Create SFML text for audio panel button
    #include <SFML/Graphics/Font.hpp> // Include the SFML font header

    // Load the font from a file
    // Declare and initialize audioPanelButton
    sf::Font font; // Declare the font variable
    font.loadFromFile("path/to/font.ttf"); // Load the font from a file

    sf::Text audioPanelButton;
    audioPanelButton.setFont(font);
    audioPanelButton.setCharacterSize(24);
    audioPanelButton.setString("AUDIO PANEL");
    audioPanelButton.setPosition(20, 300);

    // Create SFML text for input channel label
    sf::Text inputChannelLabel;
    inputChannelLabel.setFont(font);
    inputChannelLabel.setCharacterSize(24);
    inputChannelLabel.setString("Input Channel: ");
    inputChannelLabel.setPosition(20, 100);

    // Create SFML text for output channel label
    sf::Text outputChannelLabel;
    outputChannelLabel.setFont(font);
    outputChannelLabel.setCharacterSize(24);
    outputChannelLabel.setString("Output Channel: ");
    outputChannelLabel.setPosition(20, 150);

    // Create SFML text for input channel selection
    sf::Text inputChannelSelection;
    inputChannelSelection.setFont(font);
    inputChannelSelection.setCharacterSize(24);
    inputChannelSelection.setString("1");
    inputChannelSelection.setPosition(200, 100);

    // Create SFML text for output channel selection
    sf::Text outputChannelSelection;
    outputChannelSelection.setFont(font);
    outputChannelSelection.setCharacterSize(24);
    outputChannelSelection.setString("1");
    outputChannelSelection.setPosition(200, 150);

    // Main program loop
    while (window.isOpen()) {
        // ...

        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
        // Handle window close event
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        // Handle button click event
        else if (event.type == sf::Event::MouseButtonPressed) {
            // Add your statement or code block here
        }
            // Add your statement here
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                if (audioPanelButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    // Open audio panel to select ASIO driver, input channel, and output channel
                    std::string selectedDriver = "ASIO Driver"; // Replace with actual driver selection logic
                    int selectedInputChannel = std::atoi(inputChannelSelection.getString().toAnsiString().c_str());
                    int selectedOutputChannel = std::atoi(outputChannelSelection.getString().toAnsiString().c_str());
                    selectASIODriver(selectedDriver);
                    selectInputChannel(selectedInputChannel);
                    selectOutputChannel(selectedOutputChannel);
                }
            }
        }

        // ...

        // Draw audio panel button
        window.draw(audioPanelButton);

        // Draw input channel label
        window.draw(inputChannelLabel);

        // Draw output channel label
        window.draw(outputChannelLabel);

        // Draw input channel selection
        window.draw(inputChannelSelection);

        // Draw output channel selection
        window.draw(outputChannelSelection);

        // ...

        // Update the window
        window.display();
    }

    return 0;
}

// Function to select ASIO driver
/* void selectASIODriver(const std::string& driverName) {
    // TODO: Implement driver selection logic
    std::cout << "Selected ASIO driver: " << driverName << std::endl;
} */

/* int main2() {
    // Initialize input, output, and gain variables
    float input = 0.0f;
    float output = 0.0f;
    float gain = 1.0f;

    // Create SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Audio Program");

    // Create SFML text for gain label
    // ...

    // Create SFML text for gain value label
    // ...

    // Create SFML rectangle shape for gain knob
    // ...

    // Create SFML text for input label
    // ...

    // Create SFML rectangle shape for input meter
    // ...

    // Create SFML text for output label
    // ...

    // Create SFML rectangle shape for output meter
    // ...

    // Create SFML text for audio panel button
    // Define the font
    sf::Font font;

    // Load the font from a file
    // Declare and initialize audioPanelButton
    sf::Text audioPanelButton;

    if (!font.loadFromFile("path/to/font.ttf")) {
        // Handle font loading error
    }

    // Set the font of the audioPanelButton
    audioPanelButton.setFont(font);
    audioPanelButton.setPosition(20, 300);

    // Main program loop
    while (window.isOpen()) {
        // ...

        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
        // Handle window close event
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        // Handle button click event
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                if (audioPanelButton.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                    // Open audio panel to select ASIO driver
                    std::string selectedDriver = "ASIO Driver"; // Replace with actual driver selection logic
                    selectASIODriver(selectedDriver);
                }
            }
        }

        // ...

        // Draw audio panel button
        window.draw(audioPanelButton);

        // ...

        // Update the window
        window.display();
    }

    return 0;
}


// Function to process audio data with gain
float processAudio(float input, float gain) ; {
    return input * gain;
}

int main3() ; {
    // Initialize input, output, and gain variables
    float input = 0.0f;
    float output = 0.0f;
    float gain = 1.0f;

    // Create SFML window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Audio Program");

    // Create SFML text for gain label
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Failed to load font" << std::endl;
        return 1;
    }
    sf::Text gainLabel;
    gainLabel.setFont(font);
    gainLabel.setCharacterSize(24);
    gainLabel.setString("Gain: " + std::to_string(gain));
    gainLabel.setPosition(20, 20);

    // Create SFML rectangle shape for gain knob
    sf::RectangleShape gainKnob(sf::Vector2f(50, 100));
    gainKnob.setFillColor(sf::Color::Red);
    gainKnob.setPosition(20, 60);

    // Create SFML text for input label
    sf::Text inputLabel;
    inputLabel.setFont(font);
    inputLabel.setCharacterSize(24);
    inputLabel.setString("Input: " + std::to_string(input));
    inputLabel.setPosition(20, 140);

    // Create SFML rectangle shape for input meter
    sf::RectangleShape inputMeter(sf::Vector2f(200, 20));
    inputMeter.setFillColor(sf::Color::Green);
    inputMeter.setPosition(20, 180);

    // Create SFML text for output label
    sf::Text outputLabel;
    outputLabel.setFont(font);
    outputLabel.setCharacterSize(24);
    outputLabel.setString("Output: " + std::to_string(output));
    outputLabel.setPosition(20, 220);

    // Create SFML rectangle shape for output meter
    sf::RectangleShape outputMeter(sf::Vector2f(200, 20));
    outputMeter.setFillColor(sf::Color::Blue);
    outputMeter.setPosition(20, 260);

    // Main program loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    if (gainKnob.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                        // Calculate new gain value based on mouse position
                        float newGain = (mousePosition.y - gainKnob.getPosition().y) / gainKnob.getSize().y;
                        gain = std::max(0.0f, std::min(1.0f, newGain));

                        // Update gain label
                        gainLabel.setString("Gain: " + std::to_string(gain));
                    }
                }
            }
        }

        // Clear the window
        window.clear();

        // Draw gain label and knob
        window.draw(gainLabel);
        window.draw(gainKnob);

        // Draw input label
        window.draw(inputLabel);

        // Draw input meter
        inputMeter.setSize(sf::Vector2f(input * 200, 20));
        window.draw(inputMeter);

        // Draw output label
        window.draw(outputLabel);

        // Draw output meter
        outputMeter.setSize(sf::Vector2f(output * 200, 20));
        window.draw(outputMeter);

        // Display the window
        window.display();

        // TODO: Read input from audio source

        // Process audio with gain
        output = processAudio(input, gain);

        // TODO: Write output to audio destination
    }

    return 0;
} */