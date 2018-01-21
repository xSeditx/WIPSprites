#include"window.h"
#include"World.h"
#include"sprite.h"
#include<SDL_image.h>
#include<iostream>


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// Stuff to Manage later //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float POSX=0,POSY=0;
int GLOBALSTATE = 1,ANIMATING = true;

	int NUMBER_OF_FRAMES = 4;
	int SPRITE_WIDTH = 32;
	int SPRITE_HEIGHT = 32;
  float SPRITE_SPEED = 15; 
  float SPRITE_SCALE = 1;
  float PLAYER_X, PLAYER_Y;


void DRAW_WORLD();
void STUFF_TO_SORT_OUT_LATER();
const int MAPX = 3000, MAPY = 1000;

SpriteSheet *WORLD_TILES;
world *WORLD_MAP;//(MAPX,MAPY);



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
SpriteSheet *FAIRYSHEET;
Entity *FAIRY;




using namespace std;

void main()
{

		WINDOW main(0,0,SCREENWIDTH,SCREENHEIGHT," Animation Practice");
		SET_ACTIVE_WINDOW(&main);

    	bool quit = 0;
    	SDL_Event event;

    	POSX = SCREENWIDTH/2;
    	POSY  = SCREENHEIGHT / 2;
    	
		SpriteSheet FAIRYSHEET("fawwee.png");
    	world WORLD_MAP(MAPX,MAPY);

		//SpriteSheet      TILES("NEW.png");

        AniEntity FAIRY(&FAIRYSHEET, 5);
    	FAIRY.STATE[0] = State(MAKE_Rect(0, 0,SPRITE_WIDTH,SPRITE_HEIGHT),NUMBER_OF_FRAMES);
        FAIRY.STATE[1] = State(MAKE_Rect(0,32,SPRITE_WIDTH,SPRITE_HEIGHT),NUMBER_OF_FRAMES);
        FAIRY.STATE[2] = State(MAKE_Rect(0,64,SPRITE_WIDTH,SPRITE_HEIGHT),NUMBER_OF_FRAMES);
        FAIRY.STATE[3] = State(MAKE_Rect(0,96,SPRITE_WIDTH,SPRITE_HEIGHT),NUMBER_OF_FRAMES);
    
    	FAIRY.ANIMATED = true;
    	FAIRY.POSITION.X = SCREENWIDTH/2;
    	FAIRY.POSITION.Y = SCREENHEIGHT/2;
    	FAIRY.SIZE.HEIGHT = SPRITE_HEIGHT;
    	FAIRY.SIZE.WIDTH = SPRITE_WIDTH;
    
    	while (LOOP_GAME())
        {
    		    ANIMATING = false;
    		    SDL_RenderClear(SCREEN->RENDER);
    		    WORLD_MAP.UPDATE();
				{
				FAIRY.POSITION.X = POSX;
    		    FAIRY.POSITION.Y = POSY;
    		    FAIRY.CURRENT_STATE = GLOBALSTATE;
    		    FAIRY.RENDER();
				}

				
    		    SDL_RenderPresent(SCREEN->RENDER);
    	}
    	
}

void STUFF_TO_SORT_OUT_LATER(){

}


int KEYBOARD_HANDLER(SDL_Keycode sym){
	switch (sym){
	case SDLK_UP:
		   WORLD_MAP->CAMERA.Y -=SPRITE_SPEED;

		   PLAYER_Y -=SPRITE_SPEED;
			GLOBALSTATE = 3;
			ANIMATING = true;
	break;
	case SDLK_DOWN:
		WORLD_MAP->CAMERA.Y +=SPRITE_SPEED;
		PLAYER_Y +=SPRITE_SPEED;
			GLOBALSTATE = 0;
			ANIMATING = true;
	break;
	case SDLK_LEFT:
		WORLD_MAP->CAMERA.X -=SPRITE_SPEED;
		PLAYER_X -=SPRITE_SPEED;
		GLOBALSTATE = 1;
		ANIMATING = true;
	break;
	case SDLK_RIGHT:
		WORLD_MAP->CAMERA.X+=SPRITE_SPEED;
		PLAYER_X +=SPRITE_SPEED;
	    GLOBALSTATE = 2;
		ANIMATING = true;
	break;

	case SDLK_RALT:
		SPRITE_SCALE +=.25;
	break;

	case SDLK_RCTRL:
		SPRITE_SCALE -=.25;
	break;
	
	case SDLK_SPACE:
	break;
	}
	return 0;
}
