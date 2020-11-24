
package test;
import java.lang.Comparable;
import java.util.Comparator;


public class Produit implements Comparable<Produit>{
private String nom;
private int prix;
private int valeur;

public Produit(String nom, int prix, int valeur){
this.nom = nom;
this.prix = prix;
this.valeur = valeur;}
@Override 
public int compareTo(Produit produits){
 return this.prix - produits.prix;
}
@Override
    public String toString() {
        return "{" + "nom='" + nom + '\'' +
                    ", prix=" + prix + '\'' +
                    ", valeur=" + valeur +'}';
    }
} 