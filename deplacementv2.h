
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

typedef struct pmap
{
	int nbmoved;
	SDL_Surface *afficher_pmap;
	SDL_Rect pos_pmap;
	SDL_Surface *afficher_pperso;
	SDL_Rect pos_pperso;
}pmap;	

typedef struct 
{
SDL_Surface *mask;
SDL_Surface *background;
SDL_Surface *ecran;
SDL_Rect pos;
SDL_Rect camera;
}stage;


int Deplacement_personnage(SDL_Event *event,personnage *p,int *continuer,stage *s,pmap *pmap);

