#ifndef USUARIOS_H
#define USUARIOS_H

struct usuario{
    int id;
    char username[16];
    char password[16];
    int clinicaAtendimento;
};

typedef struct usuario Usuario;

int gravarUsuario(Usuario usuario) {

    FILE *arquivo;
    arquivo = fopen("dados/usuarios.txt", "a+");

    int ultimoID = ultimoUsuario();

    if (arquivo == NULL) {
        return 0;
    }

    fprintf(arquivo, "%d %s %s %d\n", ultimoID, usuario.username, usuario.password, usuario.clinicaAtendimento);
    fclose(arquivo);

    return 1;
}

int ultimoUsuario(){

    FILE *arquivo;
    arquivo = fopen("dados/usuarios.txt", "r");

    int ultimoId = 0;

    Usuario usuario;
    usuario.id = 0;
    usuario.clinicaAtendimento = 0;

    if (arquivo == NULL) {
        printf("\n\nERRO AO ABRIR ARQUIVO DE USUARIOS !!\n\n");
        exit(1);
    }

    while (fscanf(arquivo, "%d %s %s %d\n", &usuario.id, usuario.username, usuario.password, &usuario.clinicaAtendimento) != EOF)
    {
        ultimoId = usuario.id;
    }  
    

    ultimoId++;
    return ultimoId;

}

#endif      