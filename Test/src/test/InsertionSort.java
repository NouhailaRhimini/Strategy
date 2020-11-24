

package test;

public class InsertionSort implements Strategy {
    public void sort(Comparable[] a) {
        System.out.println("sorting array using insertion sort strategy");
  // Sort a[] into increasing order.
  int N = a.length;
  
  // Insert a[i] among a[i-1], a[i-2], a[i-3]....
  for (int i = 1; i < N; i++) { 
   for ( int j = i; j > 0 && ( (a[j].compareTo( a[j-1]))< 0 ); j--)
   {
       Comparable temp = a[j];
       a[j] = a[j - 1];
       a[j - 1] = temp;    
   }    
  }

 }
}
