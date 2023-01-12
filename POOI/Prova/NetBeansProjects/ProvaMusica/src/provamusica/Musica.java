/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package provamusica;

/**
 *
 * @author 2020122760048
 */
public abstract class Musica {

    private String nome;
    private String compositor;
    private String interprete;
    private int anoCriacao;
    protected String toqueBase;

    public Musica(String nome, String compositor, String interprete, int anoCriacao) {
        this.nome = nome;
        this.composito/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package provamusica;

/**
 *
 * @author 2020122760048
 */
public abstract class Musica {

    private String nome;
    private String compositor;
    private String interprete;
    private int anoCriacao;
    protected String toqueBase;

    public Musica(String nome, String compositor, String interprete, int anoCriacao) {
        this.nome = nome;
        this.compositor = compositor;
        this.interprete = interprete;
        this.anoCriacao = anoCriacao;
    }

    public String getCompositor() {
        return compositor;
    }

    public String getNome() {
        return nome;
    }

    public String toqueBase() {
        return toqueBase;
    }

}
