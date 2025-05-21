//
//  PlayState.cpp
//  Textbox
//
//  Created by Austin Horn on 1/28/23.
//  Copyright © 2023 Austin Horn. All rights reserved.
//

#include "PlayState.hpp"
#include "IntroState.hpp"
#include "Base/StateMachine.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <iostream>
#include <memory>

PlayState::PlayState(StateMachine& machine, sf::RenderWindow& window, Resources& resources, const bool replace)
    : State{ machine, window, resources, replace }
    , m_alpha{ 0, 0, 0, 255 }
{
    const auto window_size = sf::Vector2f{ window.getSize() };

    // Fill the background with blue
    m_background.setFillColor(sf::Color::Blue);
    m_background.setSize(window_size);
    
    // Fill the fader surface with black
    m_fader.setFillColor(m_alpha);
    m_fader.setSize(window_size);
    
    std::cout << "PlayState Init" << std::endl;
}

void PlayState::pause()
{
    std::cout << "PlayState Pause" << std::endl;
}

void PlayState::resume()
{
    std::cout << "PlayState Resume" << std::endl;
}

void PlayState::handleEvent()
{
    while (const std::optional<sf::Event> event = m_window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            m_machine.quit();
        }
        else if (event->is<sf::Event::MouseMoved>())
        {
            sf::Vector2i localPosition = sf::Mouse::getPosition(m_window);
            m_current_mouse_position = m_window.mapPixelToCoords(localPosition);
        }
        else if (event->is<sf::Event::MouseButtonPressed>())
        {
            // Handle mouse button pressed
        }
        else if (event->is<sf::Event::MouseButtonReleased>())
        {
            // Handle mouse button released
        }
        else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            switch (keyPressed->scancode)
            {                    
                case sf::Keyboard::Scancode::Escape:
                    m_next = StateMachine::build<IntroState>(m_machine, m_window, m_resources, true);
                    break;

                default:
                    break;
            }
        }
    }
}

void PlayState::update()
{
    static const auto clock = sf::Clock{};
    static auto last_frame_time = sf::Time{};
    const auto delta_time = clock.getElapsedTime() - last_frame_time;
    last_frame_time = clock.getElapsedTime();
    
    handleEvent();

    if (m_alpha.a != 0)
        m_alpha.a--;

    m_fader.setFillColor(m_alpha);
}

void PlayState::draw()
{
    m_window.clear();
    
    m_window.draw(m_background);

    if (m_alpha.a != 0)
        m_window.draw(m_fader);

    m_window.display();
}


