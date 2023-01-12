/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package trabalho1novaversao;

import java.util.LinkedList;
import java.util.Random;

/**
 *
 * @author gustavo
 */
public class Batalha {

    public static void ataque(Guerreiro atacante, Guerreiro atacado, LinkedList listaAtacante, LinkedList listaAtacado) {

        atacante.atacarAdversario(atacado, listaAtacado, listaAtacante);

    }

    public Guerreiro realizarBatalha(LinkedList lista1, LinkedList lista2) {
        Guerreiro perdedor = null;

        while (!lista1.isEmpty() && !lista2.isEmpty()) {
            Guerreiro guerreiro1 = (Guerreiro) lista1.getFirst();
            Guerreiro guerreiro2 = (Guerreiro) lista2.getFirst();

            Random random = new Random();
            int primeiro = random.nextInt(100);
          
            if (primeiro % 2 == 0) {
                ataque(guerreiro1, guerreiro2, lista1, lista2);

                if (guerreiro2.isEstaVivo()) {
                    ataque(guerreiro2, guerreiro1, lista2, lista1);
                }

            } else {
                ataque(guerreiro2, guerreiro1, lista2, lista1);

                if (guerreiro1.isEstaVivo()) {
                    ataque(guerreiro1, guerreiro2, lista1, lista2);
                }

            }

            guerreiro1.modificarFila(lista1);
            guerreiro2.modificarFila(lista2);

            if (lista1.isEmpty()) {
                perdedor = guerreiro1;
            } else if (lista2.isEmpty()) {
                perdedor = guerreiro2;
            }
        }
        return perdedor;
    }
}
