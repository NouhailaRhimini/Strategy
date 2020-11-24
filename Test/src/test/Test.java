
package test;
import java.util.Arrays;

public class Test {

    public static void main(String[] args) {
    // we can provide any strategy to do the sorting 
        Produit[] produits = new Produit[3];
        produits[0] = new Produit("p1",45,1);
        produits[1] = new Produit("p2",78,2);
        produits[2] = new Produit("p3",12,3);
       
        
        // we can change the strategy without changing Context class
        Context ctx = new Context(new QuickSort());
        ctx.arrange(produits);
        // try it yourself then 
        System.out.println(Arrays.toString(produits));
        ctx = new Context(new BubbleSort());
        ctx.arrange(produits);
        // try it yourself then 
        System.out.println(Arrays.toString(produits));
        ctx = new Context(new InsertionSort());
        ctx.arrange(produits);
        // try it yourself then 
        System.out.println(Arrays.toString(produits));
    }

}
