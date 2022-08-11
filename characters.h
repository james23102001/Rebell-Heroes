
/***Characters.hpp
Fonctions des personnages de REBELS HEROES
Par James LILIOU, Pour GAME CENTER***/

#ifndef DEF_CHARACTERS
#define DEF_CHARACTERS


//Characters class declaration
    void initChars();

    typedef struct{
    int health;
    int attack;
    int defense;
    int sp_attack;
    int sp_defense;
    int speed;
    int classe;
    }character;

//Characters creation
    character James;
    character Riley;
    character Desdemona;
    character Eok;
    character Tenebra;
    character Estra;
    character Kicop_Uw;
    character Hades;
    character Loupito;

    character all[9];

#endif // DEF_CHARACTERS
