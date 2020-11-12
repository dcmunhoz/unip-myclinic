#ifndef USUARIOS_H
#define USUARIOS_H

struct usuario{
    int id;
    char username[16];
    char password[16];
};

typedef struct usuario Usuario;

#endif      