#include "Pokitto.h"
#include "PokittoCookie.h"

#include "src/Game.h"
#include "src/utils/GameCookie.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

Game game;
GameCookie cookie;


int main() {


    // Initialise pokitto ..

    cookie.begin("PIPES", sizeof(cookie), (char*)&cookie);

    PC::begin();
    PD::persistence = true;
    PD::setInvisibleColor(0);
    PD::setFont(font3x5);
    PD::setColor(0);


    // Has the cookie been initialised?

    if (cookie.initialised != COOKIE_INITIALISED) {

        cookie.initialise();

    }


    // Play game!

    game.setup(&cookie);

    while (PC::isRunning()) {
    
        if (!PC::update()) continue;
    
        game.loop();
    
    }
    
    return 0;

}