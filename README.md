# Sistema de Gerenciamento de Tarefas

## Ideia

Um sistema de gerenciamento de tarefas é uma ferramenta ou aplicativo de software projetado para ajudar indivíduos, equipes ou organizações a organizar, acompanhar e gerenciar as tarefas que precisam ser realizadas. O objetivo principal é melhorar a eficiência, a produtividade e o acompanhamento de projetos e atividades.

As equipes de desenvolvimento de software utilizam esse sistema para rastrear e priorizar as tarefas de desenvolvimento, correção de bugs, testes e implantação de software, sendo assim uma ferramenta essencial para melhorar a eficiência, a colaboração e o acompanhamento de projetos. Ajudando também as equipes a se manterem organizadas, a cumprir prazos e a entregar software de alta qualidade de forma mais consistente.

## Projeto

### Parte Básica

O projeto consiste em um Sistema de Gerenciamento de Tarefas considerando as seguintes características:

1. **Informações das Tarefas** (Estrutura Tarefa):
   - Código da Tarefa – número inteiro
   - Nome da Tarefa – caractere de tamanho máximo 30
   - Projeto – nome do projeto a que pertence a tarefa - caractere de tamanho máximo 30
   - Data de Início – estrutura contendo dia, mês e ano como valores inteiros
   - Data de Término – estrutura contendo dia, mês e ano como valores inteiros
   - Status – define se a tarefa está atrasada ou em dia, pode ser considerado um valor inteiro sendo 1 atrasada e 0 em dia e -1 pendente

2. **Funcionalidades do Sistema**
   1. Adicionar uma nova Tarefa
   2. Modificar uma Tarefa (dados inseridos)
   3. Concluir Tarefa (atualiza data de Término)
   4. Atualização do Status da Tarefa (automática comparando datas)
   5. Lista de Tarefas Pendentes
   6. Lista de Tarefas Concluídas
   7. Lista de Tarefas Concluídas com e sem Atrasos
   8. Sair do Programa

### Parte Avançada

Nesta parte, a estrutura de tarefa ganha um novo campo:

- Prioridade da Tarefa – um valor inteiro de 1, 2, 3, sendo 1 Alta Prioridade, 2 Prioridade Normal e 3 Baixa Prioridade.

Com essa nova estrutura, as funcionalidades do sistema devem ser modificadas para considerar três filas de tarefas, uma para cada prioridade. A Lista de Pendências será uma única lista ordenada pela prioridade e dentro de cada prioridade ordenada pela data de término.

## Utilização

Para utilizar o sistema, basta seguir as instruções apresentadas durante a execução do programa. O sistema foi construído utilizando os conceitos de Filas e Listas, bem como os conceitos de bibliotecas e funções.

## Contribuições

Contribuições são bem-vindas! Se você encontrar um problema ou tiver uma sugestão, por favor, abra uma nova issue ou envie um pull request.
