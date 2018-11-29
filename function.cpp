#include <SDL2/SDL.h>
#include <iostream>
#include <string>
using namespace std;

double x = 0;  //Position X
double y = 0;  //Position Y
double r = 0;  //Rouge
double v = 0;  //Vert
double b = 0;  //Bleu
double inclinaison = 0;  //Inclinaison sur 360
SDL_Renderer* renderer = NULL;



void couleur(int R,int V,int B){      //Couleur selon Rouge, Vert, Bleu
  r = R%256;  //Depassement
  v = V%256;
  b = B%256;
  SDL_SetRenderDrawColor(renderer, r, v, b, SDL_ALPHA_OPAQUE);  //Application parametres
}

void incliner(int a){
  inclinaison += a%360;
}

void position(int X, int Y){    //Postion x et y
  x = X;
  y = Y;
}



/*                  ####################################
                    #             DOITES               #
                    ####################################
*/
void droite(int a){
  SDL_RenderDrawLine(renderer, x, y, x+a, y);                          //Draw line from:to
  x += a;
}
void gauche(int a){
  SDL_RenderDrawLine(renderer, x, y, x-a, y);                          //Draw line from:to
  x -= a;
}
void haut(int a){
  SDL_RenderDrawLine(renderer, x, y, x, y-a);                          //Draw line from:to
  y -= a;
}
void bas(int a){
  SDL_RenderDrawLine(renderer, x, y, x, y+a);                          //Draw line from:to
  y += a;
}
void ligne_par_coordonnes(int a,int b){
  SDL_RenderDrawLine(renderer, x, y, x+a, y-b);                          //Draw line from:to
  x += a;
  y -= b;
}















int main(int argc, char* argv[]){
  SDL_Window *Window;
  SDL_CreateWindowAndRenderer(800,800, 0, &Window, &renderer);

  couleur(0,0,0);
  SDL_RenderClear(renderer);
  couleur(255,255,255);
  position(400,400);
  cout << x <<":"<< y << endl;
  ligne_par_coordonnes(0,-100);
  cout << x <<":"<< y << endl;

  SDL_RenderPresent(renderer);                                               //Apply Set_Color on line
  string huitre;
  cin >> huitre;
    return 0;
}
