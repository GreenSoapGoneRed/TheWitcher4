
typedef struct pmap
{
	int nbmoved;
	SDL_Surface *afficher_pmap;
	SDL_Rect pos_pmap;
	SDL_Surface *afficher_pperso;
	SDL_Rect pos_pperso;
}pmap;	

void initialiser_pmap(pmap *pmap);
void afficher_pmap(pmap *pmap,SDL_Surface *ecran);
