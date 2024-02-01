#include <cstdlib>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

int main() {
    // Obtenha a data e hora atual
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Formate a data e hora para incluir no nome do arquivo
    std::stringstream ss;
    ss << "/location/where/it/will/be/saved/database_name_"
       << std::put_time(std::localtime(&currentTime), "%Y%m%d_%H%M%S") << ".sql";

    // Obtenha o nome do arquivo formatado
    std::string nomeArquivo = ss.str();

    // Defina a variável de ambiente PGPASSWORD antes de chamar o pg_dump
    std::string senha = "password_user";
    setenv("PGPASSWORD", senha.c_str(), 1);

    // Construa o comando com o nome do arquivo
    std::string comando = "sudo -E pg_dump -U user_bd_name database_name > " + nomeArquivo;

    // Execute o comando
    system(comando.c_str());

    // Limpeza: remova a variável de ambiente após o uso (opcional)
    unsetenv("PGPASSWORD");

    return 0;
}
