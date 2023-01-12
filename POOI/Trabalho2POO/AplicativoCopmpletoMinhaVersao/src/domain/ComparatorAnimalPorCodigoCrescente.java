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
public class ComparatorAnimalPorCodigoCrescente implements Comparator<Animal>{
    @Override
    public int compare(Animal o1, Animal o2) {
        if (o1.getCodigo() < o2.getCodigo()) {
            return -1;
        } else if (o1.getCodigo() > o2.getCodigo()) {
            return 1;
        } else {
            return 0;
        }

    }
}
