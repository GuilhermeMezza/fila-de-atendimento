#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue <string> filaAtendimento;
    string nome;
    int escolha;

    cout << "Fila para atendimento" << endl;

    while(true){
        
        retorno_2:
        
        cout << "\n=> Menu\n" << endl;
        cout << "   1. Inserir novo cliente" << endl;
        cout << "   2. Chamar próximo cliente" << endl;
        cout << "   3. Visualizar pessoas da fila" << endl;
        cout << "   4. Encerrar programa" << endl;
        cout << "\nEscolha uma opção: ";
        cin >> escolha;

        switch(escolha){
            
            case 1:
            
                do{
                    cout << "\nInsira o nome do cliente: ";
                    cin >> nome;
                    filaAtendimento.push(nome);
                    cout << "\nDeseja inserir outro cliente (1) ou retornar ao menu principal (2)? ";
                    cin >> escolha;
                }while(escolha == 1);
                
                break;

            case 2:
            
                retorno:
            
                if(!filaAtendimento.empty()){
                    
                    cout << "\nChamando próximo cliente: " << filaAtendimento.front() << endl;
                    filaAtendimento.pop();
                    
                    cout << "\nPessoas da fila: " << endl;
                    int posicao = 1;
                    queue <string> copiaFilaAtendimento = filaAtendimento;
                    
                    while(!copiaFilaAtendimento.empty()){
                        cout << "Posicao " << posicao << ": " << copiaFilaAtendimento.front() << endl;
                        copiaFilaAtendimento.pop();
                        posicao++;
                    }
                    
                }else{
                    cout << "\nNão há clientes na fila." << endl;
                }

                cout << "\nDeseja chamar o próximo (1), voltar ao menu (2) ou finalizar (3)? ";
                cin >> escolha;
                
                if(escolha == 1){
                    goto retorno;
                }else if(escolha == 2){
                    goto retorno_2;
                }else if(escolha == 3){
                    cout << "\nPrograma finalizado." << endl;
                    return 0;
                }
                break;

            case 3:
                
                cout << "\n- Quantidade de pessoas em espera: " << filaAtendimento.size() << endl;
                
                if(!filaAtendimento.empty()){
                    
                    cout << "- Primeira pessoa da fila: " << filaAtendimento.front() << endl;
                    cout << "- Ultima pessoa da fila: " << filaAtendimento.back() << endl;
                    
                    cout << "\nPessoas da fila: " << endl;
                    int posicao = 1;
                    queue <string> copiaFilaAtendimento = filaAtendimento;
                    while (!copiaFilaAtendimento.empty()) {
                        cout << "Posicao " << posicao << ": " << copiaFilaAtendimento.front() << endl;
                        copiaFilaAtendimento.pop();
                        posicao++;
                    }
                }

                cout << "\nDeseja voltar ao menu (1) ou finalizar (2)? ";
                cin >> escolha;
                
                if(escolha == 2){
                    cout << "\nPrograma finalizado." << endl;
                    return 0;
                }
                
                break;

            case 4:
                
                cout << "\nPrograma finalizado." << endl;
                return 0;

            default:
            
                cout << "\nCódigo inválido! Tente novamente." << endl;
                break;
        }
    }

    return 0;
}
