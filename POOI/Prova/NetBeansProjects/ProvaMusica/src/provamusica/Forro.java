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
public class Forro extends Musica {

    private String regiao;

    public Forro(String regiao, String nome, String compositor, String interprete, int anoCriacao) {
        super(nome, compositor, interprete, anoCriacao);
        this.regiao = regiao;
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
public class Forro extends Musica {

    private String regiao;

    public Forro(String regiao, String nome, String compositor, String interprete, int anoCriacao) {
        super(nome, compositor, interprete, anoCriacao);
        this.regiao = regiao;
        this.toqueBase = "nanananana nanananana";

    }

}
