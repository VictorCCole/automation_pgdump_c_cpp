#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Defina a senha do banco de dados
    const char *senha_banco = "password_user";

    // Obtenha a data e hora atual
    time_t t;
    struct tm *tm_info;
    time(&t);
    tm_info = localtime(&t);

    // Construa o nome do arquivo com base na data e hora
    char nome_arquivo[100];
    strftime(nome_arquivo, sizeof(nome_arquivo), "/location/where/it/will/be/saved/database_name_%Y%m%d%H%M%S.sql", tm_info);

    // Construa o comando com a senha como vari�vel de ambiente e o nome do arquivo
    const char *comando = "PGPASSWORD=\"%s\" sudo -E pg_dump -U user_bd_name database_name > %s";

    // Crie uma string para armazenar o comando final
    char comando_final[300];  // Ajuste o tamanho conforme necess�rio

    // Formate o comando final com a senha e o nome do arquivo
    snprintf(comando_final, sizeof(comando_final), comando, senha_banco, nome_arquivo);

    // Executa o comando
    int resultado = system(comando_final);

    // Verifica o resultado
    if (resultado == 0) {
        printf("Command executed successfully. File created: %s\n", nome_arquivo);
    } else {
        printf("Error executing the command.\n");
    }

    return 0;
}

