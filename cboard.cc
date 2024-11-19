#include "cboard.h"
#include <iostream>
#include <string>

int global_pos_x, global_pos_y, global_l;
bool global_hv;


cboard::cboard()
{
        for (int i = 1; i < 11; i++) {

        for (int j = 1; j < 11; j++) {

            board[i][j] = '.'; // Ustawia wszystkie pola jako puste

        }

    }

}

void cboard::showboard()
{
    std::cout << std::endl;
    std::cout << "   A B C D E F G H I J "; // Wyświetla nagłówki kolumn
    std::cout << std::endl;
    for (int j = 1; j < 11; j++) {

        std::cout << j << " "; // Wyświetla numer wiersza
        if (j<10) {cout << ' ';}
        for (int i = 1; i < 11; i++) {
            std::cout << board[i][j] << " "; // Wyświetla zawartość pola
        }
        std::cout << std::endl; 
    }
}

bool cboard::check_char(char z)
{
// if ( (z!='A')&&(z!='a')&&(z!='B')&&(z!='b')&&(z!='C')&&(z!='c')&&(z!='D')&&(z!='d')&&(z!='E')&&(z!='e')&&(z!='F')&&(z!='f')&&(z!='G')&&(z!='g')&&(z!='H')&&(z!='h')&&(z!='I')&&(z!='i')&&(z!='J')&&(z!='j') )
    if ( ( (int(z)<65) || (int(z)>74) ) && ( (int(z)<97) || (int(z)>106) ) )
    {
        // std::cout << z << "  <->  " << int(z);
        return false;
    }
    return true;
}

bool cboard::check_ship_collision(int x, int y, bool hv, int l)
{
    bool result1 = false;
    int ix, iy;

        if (hv==true) {   // statek poziomy
        for (ix = x-1 ; ix <= x+l ; ix++){
            if ( board[ix][y-1] == 'X' ) { result1 = true;}
            if ( board[ix][y] == 'X' ) { result1 = true;}
            if ( board[ix][y+1] == 'X' ) { result1 = true;}
        }
    }

    if (hv==false) {   // statek pionowy
        for (iy = y-1 ; iy <= y+l ; iy++){
            if ( board[x-1][iy] == 'X' ) { result1 = true;}
            if ( board[x][iy] == 'X' ) { result1 = true;}
            if ( board[x+1][iy] == 'X' ) { result1 = true;}
        }
    }
    return result1;
}

cboard::~cboard()
{
    std::cout << "cboard destructor" <<endl;
}

int cboard::change_char_to_int(char ch1)
{
    int nu1;
    if ( (ch1 == 'A')||(ch1 == 'a') ) {nu1 = 1;}
    if ( (ch1 == 'B')||(ch1 == 'b') ) {nu1 = 2;}
    if ( (ch1 == 'C')||(ch1 == 'c') ) {nu1 = 3;}
    if ( (ch1 == 'D')||(ch1 == 'd') ) {nu1 = 4;}
    if ( (ch1 == 'E')||(ch1 == 'e') ) {nu1 = 5;}
    if ( (ch1 == 'F')||(ch1 == 'f') ) {nu1 = 6;}
    if ( (ch1 == 'G')||(ch1 == 'g') ) {nu1 = 7;}
    if ( (ch1 == 'H')||(ch1 == 'h') ) {nu1 = 8;}
    if ( (ch1 == 'I')||(ch1 == 'i') ) {nu1 = 9;}
    if ( (ch1 == 'J')||(ch1 == 'j') ) {nu1 = 10;}
    return nu1; 
}

// NIE UZYTA funkcja...
char cboard::change_int_to_char(int nu1)
{
    char ch1;
    if  (nu1 == 1) { (ch1 = 'A'); }
    if  (nu1 == 2) { (ch1 = 'B'); }
    if  (nu1 == 3) { (ch1 = 'C'); }
    if  (nu1 == 4) { (ch1 = 'D'); }
    if  (nu1 == 5) { (ch1 = 'E'); }
    if  (nu1 == 6) { (ch1 = 'F'); }
    if  (nu1 == 7) { (ch1 = 'G'); }
    if  (nu1 == 8) { (ch1 = 'H'); }
    if  (nu1 == 9) { (ch1 = 'I'); }
    if  (nu1 == 10) { (ch1 = 'J'); }
    return ch1;
}


void cboard::create_ship(int cl)
{
    int pos_x, pos_y, length_ship;
    int x, y;
    int lx, ly;
    bool hv;
    char zn;
    bool char_ok;
	bool ship_ok = false;
	bool ship_collision = false;   // true
	string thv;
	
    while ( (ship_ok == false) || (ship_collision == true) ) 
	{

        char_ok = false;
        std::cout << "Podaj wspolrzedne zaczepienia dla " << cl << "-masztowca: X = [A,B,C,D,E,F,G,H,I,J] (?) : ";
        while ( char_ok == false )
        {
            std::cin >> zn;
            if ( check_char(zn)==true ) { char_ok = true; }
            if ( check_char(zn)==false )
            {
                std::cout << "Wprowadziles nieprawidlowy znak. Powtorz : ";
            }
        }
        pos_x = change_char_to_int(zn);
        std::cout << "Podaj wspolrzedna pionowa: y = [1..10] (?) : ";

        y = 0;
        while ( (y<1)||(y>10) )
        {   
            std::cin >> y; 
            if ((y<1)||(y>10)){std::cout << "wpisz poprawna wartosc od 1 do 10: ";}
        }
        pos_y = y;

        std::cout << " Pionowo czy poziomo ? Wpisz: [pion / poz] : ";
        thv = "";
        while ( (thv!="pion")&&(thv!="poz") ){
            std::cin >> thv;
            if ((thv!="pion")&&(thv!="poz")) {std::cout << "wpisz poprawna wartosc [pion / poz]: "; }
        }    
        if ( thv == "pion" ) {hv=false;}
        if ( thv == "poz") {hv=true;}

        length_ship = cl;
        
        ship_ok = true;

        if ((hv==true)&&(pos_x>10-cl+1)) {
            ship_ok=false;
            std::cout << "Podany statek wychodzi poza plansze. Wpisz ponownie." <<std::endl;
            getchar();  
        }
        if ((hv==false)&&(pos_y>10-cl+1)) {
            ship_ok=false;
            std::cout << "Podany statek wychodzi poza plansze. Wpisz ponownie." <<std::endl;
            getchar();  
        }

        ship_collision = check_ship_collision(pos_x, pos_y, hv, length_ship);
        //  std::cout << " (!!!) SHIP COLLISION = " << ship_collision <<std::endl;
        if ( ship_collision == true ) {
        	std::cout << "Podany statek koliduje z istniejacym na planszy. Wpisz ponownie." <<std::endl;
		}

        if ( (ship_ok == true)&&(ship_collision == false) )
        {
            if (hv==true) {
				for ( lx=pos_x; lx<=pos_x+cl-1; lx++ ) {
                	board[lx][pos_y]='X';
                }
        	}
			if (hv==false) {
            	for ( ly=pos_y; ly<=pos_y+cl-1; ly++ ) {
            		board[pos_x][ly]='X';
				}
        	}
        }

    }
	
    showboard();
    
    global_pos_x = pos_x;
	global_pos_y = pos_y;
	if (hv==true) {global_hv=true;};
	if (hv==false) {global_hv=false;};
	global_l = length_ship;
   
}

void cboard::addship()
{

    std::cout << "Masz do ulozenia: 4 x 1-masztowiec, 3 x 2-masztowiec, 2 x 3-masztowiec, 1 x 4-masztowiec"<< endl << endl;

	create_ship(4);
	cship m4(global_pos_x,global_pos_y,global_hv,global_l);
	create_ship(3);
	cship m31(global_pos_x,global_pos_y,global_hv,global_l);
	create_ship(3);
	cship m32(global_pos_x,global_pos_y,global_hv,global_l);
	create_ship(2);
	cship m21(global_pos_x,global_pos_y,global_hv,global_l);
	create_ship(2);
	cship m22(global_pos_x,global_pos_y,global_hv,global_l);
	create_ship(2);
	cship m23(global_pos_x,global_pos_y,global_hv,global_l);
	create_ship(1);
	cship m11(global_pos_x,global_pos_y,global_hv,global_l);
	create_ship(1);
	cship m12(global_pos_x,global_pos_y,global_hv,global_l);
	create_ship(1);
	cship m13(global_pos_x,global_pos_y,global_hv,global_l);
	create_ship(1);
	cship m14(global_pos_x,global_pos_y,global_hv,global_l);
	
}


