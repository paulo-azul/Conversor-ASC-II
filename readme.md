# Conversor ASCII com Bit de Paridade

Este trabalho foi feito por **Paulo Teles Serra Azul**, estudante de Engenharia de Computação da UFBA no semestre 2025.2, para a matéria de Sistemas Digitais.

## Objetivo do Projeto

O programa tem como objetivo receber um nome completo e um número de matrícula e, a partir disso:
1.  Converter cada caractere do nome para seu valor binário de 7 bits (padrão ASCII).
2.  Adicionar um 8º bit (o bit de paridade) de acordo com a matrícula do usuário (Paridade PAR se a matrícula for par, Paridade ÍMPAR se for ímpar).
3.  Exibir a nova cadeia de bits de 8 bits para cada caractere.
4.  Converter os novos valores binários de 8 bits de volta para caracteres, mostrando o nome modificado.

## Nota sobre a Implementação

O código foi implementado em C++ buscando construir manualmente as funções centrais da atividade (como `conversor_binario` e `conversor_decimal`). Embora existam bibliotecas nativas que poderiam simplificar o código (como `<bitset>`), a escolha foi focar na implementação da lógica de conversão e manipulação de bits.