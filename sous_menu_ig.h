typedef struct 
{
SDL_Surface *mask;
SDL_Surface *background;
SDL_Surface *ecran;
SDL_Rect pos;
SDL_Rect camera;
}stage;


int sous_menu_ig(stage s);
