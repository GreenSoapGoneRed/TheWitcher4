typedef struct 
{
SDL_Surface *mask;
SDL_Surface *background;
SDL_Surface *ecran;
SDL_Rect pos;
SDL_Rect camera;
}stage;
typedef struct{
objet o;
int val;
}vie;
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

typedef struct ENNEMY
{       
SDL_Surface *sprite;       
int x, y;       
int frameNumber, frameTimer;       
int direction ;
int limite;
} ENNEMY;




void SaveGame(personnage *p,ENNEMY *e,stage *s,FILE *f);
void LoadGame(personnage *p,ENNEMY *e ,stage *s,FILE *f);
