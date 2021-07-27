#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void display(char game[3][3]); //Afiseaza tabla de joc
void empty_Game(char game[3][3]); //Reseteaza tabla de joc
bool is_Full(char game[3][3]); //Verifica daca tabla este plina
char is_Over(char game[3][3]); //Verifica daca a castigat cineva si returneaza simbolul castigatorului daca nu returneaza '-'

int main() {
    char pl1[] = {"Player_1"}, pl2[] = {"Player_2"};
    char game[3][3];
    int i,j;
    bool turn;
    start:
    //system("clean");
    turn = false;
    empty_Game(game);

    printf("\n\t\t\tTIC TAC TOE by Teja\n\n");
    while(!is_Full(game)) {
        printf("\n\tTastati pozitia: ");
        alta_pozitie:
        scanf("%d %d", &i, &j); i--; j--;
        if(game[i][j] != '-' || i>2 || j >2 || i<0 || j <0) {
            printf("\a\tPozitia exista deja sau ati depasit tabla de joc! Introduceti alta pozitie: ");
            goto alta_pozitie;
        }
        else {
            if(turn) {
                turn = false;
                game[i][j] = 'O';
            }
            else {
                turn = true;
                game[i][j] = 'X';
            }
        }
        display(game);
        switch(is_Over(game)) {
            case 'X' : {printf("\n\tCastigatorul este Player1\n"); goto rematch; break;}
            case 'O' : {printf("\n\tCastigatorul este Player2\n"); goto rematch; break;}
        }
    }
    if(is_Full) {
        printf("\n\tEste remiza\n");
    }
    rematch:
    printf("\t\tRematch? (y/n): ");
    getchar();
    scanf("%c", &game[0][0]);
    if(game[0][0] == 'y' || game[0][0] == 'Y') {
        goto start;
    }
    else {
        printf("\nSfarsit de joc!\a\n\n");
    }
    return 0;
}
//Afiseaza tabla de joc
void display(char game[3][3]) {
    int i,j;
    for(i=0; i<3; i++) {
        printf("\n\t\t\t");
        for(j=0; j<3; j++) {
            printf("\t%c", game[i][j]);
        }
    }
}

//Reseteaza tabla de joc
void empty_Game(char game[3][3]) {
    int i,j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            game[i][j] = '-';
        }
    }
}

//Verifica daca tabla este plina
bool is_Full(char game[3][3]) {
    int i,j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(game[i][j] == '-')
                return false;
        }
    }
    return true;
}

//Verifica daca a castigat cineva si returneaza simbolul castigatorului daca nu returneaza '-'
char is_Over(char game[3][3]) {
    int i;
    for(i=0; i<3; i++) {
        if(game[0][i] == game[1][i] && game[2][i] == game[1][i] && game[1][i] != '-')
            return game[1][i];
        if(game[i][0] == game[i][1] && game[i][2] == game[i][1] && game[i][1] != '-')
            return game[i][0];
    }
    
    if(game[0][0] == game[1][1] && game[2][2] == game[1][1] && game[1][i] != '-')
        return game[0][0];
    if(game[2][0] == game[1][1] && game[0][2] == game[1][1] && game[1][i] != '-')
        return game[2][0];
    return '-';
}