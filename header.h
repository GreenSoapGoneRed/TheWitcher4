#ifndef HEADER2_H_INCLUDED
#define HEADER2_H_INCLUDED


#define ENNEMY_WIDTH 40
#define ENNEMY_HEIGHT 80
#define TIME_BETWEEN_2_FRAMES 6

typedef struct
{
SDL_Rect positionObjet;
}objet;

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

//int Collission(SDL_Rect a,SDL_Rect b); FUCKING WORTHLESS
int Collision(SDL_Rect box1,SDL_Rect box2);
void anim_perso(int *i, SDL_Event *event,personnage *p);
int collision_parfaite(SDL_Surface *bg,int x,int y);
SDL_Color GetPixel(SDL_Surface *bg,int x,int y);
int Collission(SDL_Rect a,SDL_Rect b);

//ALL DIRECTIONS
int collision_droite(SDL_Surface *s,SDL_Surface *masque,SDL_Rect *p,stage *stage1 );
int collision_up(SDL_Surface *s,SDL_Surface *masque,SDL_Rect *p,stage *stage1 );
int collision_gauche(SDL_Surface *s,SDL_Surface *masque,SDL_Rect *p,stage *stage1 );
int collision_gravite(SDL_Surface *s,SDL_Surface *masque,SDL_Rect *p,stage *stage1 );
int collision_gauche_objet(SDL_Surface *s,SDL_Surface *masque,SDL_Rect *p,stage *stage1 );


//SAVE'n'LOAD
void SaveGame(personnage *p,ENNEMY *e,stage *s,FILE *f);
void LoadGame(personnage *p,ENNEMY *e,stage *s,FILE *f);
//MENU
int menu1();
int menu2(SDL_Surface *screen);
void menu3(SDL_Surface *screen,int *config,int *music);
void menu4(SDL_Surface *screen);
//TINY ITTY-BITTY MENUS
int sous_menu_ig(stage s);
//afficher
void afficher_background(SDL_Surface *bg,SDL_Rect *pos,SDL_Surface *screen);
objet init (objet obj,int x1,int y1,int w1,int h1); 
void charger_image(char image[],SDL_Surface *screen,SDL_Surface *sprite,SDL_Rect *positionsprite);
void afficher_personnage(personnage p,char image[],SDL_Surface *screen);
void afficher_objet(objet obj,char lien[],SDL_Surface *screen);
void afficher_vie(vie v,SDL_Surface *screen);
//minimap
void initialiser_pmap(pmap *pmap);
void afficher_pmap(pmap *pmap,SDL_Surface *ecran);
//initialiser
void initialiser_personnage(personnage *p);
SDL_Surface *initialiser_stage(stage *s,char x[]);
//scrolling et deplacement 
void scrolling(personnage *p,stage *stage1 );
void scroll_cam(personnage p,stage *s);
int Deplacement_personnage(SDL_Event *event,personnage *p,int *continuer,stage *s,pmap *pmap);
//charger background ... 
//void loadGame(void);
//quitter SDL ...
//void cleanup();
//les entrees 
//void getInput() ;
//initialiser ennemi
void initializeEnnemy(void);
//afficher ennemi
void drawEnnemy();
//charger + afficher une image
SDL_Surface *loadImage(char *name);
void drawImage(SDL_Surface *image, int x, int y);
//limiter le prog a 60 images par seconde !! importante !!
void delay(unsigned int frameLimit);
// fonctions temporaires pour l'hero !! a changer
//void initializehero(void);
//void drawhero();
//void dohero();
//fonction principale de l'ennemi
void drawanimatedEnnemy();
// entite secondaire
//void initentity();
//void doEntity();

personnage p;
ENNEMY monstre;
//ENTITY entity ;
stage s;

#endif // HEADER2_H_INCLUDED
