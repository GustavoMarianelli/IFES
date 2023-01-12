/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package trabalho1novaversao;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.LinkedList;

/**
 *
 * @author gustavo
 */
public class Trabalho1NovaVersao {

    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException {
        LinkedList<Guerreiro> lista1 = new LinkedList<>();
        LinkedList<Guerreiro> lista2 = new LinkedList<>();

        try {
            LerArquivos.lerArquivo("./arq1.txt", lista1, 1);
            LerArquivos.lerArquivo("./arq2.txt", lista2, 2);
            
        } catch (FileNotFoundException error) {
            error.printStackTrace();
        }
        
        
        System.out.printf("Gregos e Nórdicos pesam - %d unidades\n", Questoes.somarPesos(lista1));
        System.out.printf("Atlantes e Egípcios pesam - %d unidades\n", Questoes.somarPesos(lista2));

        int maiorIdade1 = Questoes.maiorIdade(lista1); 
        int maiorIdade2 = Questoes.maiorIdade(lista2);

        if (maiorIdade1 > maiorIdade2)
            maiorIdade2 = maiorIdade1;

        Questoes.mostrarIdade(maiorIdade2, lista1);
        Questoes.mostrarIdade(maiorIdade2, lista2);

        Batalha b = new Batalha();

        Guerreiro perdedor = b.realizarBatalha(lista1, lista2); 

        int resultado;

        if (lista1.isEmpty()) {
            resultado = 2;
            Questoes.ladoVencedor(resultado);
            Questoes.mostrarDadosLutador(lista2.getLast(), perdedor);
        } else if (lista2.isEmpty()) {
            resultado = 1;
            Questoes.ladoVencedor(resultado);
            Questoes.mostrarDadosLutador(lista1.getLast(), perdedor);
        }

    }

}
