


typedef struct 
{
SDL_Surface *mask;
SDL_Surface *background;
SDL_Surface *ecran;
SDL_Rect pos;
SDL_Rect camera;
}stage;

typedef struct
{
int id;
 SDL_Rect position;
 SDL_Surface *sprite;
 vie v; 
 int score;
int vitesse;
 int acceleration;
}personnage;






void scroll_cam(personnage p,stage *s);
void scrolling(personnage *p,stage *stage1 );
