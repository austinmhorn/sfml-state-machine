//
//  OptionsState.cpp
//  Textbox
//
//  Created by Austin Horn on 1/28/23.
//  Copyright © 2023 Austin Horn. All rights reserved.
//

#include "OptionsState.hpp"
#include "Base/StateMachine.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <iostream>
#include <memory>

OptionsState::OptionsState(StateMachine& machine, sf::RenderWindow& window, Resources& resources, const bool replace)
    : State{ machine, window, resources, replace }
    , m_alpha{ 0, 0, 0, 255 }
{
    const auto window_size = sf::Vector2f{ window.getSize() };

    // Fill the fader surface with black
    m_fader.setFillColor(m_alpha);
    m_fader.setSize(window_size);
    
    std::cout << "OptionsState Init" << std::endl;;
}

void OptionsState::pause()
{
    std::cout << "OptionsState Pause" << std::endl;;
}

void OptionsState::resume()
{
    std::cout << "OptionsState Resume" << std::endl;;
}

void OptionsState::handleEvent()
{
    for (auto event = sf::Event{}; m_window.pollEvent(event);)
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                m_machine.quit();
                break;
                
            case sf::Event::MouseMoved:
                ///< Get new mouse position
                m_current_mouse_position = m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
                                    
                break;
                
            case sf::Event::MouseButtonPressed:
                break;
                
            case sf::Event::MouseButtonReleased:
                break;
                
            case sf::Event::TextEntered:
                break;
                
            default:
                break;
        }
    }
}

void OptionsState::update()
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

void OptionsState::draw()
{
    m_window.clear();

    if (m_alpha.a != 0)
        m_window.draw(m_fader);

    m_window.display();
}
