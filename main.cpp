#include <iostream>
#include "cboard.cc"
#include "cgamer.cc"
#include "cship.cc"

// #include <windows.h>  - wpisac do kompilacji w DEV_C++
// #include <cstdlib>   - wpisac do kompilacji w DEV_C++

using namespace std;

bool check_char(char z)
{
   
  // if ( (z!='A')&&(z!='a')&&(z!='B')&&(z!='b')&&(z!='C')&&(z!='c')&&(z!='D')&&(z!='d')&&(z!='E')&&(z!='e')&&(z!='F')&&(z!='f')&&(z!='G')&&(z!='g')&&(z!='H')&&(z!='h')&&(z!='I')&&(z!='i')&&(z!='J')&&(z!='j') )
    if ( ( (int(z)<65) || (int(z)>74) ) && ( (int(z)<97) || (int(z)>106) ) )
    {
        return false;
    }
    return true;
}

int change_char_to_int(char ch1)
{
    int num;
    if ( (ch1 == 'A')||(ch1 == 'a') ) {num = 1;}
    if ( (ch1 == 'B')||(ch1 == 'b') ) {num = 2;}
    if ( (ch1 == 'C')||(ch1 == 'c') ) {num = 3;}
    if ( (ch1 == 'D')||(ch1 == 'd') ) {num = 4;}
    if ( (ch1 == 'E')||(ch1 == 'e') ) {num = 5;}
    if ( (ch1 == 'F')||(ch1 == 'f') ) {num = 6;}
    if ( (ch1 == 'G')||(ch1 == 'g') ) {num = 7;}
    if ( (ch1 == 'H')||(ch1 == 'h') ) {num = 8;}
    if ( (ch1 == 'I')||(ch1 == 'i') ) {num = 9;}
    if ( (ch1 == 'J')||(ch1 == 'j') ) {num = 10;}
    return num; 
}

int main()
{
    int shot_x, shot_y;
    char z;
    string gmr1 , gmr2;
    bool gmr1_win , gmr2_win;
    int a, i, j, n1, n2;

    cout << endl;
    cout << "   **********************" << endl; 
    cout << "   ***  GRA W STATKI  ***" << endl;
    cout << "   **********************" << endl;
    cout << "           Autor: Szymon Wierzbicki, klasa II F, 2024 " << endl << endl;
    cout << "Podaj nazwe gracza 1: " ;
    cin >> gmr1;
    cout << endl;
    cout << "Podaj nazwe gracza 2: ";
    cin >> gmr2;

    cgamer gamer1(gmr1);
    cgamer gamer2(gmr2);

    cout << endl;
    cout << "Gracz 1 " << gamer1.name << " rozloz statki" <<endl;
    cout << endl;
    gamer1.my_board.addship();
    // gamer1.my_board.showboard();

    cout << " Nacisnij_enter ... " << endl;  
    getchar();
    getchar();
    system("CLS");

    cout << "Gracz 2 " << gamer2.name << " rozloz statki" <<endl;
    cout << endl;
    gamer2.my_board.addship();
    // gamer2.my_board.showboard();

    cout << " Nacisnij_enter ... " << endl;  
    getchar();
    getchar();
    system("CLS");

    bool game_over1 = false;
    bool game_over2 = false;

    cout << "Rozpoczynamy gre ! " <<endl;
    cout << endl;
    
    bool repeating = true;

    while ( (game_over1 == false)&&(game_over2 == false) ) 
    {
        repeating = true;
        cout << " Gracz - "<< gmr1 << " - do pulpitu i nacisnij enter" <<endl; 
        getchar();
        cout << "Twoja tablica: " <<endl;
        gamer1.my_board.showboard();
        cout << endl;
        cout << endl;
        cout << "Tablica przeciwnika: " <<endl;
        gamer1.alien_board.showboard();

        // shot gamer's 1:
        while (repeating == true)
        {  
    
            repeating = false;
            shot_x = 0; shot_y = 0; z = '0';
            std::cout << "Podaj wspolrzedne strzalu:" << endl;
            std::cout << "  Poziomo [A,B,C,D,E,F,G,H,I,J] :  ";
            while ( check_char(z) == false )
            { 
                std::cout << "  Wprowadz prawidlowa litere: ";
                std::cin >> z;
            }
            shot_x = change_char_to_int(z);
            std::cout << endl;
            std::cout << "  Pionowo [1..10] :  ";
            while ( (shot_y<1)||(shot_y>10) )
            {
                std::cout << "Wprowadz poprawna wartosc: ";
                std::cin >> shot_y;
            }
            if ( (gamer1.alien_board.board[shot_x][shot_y]=='T') )
            {
                repeating = true;
                cout << "Juz strzelales w to pole ! " << endl;
                cout << " Powtorz strzal: " << endl;
                //cout << " nacisnij ENTER ... ";
                //getchar();
            }
            else if ( (gamer1.alien_board.board[shot_x][shot_y]=='-') )
            {
                repeating = true;
                cout << "Juz strzelales w to pole ! " << endl;
                cout << " Powtorz strzal: " << endl;
                //cout << " nacisnij ENTER ... ";
                //getchar();
            }
            else if (gamer2.my_board.board[shot_x][shot_y]=='X')
            {
                gamer2.my_board.board[shot_x][shot_y] = 'T';
                gamer1.alien_board.board[shot_x][shot_y] = 'T';
                cout << "TRAFIONY !" << endl;
                cout << "Strzelaj dalej !" <<endl;
                repeating = true;
            }
            else if (gamer2.my_board.board[shot_x][shot_y]=='.') 
            {
                cout << "PUDLO !" << endl;
                gamer1.alien_board.board[shot_x][shot_y] = '-';
                repeating = false;
            }
            
            
        }

        cout << " nacisnij ENTER ... ";
        getchar();
        getchar();
        system("CLS");

        cout << " Gracz - "<< gmr2 << " - do pulpitu i nacisnij enter" <<endl; 
        getchar();
        cout << "Twoja tablica: " <<endl;
        gamer2.my_board.showboard();
        cout << endl;
        cout << endl;
        cout << "Tablica przeciwnika: " <<endl;
        gamer2.alien_board.showboard();

        // shot gamer's 2:
        repeating = true;
        while (repeating == true)
        {  
            repeating = false;
            shot_x = 0; shot_y =0; z = '0';
            std::cout << "Podaj wspolrzedne strzalu:" << endl;
            std::cout << "  Poziomo [A,B,C,D,E,F,G,H,I,J] :  ";
            while ( check_char(z) == false )
            { 
                std::cout << "  Wprowadz prawidlowa litere: ";
                std::cin >> z;
            }
            shot_x = change_char_to_int(z);
            std::cout << endl;
            std::cout << "  Pionowo [1..10] :  ";
            while ( (shot_y<1)||(shot_y>10) )
            {
                std::cout << "Wprowadz poprawna wartosc: ";
                std::cin >> shot_y;
            };
            if ( (gamer2.alien_board.board[shot_x][shot_y]=='T') )
            {
                repeating = true;
                cout << "Juz strzelales w to pole ! " << endl;
                cout << " Powtorz strzal: " << endl;
                //cout << " nacisnij ENTER ... ";
                //getchar();
            }
            else if ( (gamer2.alien_board.board[shot_x][shot_y]=='-') )
            {
                repeating = true;
                cout << "Juz strzelales w to pole ! " << endl;
                cout << " Powtorz strzal: " << endl;
                //cout << " nacisnij ENTER ... ";
                //getchar();
            }
            else if (gamer1.my_board.board[shot_x][shot_y]=='X')
            {
                gamer1.my_board.board[shot_x][shot_y] = 'T';
                gamer2.alien_board.board[shot_x][shot_y] = 'T';
                cout << "TRAFIONY !" << endl;
                cout << "Strzelaj dalej !" <<endl;
                repeating = true;
            }
            else if (gamer1.my_board.board[shot_x][shot_y]=='.') 
            {
                cout << "PUDLO !" << endl;
                gamer2.alien_board.board[shot_x][shot_y] = '-';
                repeating = false;
            }
            
        }

        cout << " nacisnij ENTER ... ";
        getchar();
        getchar();
        system("CLS");
        game_over1 = false;
        game_over2 = false;
        n1 = 0;
        n2 = 0;
        for ( i = 1; i < 11; i++) 
        {
            for (j = 1; j < 11; j++) 
            {
                if (gamer1.my_board.board[i][j] == 'X') 
                {
                    n1++;                     
                }
                if (gamer2.my_board.board[i][j] == 'X')
                {
                    n2++;                    
                }
            }
        }    
                if ( n1 == 0 )
                {
                    game_over1 = true;
                    gmr2_win = true;
                }
                if ( n2 == 0)
                {
                    game_over2 = true;
                    gmr1_win = true;
                }
                              
    }

    string winner;
    if (gmr1_win == true) {winner = gmr1;}
    if (gmr2_win == true) {winner = gmr2;}
    if ( (gmr1_win == true)&&(gmr2_win ==  true) ) {winner = " REMIS ! "; }
    
    cout << "Koniec rozgrywki. Wygral gracz : " << winner << endl << endl;

    cout << " Aby zakonczyc, wcisnij ENTER ... ";
    getchar();

    return 0;
}
