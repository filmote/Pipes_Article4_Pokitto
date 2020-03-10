#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;

#define SCROLLBAR_X          103
#define SCROLLBAR_Y          0
#define SCROLLBAR_WIDTH      6
#define SCROLLBAR_HEIGHT     86


/* ----------------------------------------------------------------------------
 *   Render the backgrpund pipe scene.
 */
void Game::renderBackground(byte counter) { 

  // PD::fillScreen(11);

  // PD::drawBitmap(112,  0, Pipe_Straight_TB_NoFlange);
  // PD::drawBitmap(112, 16, Pipe_Corner_TL);
  // PD::drawBitmap(96,  16, Pipe_Corner_TR_NoFlange);
  // PD::drawBitmap(96,   0, Pipe_Corner_BL);
  // PD::drawBitmap(80,   0, Pipe_Straight_LR_NoFlange);
  // PD::drawBitmap(64,   0, Pipe_Straight_LR);
  // PD::drawBitmap(48,   0, Pipe_Corner_BR);
  // PD::drawBitmap(48,  16, Pipe_Straight_TB_NoFlange);
  // PD::drawBitmap(48,  32, Pipe_Corner_TR_NoFlange);
  // PD::drawBitmap(64,  32, Pipe_Corner_BL);
  // PD::drawBitmap(64,  48, Pipe_Straight_TB_NoFlange);

  // PD::drawBitmap(0,    0, Pipe_Straight_TB_NoFlange);
  // PD::drawBitmap(0,   16, Pipe_Straight_TB);
  // PD::drawBitmap(0,   32, Pipe_Corner_TR_NoFlange);
  // PD::drawBitmap(16,  32, Pipe_Straight_LR);
  // PD::drawBitmap(32,  32, Pipe_Corner_TL);
  // PD::drawBitmap(32,  16, Pipe_Corner_BR);
  // PD::drawBitmap(48,  16, Pipe_Cross_Underlap_NoFlange);
  // PD::drawBitmap(64,  16, Pipe_Straight_LR_NoFlange);
  // PD::drawBitmap(80,  16, Pipe_Corner_BL);
  // PD::drawBitmap(80,  32, Pipe_Corner_TR_NoFlange);
  // PD::drawBitmap(96,  32, Pipe_Straight_LR);
  // PD::drawBitmap(112, 32, Pipe_Straight_LR_NoFlange);

  // PD::drawBitmap(0,    0, Pipe_Cross_Underlap_NoFlange);
  // PD::drawBitmap(16,   0, Pipe_Corner_BL);
  // PD::drawBitmap(16,  16, Pipe_Straight_TB);
  // PD::drawBitmap(16,  32, Pipe_Cross_Overlap_NoFlange);
  // PD::drawBitmap(16,  48, Pipe_Corner_TR_NoFlange);
  // PD::drawBitmap(32,  48, Pipe_Straight_LR);
  // PD::drawBitmap(48,  48, Pipe_Straight_LR_NoFlange);
  // PD::drawBitmap(64,  48, Pipe_Cross_Underlap_NoFlange);
  // PD::drawBitmap(80,  48, Pipe_Straight_LR_NoFlange);
  // PD::drawBitmap(96,  48, Pipe_Corner_BL);

  // PD::drawBitmap(0,  48, Pipe_Corner_BL);

  // PD::drawBitmap(0,  64, Pipe_Tee_TB_R);
  // PD::drawBitmap(16,  64, Pipe_Straight_LR);
  // PD::drawBitmap(32,  64, Pipe_Tee_LR_B);
  // PD::drawBitmap(48,  64, Pipe_Straight_LR);
  // PD::drawBitmap(64,  64, Pipe_Corner_TL);


  // PD::drawBitmap(96,  64, Pipe_Straight_TB);

  // PD::drawBitmap(0,  80, Pipe_Straight_TB);
  // PD::drawBitmap(32,  80, Pipe_Straight_TB);
  // PD::drawBitmap(96,  80, Pipe_Corner_TR_NoFlange);

    PD::fillScreen(11);

  if (counter >= 1) PD::drawBitmap(112,  0, Pipe_Straight_TB_NoFlange);
  if (counter >= 2) PD::drawBitmap(112, 16, Pipe_Corner_TL);
  if (counter >= 3) PD::drawBitmap(96,  16, Pipe_Corner_TR_NoFlange);
  if (counter >= 4) PD::drawBitmap(96,   0, Pipe_Corner_BL);
  if (counter >= 5) PD::drawBitmap(80,   0, Pipe_Straight_LR_NoFlange);
  if (counter >= 6) PD::drawBitmap(64,   0, Pipe_Straight_LR);
  if (counter >= 7) PD::drawBitmap(48,   0, Pipe_Corner_BR);
  if (counter >= 8) PD::drawBitmap(48,  16, Pipe_Straight_TB_NoFlange);
  if (counter >= 9) PD::drawBitmap(48,  32, Pipe_Corner_TR_NoFlange);
  if (counter >= 10) PD::drawBitmap(64,  32, Pipe_Corner_BL);
  if (counter >= 11) PD::drawBitmap(64,  48, Pipe_Straight_TB_NoFlange);

  if (counter >= 12) PD::drawBitmap(64,  64, Pipe_Corner_TL);

  if (counter >= 13) {
   
    PD::drawBitmap(48,  64, Pipe_Straight_LR);
    PD::drawBitmap(32,  64, Pipe_Tee_LR_B);

  }

  if (counter >= 14) {

    PD::drawBitmap(32,  80, Pipe_Straight_TB);
    PD::drawBitmap(16,  64, Pipe_Straight_LR);

  }

  if (counter >= 15) PD::drawBitmap(0,  64, Pipe_Tee_TB_R);

  if (counter >= 16) {

    PD::drawBitmap(0,  48, Pipe_Corner_BL);
    PD::drawBitmap(0,  80, Pipe_Straight_TB);

  }

  if (counter >= 21) PD::drawBitmap(0,    0, Pipe_Straight_TB_NoFlange);
  if (counter >= 22) PD::drawBitmap(0,   16, Pipe_Straight_TB);
  if (counter >= 23) PD::drawBitmap(0,   32, Pipe_Corner_TR_NoFlange);
  if (counter >= 24) PD::drawBitmap(16,  32, Pipe_Straight_LR);
  if (counter >= 25) PD::drawBitmap(32,  32, Pipe_Corner_TL);
  if (counter >= 26) PD::drawBitmap(32,  16, Pipe_Corner_BR);
  if (counter >= 27) PD::drawBitmap(48,  16, Pipe_Cross_Underlap_NoFlange);
  if (counter >= 28) PD::drawBitmap(64,  16, Pipe_Straight_LR_NoFlange);
  if (counter >= 29) PD::drawBitmap(80,  16, Pipe_Corner_BL);
  if (counter >= 30) PD::drawBitmap(80,  32, Pipe_Corner_TR_NoFlange);
  if (counter >= 31) PD::drawBitmap(96,  32, Pipe_Straight_LR);
  if (counter >= 32) PD::drawBitmap(112, 32, Pipe_Straight_LR_NoFlange);

  if (counter >= 37) PD::drawBitmap(0,    0, Pipe_Cross_Underlap_NoFlange);
  if (counter >= 38) PD::drawBitmap(16,   0, Pipe_Corner_BL);
  if (counter >= 39) PD::drawBitmap(16,  16, Pipe_Straight_TB);
  if (counter >= 40) PD::drawBitmap(16,  32, Pipe_Cross_Overlap_NoFlange);
  if (counter >= 41) PD::drawBitmap(16,  48, Pipe_Corner_TR_NoFlange);
  if (counter >= 42) PD::drawBitmap(32,  48, Pipe_Straight_LR);
  if (counter >= 43) PD::drawBitmap(48,  48, Pipe_Straight_LR_NoFlange);
  if (counter >= 44) PD::drawBitmap(64,  48, Pipe_Cross_Underlap_NoFlange);
  if (counter >= 45) PD::drawBitmap(80,  48, Pipe_Straight_LR_NoFlange);
  if (counter >= 46) PD::drawBitmap(96,  48, Pipe_Corner_BL);

  if (counter >= 47) {
    PD::drawBitmap(96,  64, Pipe_Straight_TB);
    PD::drawBitmap(96,  80, Pipe_Corner_TR_NoFlange);
  }

    
}

/* ----------------------------------------------------------------------------
 *   Render the board.
 */
void Game::renderBoard(int xOffset, int yOffset, byte topRow) { 


  // Draw stripey background ..
  
  PD::fillScreen(11);
  

  // Clear background of actual board ..
  
  PD::setColor(8);
  PD::fillRect(xOffset - 2, yOffset - 2 , (puzzle.maximum.x * GRID_WIDTH) + 5, (puzzle.maximum.y * GRID_HEIGHT) + 5);
  PD::setColor(9);
  PD::drawRect(xOffset - 2, yOffset - 2 , (puzzle.maximum.x * GRID_WIDTH) + 5, (puzzle.maximum.y * GRID_HEIGHT) + 5);


  // Draw placed pipes ..
  
  for (int y = 0; y < puzzle.maximum.y; y++) {
      
    for (int x = 0; x < puzzle.maximum.x; x++) {
      
      if (isPipe(x,y)) {
        
        PD::drawBitmap((x * GRID_WIDTH) + xOffset, (y * GRID_HEIGHT) + yOffset, connectors[getPipeValue(x, y)]);

      }
        
    }
      
  }



  // Draw placed nodes ..
  
  for (int y = 0; y < puzzle.maximum.y; y++) {
      
    for (int x = 0; x < puzzle.maximum.x; x++) {
      
      if (isNode(x, y)) {
        
        PD::drawBitmap((x * GRID_WIDTH + 2) + xOffset, (y * GRID_HEIGHT + 2) + yOffset, nodes[getNodeValue(x,y)]);
        
      }
        
    }
      
  }

  
  // Draw grid marks ..
  
  for (int y = 0; y <= puzzle.maximum.y; y++) {
      
    for (int x = 0; x <= puzzle.maximum.x; x++) { 
        
      PD::drawPixel((x * GRID_WIDTH) + xOffset, (y * GRID_HEIGHT) + yOffset, 9);
      
    }
    
  }

  
  // Draw selected cell ..

  PD::setColor(9);

  PD::drawRect((player.highlightedNode.x * GRID_WIDTH) + xOffset, (player.highlightedNode.y * GRID_HEIGHT) + yOffset, GRID_WIDTH, GRID_HEIGHT);


  // Draw scrollbar if one is needed ..

  if (puzzle.slider.unit > 0) {
    
    PD::setColor(0);
    PD::fillRect(SCROLLBAR_X, SCROLLBAR_Y, SCROLLBAR_WIDTH + 1, SCROLLBAR_HEIGHT);
    PD::setColor(9);
    PD::drawRect(SCROLLBAR_X, SCROLLBAR_Y, SCROLLBAR_WIDTH, SCROLLBAR_HEIGHT);
    PD::fillRect(SCROLLBAR_X + 2, SCROLLBAR_Y + 5 + (topRow * puzzle.slider.unit), SCROLLBAR_WIDTH - 3, puzzle.slider.overall);


    // Top arrow ..

    PD::drawBitmap(SCROLLBAR_X + 2, SCROLLBAR_Y + 2, ArrowUp);


    // Bottom arrow ..

    PD::drawBitmap(SCROLLBAR_X + 2, SCROLLBAR_Y + SCROLLBAR_HEIGHT - 3, ArrowDown);

  }
    
}


