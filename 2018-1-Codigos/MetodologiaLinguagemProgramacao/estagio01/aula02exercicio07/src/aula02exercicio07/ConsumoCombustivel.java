//aula 02 - slide 48

package aula02exercicio07;

import java.util.Scanner;

public class ConsumoCombustivel {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int distancia_km, gasto_litros;
		
		System.out.print("Informe a dist�ncia total percorrida (km): ");
		distancia_km = input.nextInt();

		System.out.print("Informe quantidade de combust�vel gasta (litros): ");
		gasto_litros = input.nextInt();
		
		System.out.println("Consumo m�dio = " + getConsumoMedio(distancia_km, gasto_litros) + " km/l");
	}
	
	public static double getConsumoMedio(int distancia, int litros) {
		return distancia / litros;
	}
}
