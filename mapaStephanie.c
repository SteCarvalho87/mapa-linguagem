#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Definição dos tipos de atendimento
enum Atendimento {
    ABERTURA_CONTA = 1,
    CAIXA,
    GERENTE_PF,
    GERENTE_PJ
};

// Definição da estrutura do cadastro de clientes
struct Cliente {
    char nome[50];
    char cpf[15];
    enum Atendimento tipoAtendimento;
};

// Variável global para armazenar os cadastros
struct Cliente cadastros[50];
int totalCadastros = 0;

// Protótipos das funções
void solicitarAtendimento();
void listarAtendimentos();
void listarPorSetor();

int main() {
    setlocale (LC_ALL, "portuguese");
    int opcao;

    printf("Bem-vindo(a) ao sistema de atendimento!\n");

    do {
        printf("\n Digite uma das opções:\n");
        printf("1 - Solicitar Atendimento\n");
        printf("2 - Listar Atendimentos Registrados\n");
        printf("3 - Listar Atendimento por Setor\n");
        printf("4 - Sair\n");

        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1:
                solicitarAtendimento();
                break;
            case 2:
                listarAtendimentos();
                break;
            case 3:
                listarPorSetor();
                break;
            case 4:
                printf("Agradecemos a sua visita!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);
    return 0;
}

void solicitarAtendimento() {
    if (totalCadastros < 50) {
        struct Cliente novoCliente;

        printf("Digite o seu nome completo: ");
        scanf(" %[^\n]s", novoCliente.nome);
        fflush(stdin);

        printf("Digite o seu CPF (formato 123.123.123-12): ");
        scanf("%s", novoCliente.cpf);
        fflush(stdin);

        printf("\nEscolha o tipo de atendimento:\n");
        printf("1 - Abertura de Conta\n");
        printf("2 - Caixa\n");
        printf("3 - Gerente Pessoa Física\n");
        printf("4 - Gerente Pessoa Jurídica\n");

        scanf("%d", (int*)&novoCliente.tipoAtendimento);
        fflush(stdin);

        cadastros[totalCadastros] = novoCliente;
        totalCadastros++;
        system("cls");

        printf("Cadastro realizado com sucesso! Aguarde um instante e um de nossos atendentes irá chamá-lo(a)! \n");
    } else {
        system("cls");
        printf("Limite de cadastros atingido.\n");
    }
}

void listarAtendimentos() {
    int i;
    if (totalCadastros == 0) {
        system("cls");
        printf("Nenhum atendimento registrado.\n");
        return;
    }
    else {
         for (i = 0; i < totalCadastros; i++) {
             printf("Nome: %s\n", cadastros[i].nome);
             printf("CPF: %s\n", cadastros[i].cpf);
             printf("Tipo Atendimento - %d - ", cadastros[i].tipoAtendimento);
             switch (cadastros[i].tipoAtendimento) {
             case ABERTURA_CONTA:
                 printf("Abertura de Conta\n");
                 break;
             case CAIXA:
                 printf("Caixa\n");
                 break;
             case GERENTE_PF:
                 printf("Gerente Pessoa Física\n");
                 break;
             case GERENTE_PJ:
                 printf("Gerente Pessoa Jurídica\n");
                 break;
             default:
                 printf("Desconhecido\n");
             }
         printf("===============================\n");
         }
    }
}

void listarPorSetor() {
    int i;
    int setor;

    if (totalCadastros == 0) {
        printf("Nenhum atendimento registrado.\n");
        system("cls");
        return;
    }
    else {
        printf("\nDigite o tipo de atendimento que deseja listar (1 a 4): \n");
        printf("1 - Abertura de Conta\n");
        printf("2 - Caixa\n");
        printf("3 - Gerente Pessoa Física\n");
        printf("4 - Gerente Pessoa Jurídica\n");
        scanf("%d", &setor);
        fflush(stdin);

        if (setor < 1 || setor > 4) {
            printf("Opção inválida.\n");
            return;
        }
        else {
            printf("Listagem de atendimentos do tipo %d:\n", setor);
            for (i = 0; i < totalCadastros; i++) {
                if ((int)cadastros[i].tipoAtendimento == setor) {
                   printf("Nome: %s\n", cadastros[i].nome);
                   printf("CPF: %s\n", cadastros[i].cpf);
                   printf("Tipo Atendimento - %d - ", cadastros[i].tipoAtendimento);

                   switch (cadastros[i].tipoAtendimento) {
                   case ABERTURA_CONTA:
                        printf("Abertura de Conta\n");
                        break;
                   case CAIXA:
                        printf("Caixa\n");
                        break;
                   case GERENTE_PF:
                        printf("Gerente Pessoa Física\n");
                        break;
                   case GERENTE_PJ:
                        printf("Gerente Pessoa Jurídica\n");
                        break;
                   default:
                        printf("Desconhecido\n");
                   }
                printf("===============================\n");
                }
            }
        }
    }
}
