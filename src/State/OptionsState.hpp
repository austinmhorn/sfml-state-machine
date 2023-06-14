//
//  OptionsState.hpp
//  Textbox
//
//  Created by Austin Horn on 1/28/23.
//  Copyright © 2023 Austin Horn. All rights reserved.
//

#ifndef OptionsState_hpp
#define OptionsState_hpp

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Cursor.hpp>

#include "Base/State.hpp"

class OptionsState final : public State
{
public:
    OptionsState(StateMachine& machine, sf::RenderWindow& window, Resources& resources, const bool replace = true);

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


#endif /* OptionsState_hpp */
