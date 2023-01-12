/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package trabalho1novaversao.Lado1.Gregos;

import java.util.LinkedList;
import trabalho1novaversao.Guerreiro;

/**
 *
 * @author gustavo
 */
public class LeaoDaNemeia extends Grego {

    public LeaoDaNemeia(int numero, String nome, int idade, double peso) {
        super(numero, nome, idade, peso);
        this.setForcaAtaque(30);
    }

    @Override
    public void atacarAdversario(Guerreiro atacado, LinkedList listaAtacado, LinkedList atacante) {
        super.atacarAdversario(atacado, listaAtacado, atacante);

        int i = 0, parar = 0, tam = listaAtacado.size();

        if (atacado.isEstaVivo()) {
            i = 1;
        }

        int novaForcaAtaque = 15;

        while (i < tam && parar < 2) {

            Guerreiro aux = (Guerreiro) listaAtacado.get(i);
            aux.setEnergia(aux.getEnergia() - novaForcaAtaque);
            aux.morrer(listaAtacado);
            if (!aux.isEstaVivo()) {
                tam--;
            }
            novaForcaAtaque -= 10;
            i++;
            parar++;

        }
    }
}
