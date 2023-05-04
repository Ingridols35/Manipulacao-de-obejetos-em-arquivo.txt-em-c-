#include <iostream>
#include <string>
#include <fstream>
#include <locale.h> 

using namespace std;
//função do menu de opções 
char menu()
{
    char resp;
    std::cout << "\n\nDigite 1 para inserir dados\n";
    std::cout << "\n\nDigite 2 para listar dados\n";
    std::cout << "\n\nDigite 0 para sair\n\n";
  
    std::cin >> resp;
    return resp;
}

class Pessoa {
private:
    std::string nome;
    std::string cpf;
    std::string email;
    int idade;

public:
    std::string& getNome() { return nome; }
    std::string& getCpf() { return cpf; }
    std::string& getEmail() { return email; }
    int& getIdade() { return idade; }

    void setNome(std::string& nome) { this->nome = nome; }
    void setCpf(std::string& cpf) { this->cpf = cpf; }
    void setEmail(std::string& email) { this->email = email; }
    void setIdade(int idade) { this->idade = idade; }


//sobrecarga do operador de inserção de dados 
//ostream (output stream)
    friend std::ostream& operator<<(std::ostream& os, const Pessoa& p)
    //escreve cada dado informado
{
        os << "\n" << p.nome << "\n";
        os << "\n" << p.idade << "\n";
        os << "\n" << p.cpf << "\n";
        os << "\n" << p.email << "\n";
        return os;
    }


//sobrecarga do operador de extração de dados 
//ifstream (input stream) -> (lê interpreta sequencia de caracters)
    friend std::istream& operator>>(std::istream& is, Pessoa& p)
   //ler os dados 
{
        std::getline(is >> std::ws, p.nome);
        is >> p.idade;
        std::getline(is >> std::ws, p.cpf);
        std::getline(is >> std::ws, p.email);
        return is;
    }
};

int main(int argc, char* argv[])
{

 setlocale(LC_ALL, "Portuguese");
 
    char resp;
    while (true) {
        resp = menu();
        system("clear||cls");
        if (resp == '1') {
            Pessoa pessoa;

            std::string nome;
            std::string cpf;
            std::string email;
            int idade;
            

          //ofstram ofs: abrir o arquivo txt
            //app (append) adciona ao final do arquivo
            std::ofstream ofs("arquivo.txt", std::fstream::app);

          
            std::cout << "\n\nInforme o nome: \n";
            std::getline(std::cin >> std::ws, nome);
          
            std::cout << "\nInforme o idade:\n";
            std::cin >> idade;
          
            std::cout << "\nInforme o CPF\n";
            std::getline(std::cin >> std::ws, cpf);

          
            std::cout << "\nInforme o E-mail\n";
            std::getline(std::cin >> std::ws, email);
          
            std::cout << std::endl;

           //seta os dados 
            pessoa.setNome(nome);
            pessoa.setIdade(idade);
            pessoa.setCpf(cpf);
            pessoa.setEmail(email);

            ofs << pessoa; //ofs: inserir ao arquivo

           //ofs.close (fechar o arquivo)
            ofs.close();
        }

           // comando para listar os dados 
        else if (resp == '2') {
            Pessoa p;
            std::ifstream ifs("arquivo.txt");

            std::cout << "Listando dados" << std::endl;

            if (ifs.good()) // verifica se o arquivo existe e se é possivel ler
            {
               while (!ifs.eof()){
                 
               
                ifs >> p; // extrai os dados
                  
            //exibindo os dados 
                  {
                    std::cout << "\nNome:\n" << p.getNome() << "\n\n";
                    std::cout << "\nIdade:\n" << p.getIdade() << "\n\n";
                    std::cout << "\nCPF:\n" << p.getCpf() << "\n\n";
                    std::cout << "\nE-mail:\n"<<p.getEmail()<<"\n\n";
}
           ifs.close();
         }
            }
       
         else{//exibição de mensagem caso não houver arquivo ou for impossivel lê-lo 

           std::cout<<"Falha ao exibir arquivo";
         }
    }

     else if(resp=='0'){

       std:: cout<<"\n Conecte-se a: https://www.linkedin.com/in/ingrid-oliveira-a192b9181!\n";
       break;
     }

    else{
      std::cout<<"Opção invalida !";
    }
   
  }

  
}
