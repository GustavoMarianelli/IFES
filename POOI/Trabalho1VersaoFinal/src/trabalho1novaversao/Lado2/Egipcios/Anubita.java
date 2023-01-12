/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package trabalho1novaversao.Lado2.Egipcios;

import java.util.LinkedList;
import trabalho1novaversao.Guerreiro;

/**
 *
 * @author gustavo
 */
public class Anubita extends Egipcio {

    public Anubita(int numero, String nome, int idade, double peso) {
        super(numero, nome, idade, peso);
        this.setForcaAtaque(15);
    }

    @Override
    public void atacarAdversario(Guerreiro atacado, LinkedList listaAtacado, LinkedList atacante) {
        super.atacarAdversario(atacado, listaAtacado, atacante);
        Guerreiro aux;
        if (listaAtacado.size() > 1) {
            aux = (Guerreiro) listaAtacado.getLast(); 
            if (aux.isEstaVivo()) { 
                aux.setEnergia(aux.getEnergia() - this.getForcaAtaque()); 
                aux.morrer(listaAtacado);
            }
        }
    }

}
