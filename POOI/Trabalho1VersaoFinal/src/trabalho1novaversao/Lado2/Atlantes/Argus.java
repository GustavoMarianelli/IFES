/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package trabalho1novaversao.Lado2.Atlantes;

import java.util.LinkedList;
import trabalho1novaversao.Guerreiro;

/**
 *
 * @author gustavo
 */
public class Argus extends Atlante {
    
    public Argus(int numero, String nome, int idade, double peso) {
        super(numero, nome, idade, peso);
        this.setEnergia(60);
    }
    
    @Override
    public void atacarAdversario(Guerreiro atacado, LinkedList listaAtacado, LinkedList atacante) {
      
        if (atacado.isEstaVivo()) {
            this.setForcaAtaque(atacado.getEnergia());
            super.atacarAdversario(atacado, listaAtacado, listaAtacado);
        }
    }
    
}
