
void initialiser_pmap(pmap *pmap)
{

	pmap->afficher_pmap=NULL;
	pmap->afficher_pmap=IMG_Load("pmap.png");

	pmap->pos_pmap.x=100;
	pmap->pos_pmap.y=120;


	pmap->afficher_pperso=NULL;
	pmap->afficher_pperso=IMG_Load("pperso.png");

	pmap->pos_pperso.x=101;
	pmap->pos_pperso.y=120;
	pmap->nbmoved=0;


}

void afficher_pmap(pmap *pmap,SDL_Surface *ecran){


	SDL_BlitSurface(pmap->afficher_pmap,NULL,ecran,&pmap->pos_pmap);

	SDL_BlitSurface(pmap->afficher_pperso,NULL,ecran,&pmap->pos_pperso);

		if (pmap->nbmoved==5){
		pmap->pos_pperso.x+=10;
		pmap->nbmoved=0;
}
	if (pmap->nbmoved==-5){
		pmap->pos_pperso.x-=10;
		pmap->nbmoved=0;
	}

}

