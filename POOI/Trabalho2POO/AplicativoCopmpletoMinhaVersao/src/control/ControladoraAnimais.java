/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package control;

import dao.AnimalFileDao;
import domain.Animal;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Vector;
/**
 *
 * @author gustavo
 */
public class ControladoraAnimais {
     private Vector<Animal> animais;
    private int marcador;
    AnimalFileDao animalDao;
    
    private String obterNomeColunaBanco(String coluna) {
        if (coluna.equals("Código"))
            return "codigo";
        if (coluna.equals("Nome"))
            return "nome";
        if (coluna.equals("Idade"))
            return "idade";
        if (coluna.equals("Peso"))
            return "peso";
        return "id";
    }

    public ControladoraAnimais() {
        this.animalDao = new AnimalFileDao();
    }
    
    private void atualizarAnimal(Animal animal, Vector linha){
        animal.setCodigo(Integer.parseInt((String)linha.get(0)));
        animal.setNome(linha.get(1).toString());
        animal.setIdade(Integer.parseInt((String) linha.get(2)));
        animal.setPeso(Double.parseDouble((String) linha.get(3)));
    }
    
    private Vector criarLinhaAnimal(Animal animal) {
        Vector linha = new Vector();
        linha.addElement(animal.getCodigo());
        linha.addElement(animal.getNome());
        linha.addElement(animal.getIdade());
        linha.addElement(animal.getPeso());
        return linha;
    }
     
    
    public void inserirNovoAnimal(Vector linha) throws FileNotFoundException, IOException, ClassNotFoundException{
        Animal animal = new Animal();
        this.atualizarAnimal(animal, linha);
        this.animais.add(animal);
        animalDao.salvarAnimais(this.animais);
    }
    
    public void setMarcador(int marcador){
        this.marcador = marcador;
    }

    public void alterarAnimal(Vector linha) throws FileNotFoundException, IOException, ClassNotFoundException {
        Animal animal = animais.get(marcador);
        this.atualizarAnimal(animal, linha);
        animalDao.salvarAnimais(this.animais);
    }
    
    public void  excluirAnimal() throws FileNotFoundException, IOException, ClassNotFoundException{
        animais.remove(marcador);
        animalDao.salvarAnimais(this.animais);
    }
    
    private Vector<Animal> obterAnimal(String coluna, boolean crescente) throws FileNotFoundException, IOException, ClassNotFoundException{
        String nomeColunaBanco = this.obterNomeColunaBanco(coluna);
        animais = animalDao.obterAnimais(nomeColunaBanco, crescente);
        return animais; 
    }

    public Vector obterLinhasAnimais(String coluna, boolean crescente) throws FileNotFoundException, IOException, ClassNotFoundException {
        Vector<Animal> animais = obterAnimal(coluna, crescente);
        Vector linhas = new Vector();
        
        // Montando as linhas
        for(int i = 0; i < animais.size(); i++){
            Animal animal = animais.get(i);
            linhas.addElement(this.criarLinhaAnimal(animal));
        }
        return linhas;
    }
}
