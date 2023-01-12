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
public class Mumia extends Egipcio {

    private boolean mortoVivo = false;
    
    public Mumia(int numero, String nome, int idade, double peso) {
        super(numero, nome, idade, peso);
        this.setForcaAtaque(50);
    }

    @Override
    public void atacarAdversario(Guerreiro atacado, LinkedList listaAtacado, LinkedList listaAtacante) {
        super.atacarAdversario(atacado, listaAtacado, listaAtacante);

        if (!atacado.isEstaVivo() && !this.mortoVivo) {
            Mumia m = new Mumia(5, atacado.getNome(), atacado.getIdade(), atacado.getPeso());
            m.mortoVivo = true;
            m.setForcaAtaque(5);
            listaAtacante.addLast(m);
        }
    }

    @Override
    public void morrer(LinkedList listaAtacado) {
        super.morrer(listaAtacado);
        if (!this.isEstaVivo() && !this.mortoVivo) {
            for (int i = 0; i < 4; i++) {
                Anubita vingador = new Anubita(1, this.getNome(), 0, 60);
                listaAtacado.addLast(vingador);
            }
        }
    }

}
