//
//  Application.cpp
//  LockedInside
//
//  Created by Austin Horn on 9/30/22.
//  Copyright © 2022 Austin Horn. All rights reserved.
//
#include <cassert> 

#include "Application.hpp"
#include "State/IntroState.hpp"

void Application::run() 
{
    
    loadResources();
    
    // Create window
    m_window.create({ 800, 600 }, "sfml-state-machine", sf::Style::Default);
    m_window.setFramerateLimit(60);
    
    // Load icon
    sf::Image icon = load_icon();
    
    // Set icon
    m_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Initialize state machine
    m_machine.run(StateMachine::build<IntroState>(m_machine, m_window, m_resources, true));
    
    // Main loop
    while (m_machine.running())
    {
        m_machine.nextState();
        m_machine.update();
        m_machine.draw();
    }

    // Leaving the scope of 'Application' will cleanup the state machine
}

void Application::loadResources() 
{

}
