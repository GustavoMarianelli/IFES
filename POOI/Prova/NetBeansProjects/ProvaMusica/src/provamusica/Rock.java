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
public class Rock extends Musica{
    private String album;

    public Rock(String album, String nome, String compositor, String interprete, int anoCriacao) {
        super(nome, compositor, interprete, anoCriacao);
        this.album  = album;
        this.toqueBase = "run run run";
    }

    public void setAlbum(String album) {
        this.album = album;
    }
    
    public boolean equals(Rock o) {
        if(this.getNome().equals(o.getNome()) && this.album.equals(o.album) && this.getCompositor().equals(o.getCompositor()))
            return true;
        else
            return false;
    }
    
    
    
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package provamusica;

/**
 *
 * @author 2020122760048
 */
public class Rock extends Musica{
    private String album;

    public Rock(String album, String nome, String compositor, String interprete, int anoCriacao) {
        super(nome, compositor, interprete, anoCriacao);
        this.album  = album;
        this.toqueBase = "run run run";
    }

    public void setAlbum(String album) {
        this.album = album;
    }
    
    public boolean equals(Rock o) {
        if(this.getNome().equals(o.getNome()) && this.album.equals(o.album) && this.getCompositor().equals(o.getCompositor()))
            return true;
        else
            return false;
    }
    
    
    
}
