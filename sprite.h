#pragma once
#include <SDL.h>
#include "window.h"
#include<vector>
#include<iostream>
#include<SDL_IMAGE.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// TypeDefs so that all that is needed it is to change this if a Library change is needed
#ifdef _SDL_
        typedef SDL_Rect     Rect;
        typedef SDL_Surface  Surface;
        typedef SDL_Texture  Texture;
        typedef unsigned int uint;
#endif

class SpriteSheet{
public:
	    SpriteSheet(){}
       ~SpriteSheet(){}
        SpriteSheet(char *file);
	    
	    char    *SOURCE_FILE;
	    Surface *IMAGE;
	    Texture *SOURCE;
};

class State{
public:
	    State(){}
	    ~State(){}
	    State(Rect sourcerect,uint numframes);
	    State(uint x, uint y,uint w,uint h,uint numframes);
	    std::vector<Rect>FRAMES;
	    uint TOTAL_FRAMES;
	    uint CURRENT_FRAME;

  std::vector<Rect> operator +=(Rect const& newframe) {
	this->ADD_FRAME(newframe);  
	//return FRAMES;
}
	    private:
			std::vector<Rect>& ADD_FRAME(SDL_Rect frame);
};



class Entity{
public:
	    Entity(){}
       ~Entity(){}

	    Entity(SpriteSheet *source, int numstates);
	    Entity(SpriteSheet *source){*this=Entity(source,1);}	    
	    struct{
	    	  float X,Y,Z;
	    }POSITION;
	    
	    struct{
	    	    int WIDTH,
	    		    HEIGHT;
	    }SIZE;
	    
	    bool SOLID,
	         ANIMATED;
	    
	    SpriteSheet *SOURCE;
	    
        uint TOTAL_STATES;
        std::vector<State> STATE;

	    uint CURRENT_STATE;
public:
	void RENDER();
private:

};

class AniEntity:public Entity{
public:
	  AniEntity(){}
	 ~AniEntity(){}
	  AniEntity(SpriteSheet *source, int numstates): Entity(source,numstates){};
};



extern SDL_Rect  MAKE_Rect(int x,int y, int w, int h);








////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*

struct TILE{
	Rect SOURCE;
	bool IS_SOLID;
};

class TileSheet{
public:
	TileSheet();
	~TileSheet();
	TileSheet(char *file, Rect crop);
	char *SOURCE_FILE;

	Surface *IMAGE;
	Texture *SOURCE;

	Rect TILE_DIMENSIONS;

	std::vector<TILE> TILES;
 
	void PASTE(int index, int x,int y);
};





class Sprite{
public:
	struct{
		float X,Y,Z;
	}POSITION;

	struct{
		int WIDTH,
			HEIGHT;
	}SIZE;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// ANIMATED SPRITES /////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class State{
public:
	State(){}
~State(){}
    State(Rect start, int number_of_frames);

	int NUMBER_OF_FRAMES;

	std::vector<Rect> FRAMES;
};


class AnimatedSprite : public Sprite{
public:
	AnimatedSprite(){}
	~AnimatedSprite(){}
	AnimatedSprite(char *file, int numstates);

	char        *SOURCE_FILE;

	Surface *IMAGE;
	Texture *SOURCE;

	int NUMBER_OF_STATES;
    bool IS_ANIMATING;

	struct{
		int STATE,
			FRAME;
	}CURRENT;

	std::vector<State> STATE;

	void ANIMATE();
	bool CHOP(int numstates,int numframes);

private:

	bool  IS_SOLID;
	bool  COLLISION_TYPE;
	float COLLISION_RADIUS;
};


*/


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// WORLD CLASS //////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




//extern bool CHECK_COLLISION(Sprite sprite1, Sprite sprite2);
 
/*class AniSprite: public SpriteSheet{

	AniSprite(){}
   ~AniSprite(){}

	AniSprite(SpriteSheet *source, int numstates);

	struct{
		unsigned int STATE,
			         FRAME;
	}CURRENT;

	int NUMBER_OF_STATES;
	std::vector<State> STATES;


	State::State(uint x, uint y, uint w, uint h,uint numframes){
		FRAMES.reserve(numframes);
	LOOP(numframes){
		Rect temp;
		temp.x = x;
		temp.y = y;
		temp.w = w;
		temp.h = h;
		FRAMES.emplace_back(temp);
		x += w;
	}
}



};*/


