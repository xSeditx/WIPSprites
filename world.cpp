#include"world.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////// WORLD CLASS //////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

world::world(char *file, int width,int height){

		SIZE.WIDTH  = width;
        SIZE.HEIGHT = height;

		CAMERA.X    =  width / 2; // Change this later on to start with player
		CAMERA.Y    = height / 2;

		CAMERA.VIEWPORT.WIDTH  = SCREENWIDTH;
		CAMERA.VIEWPORT.HEIGHT = SCREENHEIGHT;
}

world::world(int width,int height){
		SIZE.WIDTH  = width;
        SIZE.HEIGHT = height;

		CAMERA.X    =  width / 2;
		CAMERA.Y    = height / 2;

		CAMERA.VIEWPORT.WIDTH  = SCREENWIDTH;
		CAMERA.VIEWPORT.HEIGHT = SCREENHEIGHT;

		SpriteSheet b("NEW.png");
		BLOCKS = &b;
		for (int y = 0;y < 5;y++){
			for (int x = 0;x < 5;x++){
				TILES.push_back(MAKE_Rect(x * 16, y * 16, 16, 16));
			}
		}

		MAP.resize(width * height);
		Entity temp;

		for (int y = 0;y < height;y++){
			for (int x = 0;x < width;x++){
				MAP[x + SIZE.WIDTH * y] = 0;
				if((y%10) == 0) MAP[x + SIZE.WIDTH * y] = 1;
                if((y%10) == 1) MAP[x + SIZE.WIDTH * y] = 2;
                if((y%10) == 2) MAP[x + SIZE.WIDTH * y] = 3;
                if((y%10) == 3) MAP[x + SIZE.WIDTH * y] = 4;
				if((y%10) == 4) MAP[x + SIZE.WIDTH * y] = 5;
				if((y%10) == 5) MAP[x + SIZE.WIDTH * y] = 6;
				if((y%10) == 6) MAP[x + SIZE.WIDTH * y] = 7;
				
				temp.POSITION.X = x * 16;
				temp.POSITION.Y = y * 16;
				temp.SIZE.HEIGHT = 16;
				temp.SIZE.WIDTH = 16;
			}
		}
	 


}

void world::UPDATE(){
	int W = 16; int H = 16;

		for (int y = 0; y <  SCREENHEIGHT; y+=W){
			for (int x = 0; x < SCREENWIDTH; x+=H){
				
				float offsetx = (CAMERA.X%W);
				float offsety = (CAMERA.Y%H);

				float positionx =  ((x-offsetx) + (CAMERA.X)) / (W);
				float positiony =  ((y-offsety) + (CAMERA.Y)) / (H);

				if (positionx < 0)positionx=0;
				if (positionx > SIZE.WIDTH) positionx = SIZE.WIDTH;
				if (positiony < 0)positiony=0;
				if (positiony > SIZE.HEIGHT) positiony = (SIZE.HEIGHT - 1);

				float position  = positionx + SIZE.WIDTH * positiony;
				
				int index = MAP[(int)position];
				SDL_Rect srcrect = TILES[index];//STATE[CURRENT_STATE].FRAMES[STATE[CURRENT_STATE].CURRENT_FRAME]; //{ frames * SPRITE_WIDTH, 0, SPRITE_WIDTH, SPRITE_HEIGHT };
                SDL_Rect dstrect = {x,y, W, H};
                SDL_RenderCopy(SCREEN->RENDER, BLOCKS->SOURCE, &srcrect, &dstrect);
				//TILES.RENDER(index,x - offsetx,y - offsety);
			}
		} 
}
