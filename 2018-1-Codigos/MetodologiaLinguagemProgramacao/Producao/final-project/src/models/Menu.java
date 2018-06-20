package models;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Menu {		
	Scanner input = new Scanner(System.in);
	
	public void exibirMenu(Vendedor vendedor[], Produto produto[]) {
		int opcao = 0;
		boolean continue_loop = true;
		
		System.out.println("===============================");
		System.out.println("Escolha uma das op��es abaixo  ");
		System.out.println("1 - Cadastrar funcionario     |");
		System.out.println("2 - Cadastrar produto         |");
		System.out.println("3 - Cadastrar gerente         |");
		System.out.println("4 - Cadastrar cliente         |");
		System.out.println("0 - Sair                      |");
		System.out.println("===============================");
		
		do {
			
			while(continue_loop) {
				try {
					System.out.print("Sua op��o: ");
					opcao = Integer.parseInt( input.nextLine() );
					
					continue_loop = false;
				
				} catch (NumberFormatException ex) {
					System.out.printf("    -> Digite apenas as op��es dispon�veis.\n");
					
				} catch (InputMismatchException ex) {
					System.out.printf("    -> Digite apenas as op��es dispon�veis.\n");
				}
			}
			
			switch (opcao) {
				case 1:
					vendedor[0].cadastrarDados();
					vendedor[1].cadastrarDados();
					break;
					
				case 2:
					produto[0].cadastrarDados();
					produto[1].cadastrarDados();
					break;
			             
				case 3:
					//gerente();
					break;
					
				case 4:
					//cliente();
					break;
					
				case 0:
					System.out.println("Programa encerrado pelo usu�rio. o/");
					break;
					
				default:
					System.out.println("Op��o Inv�lida!");
						break;
			}
			
			continue_loop = true;
			
		} while (opcao != 0);
	
	}

}