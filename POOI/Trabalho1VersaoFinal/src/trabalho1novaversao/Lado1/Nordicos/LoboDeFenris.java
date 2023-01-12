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
public class LoboDeFenris extends Nordico {

    public LoboDeFenris(int numero, String nome, int idade, double peso) {
        super(numero, nome, idade, peso);
        this.setForcaAtaque(40);
    }

    @Override
    public void atacarAdversario(Guerreiro atacado, LinkedList listaAtacado, LinkedList listaAtacante) {
        this.aumentarAtaqueLobo(listaAtacante, this);
        super.atacarAdversario(atacado, listaAtacado, listaAtacante); 
        this.setForcaAtaque(40);
    }
    
    public void aumentarAtaqueLobo(LinkedList lista1, LoboDeFenris lobo) {
        int i = 1; 
        int qtdLobos = 0;
        int tam = lista1.size();
                
        if (tam > 1) { 
            while (i < tam) {
                Guerreiro aux = (Guerreiro) lista1.get(i);
                if (aux.getNumero() == 5) {
                    qtdLobos++;
                }
                i++;
            }
            this.setForcaAtaque(this.getForcaAtaque() + ((this.getForcaAtaque() * 20 / 100) * qtdLobos));
        }
    }
}
