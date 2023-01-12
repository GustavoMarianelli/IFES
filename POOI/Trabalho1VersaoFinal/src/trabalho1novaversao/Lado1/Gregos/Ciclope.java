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
public class Ciclope extends Grego {

    public Ciclope(int numero, String nome, int idade, double peso) {
        super(numero, nome, idade, peso);
        this.setForcaAtaque(40);
    }

    @Override
    public void atacarAdversario(Guerreiro atacado, LinkedList listaAtacado, LinkedList atacante) {
        super.atacarAdversario(atacado, listaAtacado, atacante);
        
        if (atacado.isEstaVivo() && !atacado.isAtacou()) {
            listaAtacado.addLast(atacado);
            listaAtacado.remove(atacado);
            this.modificarFila(atacante);
        }
    }

}
