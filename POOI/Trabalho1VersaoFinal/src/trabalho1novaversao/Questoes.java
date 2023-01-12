/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package trabalho1novaversao;

import java.util.LinkedList;

/**
 *
 * @author gustavo
 */
public class Questoes {

    public static int somarPesos(LinkedList lado) {
        int tam = lado.size();
        int soma = 0;
        int i = 0;

        while (i < tam) { 
            Guerreiro g = (Guerreiro) lado.get(i);
            soma += g.getPeso();
            i++;
        }
        return soma;
    }

    public static int maiorIdade(LinkedList lado) {
        int tam = lado.size();

        Guerreiro g = (Guerreiro) lado.getFirst();

        int maiorIdade = g.getIdade(); 

        for (int i = 1; i < tam; i++) {
            g = (Guerreiro) lado.get(i); 
            if (g.getIdade() > maiorIdade) { 
                maiorIdade = g.getIdade(); 
            }

        }
        return maiorIdade; 
    }

    public static void mostrarIdade(int maiorIdade, LinkedList lado) {

        for (int i = 0; i < lado.size(); i++) {
            Guerreiro g = (Guerreiro) lado.get(i);
            if (g.getIdade() == maiorIdade) {
                System.out.printf("%s é o mais velho (%d unidades)\n", g.getNome(),g.getIdade());
            }
        }
    }

    public static void ladoVencedor(int resultado) {

        if (resultado == 1) { 
            System.out.println("Gregos e Nórdicos venceram.");
        } else {
            System.out.println("Atlantes e Egípcios venceram.");
        }
    }

    public static void mostrarDadosLutador(Guerreiro vencedor, Guerreiro perdedor) {
        int pesoVencedor = (int) vencedor.getPeso();
        int pesoPerdedor = (int) perdedor.getPeso();
        System.out.printf("%s, %d, %d\n",
                perdedor.getNome(), perdedor.getIdade(), pesoPerdedor);
        System.out.printf("%s, %d, %d\n",
                vencedor.getNome(), vencedor.getIdade(), pesoVencedor);
       
    }
}
