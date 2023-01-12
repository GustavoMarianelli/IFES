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
public class Satiro extends Atlante {
    
    public Satiro(int numero, String nome, int idade, double peso) {
        super(numero, nome, idade, peso);
        this.setForcaAtaque(5);
    }

    @Override
    public void atacarAdversario(Guerreiro atacado, LinkedList listaAtacado, LinkedList atacante) {
        super.atacarAdversario(atacado, listaAtacado, atacante);
        int tam = listaAtacado.size();
        int i = 0;
        if(atacado.isEstaVivo()) 
            i = 1;
        
        if(tam > 1){ 
            while(i < tam){
                Guerreiro aux = (Guerreiro) listaAtacado.get(i);
                aux.setEnergia(aux.getEnergia() - this.getForcaAtaque()); 
                aux.morrer(listaAtacado);
                if(!aux.isEstaVivo())
                    tam--;
                i++;
            }
        }
    }
    
}
