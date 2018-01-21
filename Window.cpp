
#include"window.h"
#include<windows.h>
#include<iostream>
#include<vector>



#define __DEBUG_

WINDOW *SCREEN ={0};
int WINDOW_OFFSET = 1;
int LEFT_BOUNDS = 0 + WINDOW_OFFSET;
int TOP_BOUNDS = 0 + WINDOW_OFFSET;
int RIGHT_BOUNDS = SCREENWIDTH - WINDOW_OFFSET;
int BOTTOM_BOUNDS = SCREENHEIGHT - WINDOW_OFFSET;



 
WINDOW::WINDOW(int x,int y,int width,int height,char *title){
        X = x;  Y = y;
        WIDTH  = width;
        HEIGHT = height;
        TITLE  = title;
                                                                                                            if(SDL_Init(SDL_INIT_VIDEO) !=0)std::cout << "Init Video Error" << std::endl;
        HWND = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0); if(!HWND)                       std::cout << "ERROR: Initializing SDL Window" << std::endl;
        RENDER = SDL_CreateRenderer(HWND, -1, SDL_RENDERER_ACCELERATED);                                                           if(!RENDER)                     std::cout << "ERROR: Initializing SDL Renderer" << std::endl;
            
        if(SDL_SetRenderDrawColor(RENDER, 0, 0, 0, 255) != 0)std::cout << "Set Color Error" << std::endl;
        
        BACK_BUFFER  = SDL_CreateTexture(RENDER, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
        
        SDL_SetRenderTarget(RENDER, BACK_BUFFER);
        SDL_SetWindowResizable(HWND, SDL_TRUE);
        
        WINDOW_SURFACE   = SDL_GetWindowSurface     (HWND);
        WINDOW_FORMAT    = SDL_GetWindowPixelFormat (HWND);
        
        WINDOW_PIXELS = new Uint32[WIDTH * (HEIGHT + 400) + 1];
        memset(WINDOW_PIXELS, 255, WIDTH * HEIGHT * sizeof(Uint32)); 


//======================ENABLE IMAGE LOADING FOR WINDOW===================================================================================================

}

WINDOW::~WINDOW(){}


 bool LOOP_GAME()
 {
	    bool leftMouseButtonDown = false;
  		SDL_PollEvent(&SCREEN->EVENT);
        switch (SCREEN->EVENT.type)
        {
                case SDL_QUIT:
	          	        return 0;
                break;
	    
                case SDL_MOUSEBUTTONUP:
                        if (SCREEN->EVENT.button.button == SDL_BUTTON_LEFT)
                                 SCREEN->MOUSE_BUTTONS.LEFT = false;
						else  if (SCREEN->EVENT.button.button == SDL_BUTTON_RIGHT)
                                SCREEN->MOUSE_BUTTONS.RIGHT = false;
                        break;
                case SDL_MOUSEBUTTONDOWN:
                        if (SCREEN->EVENT.button.button == SDL_BUTTON_LEFT)
                                SCREEN->MOUSE_BUTTONS.LEFT = true;
						else  if (SCREEN->EVENT.button.button == SDL_BUTTON_RIGHT)
                                SCREEN->MOUSE_BUTTONS.RIGHT = true;

                case SDL_MOUSEMOTION:
                                //int mouseX = SCREEN->EVENT.motion.x;
                                //int mouseY = SCREEN->EVENT.motion.y;
								SCREEN->MOUSE_POSITION.x = SCREEN->EVENT.motion.x;
								SCREEN->MOUSE_POSITION.y = SCREEN->EVENT.motion.y;
                break;
	            case SDL_KEYDOWN:
					            KEYBOARD_HANDLER(SCREEN->EVENT.key.keysym.sym);
				break;
        }
 return 1;
 }
 

void CLS(){
				SDL_UpdateTexture(SCREEN->BACK_BUFFER, NULL, SCREEN->WINDOW_PIXELS, SCREEN->WIDTH * sizeof(Uint32)); // SLOW
				memset(SCREEN->WINDOW_PIXELS, 0, SCREEN->WIDTH * SCREEN->HEIGHT * sizeof(Uint32)); 

}

void SYNC(){
	//    SDL_RenderClear(SCREEN->RENDER);
        SDL_RenderCopy(SCREEN->RENDER, SCREEN->BACK_BUFFER, NULL, NULL);
        SDL_RenderPresent(SCREEN->RENDER);
}



void SET_PIXEL(int x, int y, Uint32 COLOR)
{
	//((Uint32*)pixels)[ x + ( y * SCREEN_WIDTH ) ] = SDL_MapRGB(fmt, 255, 0, 0);
	SCREEN->WINDOW_PIXELS[(y * SCREEN->WIDTH) + x] = COLOR;
}
 
extern void SET_PIXELII   (int x, int y, Uint32 COLOR){

	if (x < 0)x += SCREENWIDTH;
	if (x >= SCREENWIDTH)x -= SCREENWIDTH;
	
		if (y < 0)y += SCREENHEIGHT;
	if (y > SCREENHEIGHT)y -= SCREENHEIGHT;

	SCREEN->WINDOW_PIXELS[(y * SCREEN->WIDTH) + x] = COLOR;

}
 
bool SET_ACTIVE_WINDOW(WINDOW *active)
{
	SCREEN = active;
	return 1;
}

void LOCK_PIXELS(){
	int   PITCH;
	void *PIXELS;
	SDL_LockTexture(SCREEN->BACK_BUFFER, NULL, &PIXELS,  &PITCH);
}
void UNLOCK_PIXELS(){
	SDL_UnlockTexture(SCREEN->BACK_BUFFER);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// VECTOR MANIPULATION /////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float NEWX(float x,float dist,float angle){
		return x + dist * cos(RADIANS(angle));
}

float NEWY(float y,float dist,float angle){
		return y + dist * sin(RADIANS(angle));
}

void  PRINT_SCREEN(char *text){
	std::cout << "ERROR YOU HAVE NOT SETUP THE PRINT FUNCTION FOR SDL YET DUMBASS" << std::endl;
return;
}



HWND MAKE_WIN32GDI(int x,int y,int width,int height,char *title){
	    Print("MAKE_WIN32GDI Is Not Complete. Line 142");
return NULL;
}







//void rotate(float& x, float& y, float angle) {
//          float nx = cos(angle) * x + sin(angle) * y;
//          float ny = cos(angle) * y - sin(angle) * x;
//          x = nx;
//          y = ny;
//}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//SDL_Color color = {0, 0, 0, 0}; // black
/// https://gamedev.stackexchange.com/questions/63617/altering-pixel-value-in-an-sdl2-texture
/// Why you are locking the texture? You shoudn't access texture memory directly, in general accessing GPU memory has low performance. 
///	You should work with SDL_Surface all time then use SDL_UpdateTexture(sdlTexture, NULL, pSurface->pixels, pSurface->pitch); 
/// when your drawing is done, and finally call SDL_RenderCopy(renderer, pTexture, NULL, NULL);

//void *pixels;
//int pitch;
//SDL_PixelFormat *fmt;
//Uint32 format = SDL_GetWindowPixelFormat(window);
//fmt = SDL_AllocFormat(format);

//SDL_LockTexture(pTexture, NULL, &pixels, &pitch);
//((Uint32*)pixels)[ x + ( y * SCREEN_WIDTH ) ] = SDL_MapRGB(fmt, 255, 0, 0);
//SDL_UnlockTexture(pTexture);
//SDL_FreeFormat(fmt);

//http://sdl.5483.n7.nabble.com/SDL-UpdateTexture-vs-Locking-td38080.html



//auto cam_x = std::floor(camera.getCenter().x);
//auto cam_x_tile = cam_x / tileWidth;
//auto tile_width = screen.width / tileWidth;
//for(int x = cam_x_tile - tile_width / 2; x < cam_x_tile + tile_width / 2; ++x)
