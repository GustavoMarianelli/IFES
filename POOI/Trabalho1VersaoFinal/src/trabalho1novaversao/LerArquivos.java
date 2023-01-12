/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package trabalho1novaversao;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Scanner;
import trabalho1novaversao.Lado1.Gregos.Ciclope;
import trabalho1novaversao.Lado1.Gregos.Hidra;
import trabalho1novaversao.Lado1.Gregos.LeaoDaNemeia;
import trabalho1novaversao.Lado1.Nordicos.LoboDeFenris;
import trabalho1novaversao.Lado1.Nordicos.Valquiria;
import trabalho1novaversao.Lado2.Atlantes.Argus;
import trabalho1novaversao.Lado2.Atlantes.Prometeano;
import trabalho1novaversao.Lado2.Atlantes.Satiro;
import trabalho1novaversao.Lado2.Egipcios.Anubita;
import trabalho1novaversao.Lado2.Egipcios.Mumia;

/**
 *
 * @author gustavo
 */
public class LerArquivos {

    public static void lerArquivo(String arquivo, LinkedList lista, int lado) throws FileNotFoundException, IOException {

    
        int tipo, idade;
        String nome;
        double peso;

        try (FileInputStream file = new FileInputStream(arquivo)) {
            Scanner scan = new Scanner(file);
            
            while (scan.hasNext()) {
                tipo = scan.nextInt();
                nome = scan.next();
                idade = scan.nextInt();
                peso = scan.nextDouble();
                
                switch (tipo) {
                    case 1:
                        if (lado == 1) {
                            Ciclope c = new Ciclope(tipo, nome, idade, peso);
                            lista.add(c);
                        } else {
                            Prometeano p = new Prometeano(tipo, nome, idade, peso);
                            lista.add(p);
                        }
                        break;
                        
                    case 2:
                        if (lado == 1) {
                            LeaoDaNemeia ldn = new LeaoDaNemeia(tipo, nome, idade, peso);
                            lista.add(ldn);
                        } else {
                            Satiro s = new Satiro(tipo, nome, idade, peso);
                            lista.add(s);
                        }
                        
                        break;
                        
                    case 3:
                        if (lado == 1) {
                            Hidra h = new Hidra(tipo, nome, idade, peso);
                            lista.add(h);
                        } else {
                            Argus a = new Argus(tipo, nome, idade, peso);
                            lista.add(a);
                        }
                        break;
                    case 4:
                        if (lado == 1) {
                            Valquiria v = new Valquiria(tipo, nome, idade, peso);
                            lista.add(v);
                        } else {
                            Anubita anub = new Anubita(tipo, nome, idade, peso);
                            lista.add(anub);
                        }
                        
                        break;
                    case 5:
                        if (lado == 1) {
                            LoboDeFenris ldf = new LoboDeFenris(tipo, nome, idade, peso);
                            lista.add(ldf);
                        } else {
                            Mumia m = new Mumia(tipo, nome, idade, peso);
                            lista.add(m);
                        }
                        break;
                }
                
            }
            
            file.close();
        }
    }
    
  
}
