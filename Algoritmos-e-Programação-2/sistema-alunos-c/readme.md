# 📚 Sistema de Gerenciamento de Alunos em C

Um sistema desenvolvido em **Linguagem C** para o gerenciamento acadêmico de alunos, focado em praticar conceitos fundamentais como estruturas (`struct`), ponteiros, alocação estática e validação robusta de entradas de dados via terminal.

## 🚀 Funcionalidades

O sistema oferece um menu interativo com as seguintes opções:

1. **Cadastrar Aluno:** Permite registrar o nome e duas notas de um número definido inicialmente de alunos.
2. **Calcular Média:** Busca um aluno pelo nome e calcula automaticamente a média aritmética das suas notas.
3. **Alterar Notas:** Permite atualizar as notas de um aluno já cadastrado buscando-o pelo nome.
4. **Mostrar Alunos:** Exibe a lista completa de todos os alunos cadastrados, suas respectivas notas e médias.
5. **Sair:** Encerra a execução do programa.

## 🛠️ Tecnologias Utilizadas

* **Linguagem C** (Padrão C99 ou superior)
* Compilador compatível com GCC / Clang

## 📥 Como Compilar e Executar

Certifique-se de ter um compilador de C instalado em sua máquina (como o `gcc`).

1. Abra o terminal na pasta do projeto (`sistema-alunos-c`).
2. Compile o código com o `gcc`:
   ```bash
   gcc sistema-alunos.c -o sistema_alunos
