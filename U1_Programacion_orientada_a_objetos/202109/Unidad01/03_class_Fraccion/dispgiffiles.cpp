/** dispgiffiles.cpp */
#include <iostream>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include <vector>
//std::vector<std::string> gifFile;
SDL_Window* g_pWindow;
SDL_Renderer* g_pRenderer;

/** dispLAY gif files
 * @param g_pWindow : in, must be initialized before passed
 * @param g_pRenderer : in, must be initialized before passed
 * @param gifFile : in, contain the names of the gif files
 *                  to be shown.
 */
void disp_gif_files(SDL_Window* g_pWindow,SDL_Renderer* g_pRenderer,
                    std::vector<std::string>& gifFile,int x0,int y0)
{
  SDL_Event event;
  int done = 0;
  int x=0,y=0;
  SDL_Texture* m_pTexture=0; // SDL_Texture variable
  SDL_Rect m_sourceRectangle;// the first rectangle
  SDL_Rect m_destinationRectangle;// another rectangle
  SDL_SetRenderDrawColor(g_pRenderer,255,255,255,255);//Fondo blanco
  SDL_RenderClear(g_pRenderer);//Clear the window to black/white
  x=x0;
  y=y0;
  m_sourceRectangle.x=0;
  m_sourceRectangle.y=0;
  for(unsigned int i=0;i<gifFile.size();i++){
    m_pTexture=IMG_LoadTexture(g_pRenderer,&gifFile[i][0]);
    if(m_pTexture==NULL){
      printf("disp_gif_files():Could not load gif file %s:%s\n",
             &gifFile[i][0],SDL_GetError());
      exit(1);
    }
    SDL_QueryTexture(m_pTexture,NULL,NULL,
                   &m_sourceRectangle.w,&m_sourceRectangle.h);
    m_destinationRectangle.x=x;
    m_destinationRectangle.y=y;
    m_destinationRectangle.w=m_sourceRectangle.w;
    m_destinationRectangle.h=m_sourceRectangle.h;
    SDL_RenderCopy(g_pRenderer,m_pTexture,
                  &m_sourceRectangle,&m_destinationRectangle);
    y+=10+m_destinationRectangle.h;
  }
  //Show the window
  SDL_RenderPresent(g_pRenderer);

  while(done==0){
    while ( SDL_PollEvent(&event) ) {
      switch (event.type) {
        case SDL_KEYUP:
          switch (event.key.keysym.sym) {
            case SDLK_LEFT:
              done=1;
              break;
            case SDLK_RIGHT:
              done=1;
              break;
            case SDLK_ESCAPE:
            case SDLK_q:
              /* Drop through to done */
            case SDLK_SPACE:
            case SDLK_TAB:
              done=1;
              break;
            default:
              break;
          }
          break;
        case SDL_MOUSEBUTTONDOWN:
          done=1;
          break;
        case SDL_QUIT:
          done=1;
          break;
        default:
          break;
      }
    }/*end while() of event*/
  }/*end while(done==0)*/
  SDL_DestroyTexture(m_pTexture);
}/*end disp_gif_files()*/

void display_gui(std::vector<std::string>& gifFile,int x0,int y0)
{
  printf("Initial test (SDL2_image)...\n");
  // Inicializamos SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    printf("Could not load SDL: %s\n",SDL_GetError());
    exit(1);
  }
  g_pWindow=SDL_CreateWindow("Chapter 1, Shaun Mitchel SDL Game Development",
                             SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                             640,480,SDL_WINDOW_SHOWN);
  //If the window creation succeded, create our render
  if(g_pWindow){
    g_pRenderer=SDL_CreateRenderer(g_pWindow,-1,0);
  }

  disp_gif_files(g_pWindow,g_pRenderer,gifFile,40,30);

  SDL_DestroyRenderer(g_pRenderer);
  SDL_DestroyWindow(g_pWindow);
  printf("Antes de (SDL2_Quit)...\n");
  //Clean up SDL
  SDL_Quit();
}/*end display_gui()*/
