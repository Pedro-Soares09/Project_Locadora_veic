# Sistema de Aluguel de Veículos 🚗🚕

## 📝 Descrição do Projeto
Este é um projeto acadêmico desenvolvido para o 3º ciclo de **Lógica de Matemática e Algoritmo**. O programa consiste em um sistema de gerenciamento de terminal para uma locadora de veículos, permitindo o controle básico de uma frota, registro de clientes e a simulação de pedidos de aluguel com cálculo automático de custos.

## 🚀 Funcionalidades
O sistema roda diretamente no terminal e possui um menu interativo com as seguintes operações:
* **1. Cadastro de Veículos:** Permite adicionar novos carros informando o modelo, placa e valor da diária (com limite de armazenamento para 50 veículos).
* **2. Cadastro de Clientes:** Registra novos usuários utilizando Nome e CPF (com limite para 100 clientes).
* **3. Realizar Aluguel:** Vincula um veículo (por ID) a um cliente, altera o status do carro para "ALUGADO" e calcula o valor total estimado com base na quantidade de dias solicitados.
* **4. Ver Frota:** Exibe uma lista completa de todos os veículos cadastrados, detalhando suas informações e se estão "Disponíveis" ou "Alugados".

## 🛠️ Tecnologias e Estruturas Utilizadas
* **Linguagem:** C
* **Bibliotecas:** `<stdio.h>`, `<locale.h>`, `<stdlib.h>`, `<string.h>`
* **Estruturas de Dados:** Uso de `structs` (`veiculo` e `cliente`) para organização lógica das entidades.
* **Armazenamento:** Memória volátil em tempo de execução utilizando Arrays (Vetores).

## ⚙️ Como Compilar e Executar
Para testar o sistema, é necessário ter um compilador da linguagem C (como o GCC) instalado na sua máquina.

1. Salve o código-fonte em um arquivo, por exemplo, `aluguel.c`.
2. Abra o terminal e navegue até o diretório onde o arquivo está salvo.
3. Compile o programa com o comando:
   ```bash
   gcc aluguel.c -o aluguel
