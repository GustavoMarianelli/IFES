/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package domain;

import java.util.Comparator;


/**
 *
 * @author gustavo
 */
public class ComparatorAnimalPorNomeCrescente implements Comparator <Animal>{
    @Override
    public int compare(Animal o1, Animal o2) {
        return o1.getNome().compareTo(o2.getNome());
    }
}
