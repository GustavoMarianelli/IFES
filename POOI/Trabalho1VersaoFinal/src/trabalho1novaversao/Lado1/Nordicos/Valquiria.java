/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package trabalho1novaversao.Lado1.Nordicos;

import java.util.LinkedList;
import trabalho1novaversao.Guerreiro;

/**
 *
 * @author gustavo
 */
public class Valquiria extends Nordico {

    public Valquiria(int numero, String nome, int idade, double peso) {
        super(numero, nome, idade, peso);
        this.setForcaAtaque(20);
    }

    @Override
    public void atacarAdversario(Guerreiro atacado, LinkedList listaAtacado, LinkedList listaAtacante) {
        super.atacarAdversario(atacado, listaAtacado, listaAtacante);

        if (listaAtacante.size() > 1) { 
            Guerreiro aux = (Guerreiro) listaAtacante.get(1); 

            if ((aux.getEnergia() + 20) > 100 && aux.getNumero() <= 3) {     
                aux.setEnergia(100); 
            } else {
                aux.setEnergia(aux.getEnergia() + 20);
            }

        }
    }

}
