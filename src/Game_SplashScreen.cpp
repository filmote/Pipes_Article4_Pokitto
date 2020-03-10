#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


/* ----------------------------------------------------------------------------
 *  Initialise spalsch screen counter (used to control the heading) ..
 */
void Game::initSplash() { 

  splash_counter = 0;
  gameState = STATE_SPLASH_RENDER;

}


/* ----------------------------------------------------------------------------
 *   Render the Splash screen.
 *   
 *   The pipes are rendered one-by-one to simulate the laying of pipe.  The
 *   rendering function allows the user to press the A button to skip past the
 *   animations or the B button to toggle sounds.
 */
void Game::renderSplash() { 

  if (splash_counter < SPLASH_MAX && (PC::frameCount % 12) == 0) { splash_counter++; }

  renderBackground(splash_counter);

  if (splash_counter >= SPLASH_MAX) {

    PD::setColor(0);
    PD::fillRect(9, 25, 92, 37);
    PD::drawBitmap(10, 26, Heading);
    
  }

  if (PC::buttons.pressed(BTN_A)) {
    gameState = STATE_LEVEL_SELECT;
  }
  
}
