/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package trabalho1novaversao;

import java.util.LinkedList;

/**
 *
 * @author gustavo
 */
public abstract class Guerreiro {

    private int numero;
    private String nome;
    private int idade;
    private double peso;
    private int energia;
    private int forcaAtaque;
    protected boolean atacou;
    protected boolean estaVivo;
    protected boolean podeAtacar;

    public Guerreiro(int numero, String nome, int idade, double peso) {
        this.numero = numero;
        this.nome = nome;
        this.idade = idade;
        this.peso = peso;
        this.energia = 100;
        this.estaVivo = true;
        this.atacou = false;
      
    }


    
    public boolean isEstaVivo() {
        return estaVivo;
    }

    public void setEstaVivo(boolean estaVivo) {
        this.estaVivo = estaVivo;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public double getPeso() {
        return peso;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }

    public int getEnergia() {
        return energia;
    }

    public void setEnergia(int energia) {
        this.energia = energia;
    }

    public int getForcaAtaque() {
        return forcaAtaque;
    }

    public void setForcaAtaque(int forcaAtaque) {
        this.forcaAtaque = forcaAtaque;
    }

    public boolean isAtacou() {
        return atacou;
    }

    public void setAtacou(boolean atacou) {
        this.atacou = atacou;
    }

    public void atacarAdversario(Guerreiro atacado, LinkedList listaAtacado, LinkedList listaAtacante) {
       
        if (atacado.isEstaVivo() && listaAtacante.indexOf(this) == 0) { 
            this.setAtacou(true); 
            atacado.setEnergia(atacado.getEnergia() - this.getForcaAtaque());
            atacado.morrer(listaAtacado); 
        }
    }

    public void morrer(LinkedList listaAtacado) {
        if (this.getEnergia() <= 0) { 
            this.setEstaVivo(false); 
            listaAtacado.remove(this);
        }
    }

    public void modificarFila(LinkedList lista1) {
        
        if (this.isEstaVivo() && this.isAtacou()) {
            this.setAtacou(false);
            lista1.addLast(this); 
            lista1.remove(this); 
        }
    }
}
