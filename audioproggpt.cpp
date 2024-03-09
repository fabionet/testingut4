#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>

// Function to process audio data with gain
float processAudio(float input, float gain) {
    return input * gain;
}

int main() {
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
}