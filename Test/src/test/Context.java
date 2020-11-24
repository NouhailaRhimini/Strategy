
package test;
public class Context {
private final Strategy strategy;

    public Context(Strategy strategy) {
        this.strategy = strategy;
    }
    public void arrange(Comparable[] a) {
        strategy.sort(a);
    }
}
