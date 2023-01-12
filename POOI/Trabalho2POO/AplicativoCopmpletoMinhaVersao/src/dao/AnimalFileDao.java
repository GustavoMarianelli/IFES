/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package dao;

import domain.Animal;
import domain.ComparatorAnimalPorCodigoCrescente;
import domain.ComparatorAnimalPorCodigoDecrescente;
import domain.ComparatorAnimalPorIdadeCrescente;
import domain.ComparatorAnimalPorIdadeDecrescente;
import domain.ComparatorAnimalPorNomeCrescente;
import domain.ComparatorAnimalPorNomeDecrescente;
import domain.ComparatorAnimalPorPesoCrescente;
import domain.ComparatorAnimalPorPesoDecrescente;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Collections;
import java.util.Vector;

/**
 *
 * @author gustavo
 */
public class AnimalFileDao {
    public void salvarAnimais(Vector<Animal> animais) throws FileNotFoundException, IOException, ClassNotFoundException {
        try (FileOutputStream arquivo = new FileOutputStream(AnimalFileInformation.getCaminhoArquivo() + AnimalFileInformation.getNomeArquivo())) {
            ObjectOutputStream objGravar = new ObjectOutputStream(arquivo);
            
            
            objGravar.writeObject(animais);
            objGravar.flush();
            objGravar.close();
            arquivo.flush();
        }
    }

    private boolean estaArquivoVazio() throws FileNotFoundException, IOException {
      
        String local_arquivo = AnimalFileInformation.getCaminhoArquivo() + AnimalFileInformation.getNomeArquivo();
        boolean estaVazio;
        try (FileInputStream arquivoLeitura = new FileInputStream(local_arquivo)) {
            estaVazio = (arquivoLeitura.read() == -1);
        }
        return estaVazio;
    }

    public Vector<Animal> obterAnimal() throws FileNotFoundException, IOException, ClassNotFoundException {
     
        if (estaArquivoVazio()) {
            return new Vector();
        } else {
            //Classe responsavel por recuperar os objetos do arquivo
            String local_arquivo = AnimalFileInformation.getCaminhoArquivo() + AnimalFileInformation.getNomeArquivo();
            Vector<Animal> vetor;
            try (FileInputStream arquivoLeitura = new FileInputStream(local_arquivo); ObjectInputStream objLeitura = new ObjectInputStream(arquivoLeitura)) {
                vetor = (Vector<Animal>) objLeitura.readObject();
            }
            return vetor;
        }
    }

   
    public Vector<Animal> obterAnimais(String coluna, boolean crescente) throws FileNotFoundException, IOException, ClassNotFoundException {
        Vector<Animal> animais = this.obterAnimal();
        switch (coluna) {
            case "codigo":
                if (crescente) Collections.sort(animais, new ComparatorAnimalPorCodigoCrescente());
                else Collections.sort(animais, new ComparatorAnimalPorCodigoDecrescente());
                break;
            case "nome":
                if (crescente) Collections.sort(animais, new ComparatorAnimalPorNomeCrescente());
                else Collections.sort(animais, new ComparatorAnimalPorNomeDecrescente());
                break;
            case "idade":
                if (crescente) Collections.sort(animais, new ComparatorAnimalPorIdadeCrescente());
                else Collections.sort(animais, new ComparatorAnimalPorIdadeDecrescente());
                break;
            case "peso":
                if (crescente) Collections.sort(animais, new ComparatorAnimalPorPesoCrescente());
                else Collections.sort(animais, new ComparatorAnimalPorPesoDecrescente());
                break;
            default:
                break;
        }
        
        return animais;
    }
}
