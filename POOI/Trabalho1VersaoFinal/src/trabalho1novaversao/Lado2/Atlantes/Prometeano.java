/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package trabalho1novaversao.Lado2.Atlantes;

import static java.lang.Math.pow;
import java.util.LinkedList;

/**
 *
 * @author gustavo
 */
public class Prometeano extends Atlante {

    private int novaEnergia; 
    private int qtdMortes = 0; 

    public Prometeano(int numero, String nome, int idade, double peso) {
        super(numero, nome, idade, peso);
        this.setForcaAtaque(10);
    }

    @Override
    public void morrer(LinkedList listaAtacado) {

        super.morrer(listaAtacado);
        if (!this.isEstaVivo()) {
            this.qtdMortes++; 
            this.novaEnergia = (int) (100 / (pow(2, this.qtdMortes)));
            this.dividirPrometeano(listaAtacado);
        }
    }

    public void dividirPrometeano(LinkedList lista) {

        if (this.novaEnergia > 1) {

            if (this.getEnergia() <= 0) {
                this.morrer(lista);
            } else {
                Prometeano aux1 = new Prometeano(1, "Prometeano dividido", this.getIdade(), this.getPeso());
                aux1.setEnergia(this.novaEnergia); 
                aux1.qtdMortes = this.qtdMortes;
                Prometeano aux2 = aux1; 
                lista.add(aux1);
                lista.add(aux2);

            }
        }
    }

}
