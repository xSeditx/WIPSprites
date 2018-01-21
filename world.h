#pragma once
#include"window.h"
#include<vector>
#include"Sprite.h"

enum BlockType{
	    Grass,
	    Dirt,
		Stone,
		Bedrock,
		Glass,
		Water,
		Lava
};


class TILE{
	struct{
	        int X,
	        	Y;
	}POS;
	BlockType BLOCK_TYPE;
	Entity    BLOCK;
};


class world{
public:
	    world(){}
	    ~world(){}
	    
        world(char *file, int width,int height);
        world(int width,int height);
	    
	    
	    struct{
	    	    int WIDTH,
	    	    	HEIGHT;
	    }SIZE;
	    
	    struct{
	    	     int X,
	    		     Y;
	    	    struct{
	    		     int WIDTH,
	    			     HEIGHT;
	    	    }VIEWPORT;
	    }CAMERA;
	    
	    std::vector<int>MAP;
	    
	    void UPDATE();
	    SpriteSheet *BLOCKS;

	    std::vector<Rect> TILES;
	    
};	    




