/*3ª ciclo de Lógica de Matemática e Algoritmo.
Alunos: Pedro Paulo, Hugo Cavalcanti, Marcos e Leonardo, Tena: ALUGUEL DE VEICULOS;
Precisa conter: CADASTRO DE VEICULOS,
CADASIRO DE CLIENTES;
PEDIDO DE ALUGUEL:
*/


#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>



struct veiculo {
    int id;
    int disponibilidade; 
    char modelo[50];
    char placa[9];
    double ValorDiaria;
};

struct cliente{
    int id;
    char nome[50];
    char cpf[12];
};

struct veiculo VeiculoCadastrados[50];
struct cliente ClienteCadastrados[100];
int totalVeiculos = 0;
int totalClientes = 0;

void exibirMenu();
void cadastrarVeiculo();
void cadastrarCliente();
void realizarAluguel();
void verFrota();

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    int escolha;
    
    do {
        exibirMenu();
        if (scanf("%d", &escolha) != 1) {
            escolha = 0;
            while (getchar() != '\n');
        }

        switch (escolha) {
            case 1:
                cadastrarVeiculo();
                break;
            case 2:
                cadastrarCliente();
                break;
            case 3:
                realizarAluguel();
                break;
            case 4:
                verFrota();
                break;
            case 0:
                printf("\nSaindo do sistema. Obrigado!\n");
                break;
            default:
                printf("\nEscolha invalida. Tente novamente.\n");
        }
    } while (escolha != 0);

    return 0;
} 

void exibirMenu() {
    printf("\n--- ALUGUEL DE VEICULOS ---\n");
    printf("1. Cadastrar Veiculo\n");
    printf("2. Cadastrar Cliente\n");
    printf("3. Realizar Aluguel\n");
    printf("4. Ver Frota\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

void cadastrarVeiculo() {
    if (totalVeiculos >= 50) {
        printf("\nLimite maximo de veiculos atingido.\n");
        return;
    }

    struct veiculo *novoVeiculo = &VeiculoCadastrados[totalVeiculos]; 
    
    while (getchar() != '\n'); 
    
    novoVeiculo->id = totalVeiculos + 1;

    printf("\n--- CADASTRO DE VEICULO ---\n");
    printf("ID: %d\n", novoVeiculo->id);
    
    printf("Modelo: ");
    scanf(" %[^\n]", novoVeiculo->modelo); 
    
    printf("Placa (Ex: AAA0000): ");
    scanf(" %s", novoVeiculo->placa);
    
    printf("Valor da diária: ");
    scanf("%lf", &novoVeiculo->ValorDiaria);
    
    novoVeiculo->disponibilidade = 1;

    totalVeiculos++;
    printf("\nVeiculo %s cadastrado com sucesso!\n", novoVeiculo->modelo);
}

void cadastrarCliente() {
    if (totalClientes >= 100) {
        printf("\nLimite maximo de clientes atingido.\n");
        return;
    }

    struct cliente *novoCliente = &ClienteCadastrados[totalClientes]; 
    
    while (getchar() != '\n'); 

    novoCliente->id = totalClientes + 1;

    printf("\n--- CADASTRO DE CLIENTE ---\n");
    printf("ID: %d\n", novoCliente->id);
    
    printf("Nome: ");
    scanf(" %[^\n]", novoCliente->nome); 
    
    printf("CPF (Somente números): ");
    scanf(" %s", novoCliente->cpf);

    totalClientes++;
    printf("\nCliente %s cadastrado com sucesso!\n", novoCliente->nome);
}

void verFrota() {
    int i; 

    printf("\n--- FROTA DE VEICULOS ---\n");
    if (totalVeiculos == 0) {
        printf("Nenhum veiculo cadastrado.\n");
        return;
    }
    
    for (i = 0; i < totalVeiculos; i++) {
        struct veiculo v = VeiculoCadastrados[i];
        
        char status[15];
        
        if (v.disponibilidade == 1) {
            strcpy(status, "Disponível");
        } else {
            strcpy(status, "ALUGADO");
        }
        
        printf("ID: %d | Modelo: %s | Placa: %s | Diária: R$ %.2f | Status: %s\n", 
               v.id, 
               v.modelo, 
               v.placa, 
               v.ValorDiaria, 
               status);
    }
}

void realizarAluguel() {
    
    int i;
    int Totaldias;
    int idCliente, idVeiculo;
    int veiculoEncontrado = 0;
    
    printf("\n--- REALIZAR ALUGUEL ---\n");
    
    if (totalClientes == 0 || totalVeiculos == 0) {
        printf("Necessario cadastrar pelo menos um cliente e um veiculo.\n");
        return;
    }

    printf("Digite o ID do Cliente: ");
    if (scanf("%d", &idCliente) != 1) {
         printf("Entrada invalida para ID do Cliente.\n");
         while (getchar() != '\n'); 
         return;
    }

    printf("Digite o ID do Veiculo para alugar: ");
    if (scanf("%d", &idVeiculo) != 1) {
         printf("Entrada invalida para ID do Veiculo.\n");
         while (getchar() != '\n'); 
         return;
    }

    for (i = 0; i < totalVeiculos; i++) {
        if (VeiculoCadastrados[i].id == idVeiculo) {
            veiculoEncontrado = 1;
            
            if (VeiculoCadastrados[i].disponibilidade == 1) {
                VeiculoCadastrados[i].disponibilidade = 0;
                
                printf("Digite os dias para alugar:");
                scanf("%d",&Totaldias);
                
                 printf("\nVeiculo %s (ID %d) alugado com sucesso para o Cliente ID %d.\n",
                       VeiculoCadastrados[i].modelo, idVeiculo, idCliente);
                       
                double custoTotal = VeiculoCadastrados[i].ValorDiaria * Totaldias;
                printf("Custo estimado para %d dia: R$ %.2f\n", Totaldias, custoTotal);
                
            } else {
                printf("\nO Veiculo %s (ID %d) ja esta alugado.\n", 
                       VeiculoCadastrados[i].modelo, idVeiculo);
            }
            break; 
        }
    }
    
    if (veiculoEncontrado == 0) {
        printf("\nVeiculo com ID %d nao encontrado.\n", idVeiculo);
    }

}
