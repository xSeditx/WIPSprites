#include"Sprite.h"

SpriteSheet::SpriteSheet(char *file):SOURCE_FILE(file){
    	IMAGE = IMG_Load(SOURCE_FILE);
    	if(!IMAGE){
    		    Print("Image Can not be loaded");Print(file);
    	}
    
    	SOURCE = SDL_CreateTextureFromSurface(SCREEN->RENDER,IMAGE);
    	if(!SOURCE){
    		    Print("Texture Can not be made.");Print(file);
    	}
}


Entity::Entity(SpriteSheet *source, int numstates):TOTAL_STATES(numstates), SOURCE(source)
{
	    STATE.reserve(numstates);
	    LOOP(TOTAL_STATES){
	    	    State temp;
	    	    STATE.emplace_back(temp);
	    }
}

State::State(Rect srcrect,uint numframes):TOTAL_FRAMES(numframes){
        CURRENT_FRAME = 0;
    	FRAMES.reserve(numframes);
    	uint x = 0;
    	for(int count = 0;count < (numframes); count++){
    		    Rect temp;
    		    temp.x = x;
    		    temp.y = srcrect.y;
    		    temp.w = srcrect.w;
    		    temp.h = srcrect.h;
    		    FRAMES.emplace_back(temp); //FRAMES += temp; // Remember to get back to fixing the Overloaded Operator so that you can += new frames and states into your frame list.
    		    x += srcrect.w;
    	}
}

void Entity::RENDER(){
	    Uint32 ticks = SDL_GetTicks();
	    if(ANIMATED== true){
                STATE[CURRENT_STATE].CURRENT_FRAME = (ticks / 150) % STATE[CURRENT_STATE].TOTAL_FRAMES;
	    }
	    	    SDL_Rect srcrect = STATE[CURRENT_STATE].FRAMES[STATE[CURRENT_STATE].CURRENT_FRAME]; //{ frames * SPRITE_WIDTH, 0, SPRITE_WIDTH, SPRITE_HEIGHT };
                SDL_Rect dstrect = { POSITION.X, POSITION.Y, SIZE.WIDTH, SIZE.HEIGHT};
                SDL_RenderCopy(SCREEN->RENDER, SOURCE->SOURCE, &srcrect, &dstrect);
}

std::vector<Rect>& State::ADD_FRAME(SDL_Rect frame){
		FRAMES.emplace_back(frame);
	return FRAMES;
}

SDL_Rect  MAKE_Rect(int x,int y, int w, int h){
	SDL_Rect ret;
		ret.x=x;
		ret.y=y;
		ret.h=h;
		ret.w=w;
return ret;
}







/// OLDSHIT.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// TILES SPRITES ////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

TileSheet::TileSheet(){}
TileSheet::~TileSheet(){}

TileSheet::TileSheet(char *file, SDL_Rect crop):SOURCE_FILE(file), TILE_DIMENSIONS(crop){
	
    
	IMAGE = IMG_Load(file);
	int  width = IMAGE->w;
	int	height = IMAGE->h;

	

    SOURCE = SDL_CreateTextureFromSurface(SCREEN->RENDER, IMAGE);
	for(int y = 0;y < height; y+= crop.h){
	        for(int x =0; x < width; x+= crop.w){
				        //SDL_Rect CROP;
						TILE temp;
						temp.SOURCE.x = x;
						temp.SOURCE.y = y;
						temp.SOURCE.w = crop.w;
						temp.SOURCE.h = crop.h;
						TILES.emplace_back(temp);
	        }
	}

}

void TileSheet::PASTE(int index,int x,int y)
{
		SDL_Rect srcrect = TILES[index].SOURCE; //{ frames * SPRITE_WIDTH, 0, SPRITE_WIDTH, SPRITE_HEIGHT };
        SDL_Rect dstrect = { x, y, TILES[index].SOURCE.w, TILES[index].SOURCE.h};
        SDL_RenderCopy(SCREEN->RENDER, SOURCE, &srcrect, &dstrect);
		 
	  //SDL_BlitSurface(IMAGE,&srcrect,SCREEN->WINDOW_SURFACE,&dstrect);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// ANIMATED SPRITES /////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



AnimatedSprite::AnimatedSprite(char *file, int numstates) : SOURCE_FILE(file), NUMBER_OF_STATES(numstates)
{
	
	CURRENT.STATE =0;
	CURRENT.FRAME =0;

	IMAGE = IMG_Load(file);
    SOURCE = SDL_CreateTextureFromSurface(SCREEN->RENDER, IMAGE);

	if(!IMAGE){
		Print("IMAGE Can not be loaded");
		Print(file);
	}
	STATE.reserve(numstates);
	LOOP(NUMBER_OF_STATES){
		State temp;
		STATE.emplace_back(temp);
	}
}




State::State(SDL_Rect start, int number_of_frames) : NUMBER_OF_FRAMES(number_of_frames)
{

	FRAMES.reserve(number_of_frames);
	 
	int offset = start.x;

	LOOP(NUMBER_OF_FRAMES){
		    offset += start.w;
	        SDL_Rect TEMP = {offset, start.y, start.w, start.h };
			FRAMES.emplace_back(TEMP);
	}
}


void AnimatedSprite::ANIMATE()
{
	 Uint32 ticks = SDL_GetTicks();
	if(IS_ANIMATING == true){
        CURRENT.FRAME = (ticks / 100) % STATE[CURRENT.STATE].NUMBER_OF_FRAMES;
	}
		SDL_Rect srcrect = STATE[CURRENT.STATE].FRAMES[CURRENT.FRAME]; //{ frames * SPRITE_WIDTH, 0, SPRITE_WIDTH, SPRITE_HEIGHT };
        SDL_Rect dstrect = { POSITION.X, POSITION.Y, SIZE.WIDTH, SIZE.HEIGHT};
        SDL_RenderCopy(SCREEN->RENDER, SOURCE, &srcrect, &dstrect);


}

bool AnimatedSprite::CHOP(int numstates,int numframes){
	Print("ANIMATEDSPRITE::CHOP - FIX THIS ITS NOT FINISHED");
	int offset = 0;
	for (int s =0;s<4;s++){
	 
	LOOP(4){
		Print(count);
		    offset += SIZE.WIDTH;
	        SDL_Rect TEMP = {offset, (SIZE.WIDTH * s),SIZE.WIDTH, SIZE.WIDTH };
			STATE[s].FRAMES.push_back(TEMP);
	}
	}
	return true;
}

*/
