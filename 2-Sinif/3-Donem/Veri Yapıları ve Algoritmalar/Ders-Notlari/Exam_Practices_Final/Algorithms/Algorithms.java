package Algorithms;

public class Algorithms {

    // Factorial -- Tail Recursive
    public int FactorialTail(int n) {
        return FactorialTail(n, 1);
    }

    private int FactorialTail(int n, int k) {
        if (n < 0) System.out.println("hatalı giriş");
        if (n == 1) return k;
        return FactorialTail(n - 1, k * n);
    }

    // Factorial -- Divide and Conquer
    private int FactorialDivide(int n, int k) {
        if (k > 1) {
            int m = k / 2;
            return FactorialDivide(n, m) * FactorialDivide(n + m, k - m);
        }
        return n;
    }

    //Fibonacci -- Recursive
    public int FibonacciRecursive(int n) {
        if (n < 1) System.out.println("hatalı giriş");
        if (n == 1 || n == 2) return n - 1;
        return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
    }

    //Fibonacci -- Tail Recursive
    public int FibonacciTail(int n) {
        return FibonacciTail(n, 0, 1);
    }

    private int FibonacciTail(int n, int x, int y) {
        if (n < 0) System.out.println("hatalı giriş");
        if (n == 1) return x;
        if (n == 2) return y;
        return FibonacciTail(n - 1, y, x + y);
    }

    //Ebob -- Recursive -- öklid algoritması
    public int Ebob(int x, int y) {
        if (y == 0) return x;
        return Ebob(y, x % y);
    }

    //Ebob
    public int f2(int x, int y) {
        if (x == y) return x;
        else if (x > y) return f2(x - y, y);
        else return f2(y - x, x);
    }
}
