//
//  IntroState.hpp
//  Textbox
//
//  Created by Austin Horn on 1/28/23.
//  Copyright © 2023 Austin Horn. All rights reserved.
//

#ifndef IntroState_hpp
#define IntroState_hpp

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Cursor.hpp>

#include "Base/State.hpp"

struct Resources;

class IntroState final : public State
{
public:
    IntroState(StateMachine& machine, sf::RenderWindow& window, Resources& resources, const bool replace = true);

    void pause() override;
    void resume() override;
    void handleEvent() override;
    void update() override;
    void draw() override;

private:
    
    sf::RectangleShape m_background;
    sf::RectangleShape m_fader;
    sf::Color          m_alpha;
    sf::Vector2f       m_current_mouse_position;
};


#endif /* IntroState_hpp */
