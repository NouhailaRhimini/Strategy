

package test;

public class BubbleSort implements Strategy {
public void sort(Comparable[] a) {
        System.out.println("sorting array using bubble sort strategy");}
         public void bubbleSort(Comparable[] a, int start, int end) {
    //flag to see if an item was swapped or not
       boolean swap = false;
      // loop size - 1 times   
       for (int i = start + 1; i <= end; i++) {
          swap = false;
          //loop from beginning of array to (last element - i)
          for (int j = 0; j <= end - i; j++) {
          // swap if 1st item greater than 2nd item
             if (a[j].compareTo(a[j + 1]) > 0) {
             // swap
                Comparable temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swap = true;
             }
          }
    }
}
}