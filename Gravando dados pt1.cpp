#include <iostream>
#include<string.h>
using namespace std;
#include<fstream>
#include <locale.h> //necessário para usar setlocale
//função do menu de opções
char menu()
{
  char resp;
    cout<<"\n\nDigite 1 para inserir dados\n";
    cout<<"\n\n Digite 2 para listar dados\n";
    cout<<"\n\n Digite 0 para sair\n\n";
    cin>> resp;
    return resp;

}


class Pessoa {

private:

string nome ;
string cpf;
string email;
int idade;

public:
string& getNome(){

  return nome;
  
}

string& getCpf(){
  return cpf;
}

string& getEmail(){

  return email;
  
}

int& getIdade(){

  return idade;
  
}
void setNome(string & nome)
{
this->nome = nome;
}

void setCpf(string & cpf)
{
this->cpf = cpf;
}void setEmail(string & email)
{
this->email = email;
}
void setIdade(int & idade)
{
this->idade= idade;
}
//sobrecarga do operador de inserção de dados 
//ostream (output stream
friend ostream& operator <<(ostream & os, const Pessoa & p){
  //escreve cada dado informado 
os << "\n" << p.nome <<"\n";
  os << "\n" << p.idade <<"\n";
  os << "\n" << p.cpf <<"\n";
  os << "\n" << p.email <<"\n";
  return os;

  
}
//sobrecarga do operador de extração de dados 
//ifstream (input stream) -> (lê e interpreta sequencia de caracters)
friend istream& operator >>(istream & is,  Pessoa & p){
  //ler os dados 
is >> p.nome>>p.idade>>p.cpf>>p.email;

  return is;
  
}

}; 
 


int main(int argc, char *argv[]) {
	

 setlocale(LC_ALL, "Portuguese");
char resp;

  while(true){
  resp = menu(); 
    system("clear||cls");
    if(resp=='1'){
      Pessoa pessoa;
      
    string nome;
      string cpf;
      string email;
      int idade;


      //ofstram ofs: abrir o arquivo txt
      //app (append) adciona ao final do arquivo
      ofstream ofs("arquivo.txt", std::fstream:: app);
      
      cout<<"\n\nInforme o nome: \n";
      cin>>nome;
      cout<<"\nInforme o idade:\n";
      cin>>idade;
      cout<<"\nInforme o CPF\n";
      cin>>cpf;
       cout<<"\nInforme o E-mail\n";
      cin>>email;
      cout<<endl;

      //seta os dados 
      pessoa.setNome(nome);
      
      pessoa.setIdade(idade);
      
      pessoa.setCpf(cpf);

      pessoa.setEmail(email);
      
      ofs<<pessoa;//  ofs: inserir ao arquivo
      ofs.close();
      //ofs.close (fechar o arquivo)
    }
      // comando para listar os dados 
       else if (resp=='2') {
          Pessoa p;
         ifstream ifs("arquivo.txt");

         cout<<"Listando dados"<<endl;
         
         if(ifs.good()) // verifica se o arquivo existe e se é possivel ler
         {
           while (!ifs.eof())// eof(end of file) equanto não chegar ao final do arquivo 
           {

                      ifs >> p; // extrai os dados 
            //exibindo os dados 
             cout<< "\nNome:\n"<<p.getNome();
             cout<<"\n\n";
            cout<< "\nIdade:\n"<<p.getIdade();
             cout<<"\n\n";
           cout<< "\nCPF:\n"<<p.getCpf();
             cout<<"\n\n";
          cout<< "\nE-mail:\n"<<p.getEmail();
           }
           ifs.close();
         }
       
         else{//exibição de mensagem caso não houver arquivo ou for impossivel lê-lo 

           cout<<"Falha ao exibir arquivo";
         }
    }

     else if(resp=='0'){

       cout<<"\n Conecte-se a: https://www.linkedin.com/in/ingrid-oliveira-a192b9181!\n";
       break;
     }

    else{
      cout<<"Opção invalida !";
    }
   
  }

  
}

