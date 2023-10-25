import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Random;

public class Main {

    private static int[][] StrassenMultiply(int[][] A, int[][] B) {

        int n = A.length;

        int[][] res = new int[n][n];

        // si la matriz es de 1x1
        if (n == 1) {
            res[0][0] = A[0][0] * B[0][0];
        } else {

            // primera matriz
            int[][] a = new int[n / 2][n / 2];
            int[][] b = new int[n / 2][n / 2];
            int[][] c = new int[n / 2][n / 2];
            int[][] d = new int[n / 2][n / 2];

            // segunda matriz
            int[][] e = new int[n / 2][n / 2];
            int[][] f = new int[n / 2][n / 2];
            int[][] g = new int[n / 2][n / 2];
            int[][] h = new int[n / 2][n / 2];

            // Dividiendo la matriz A en 4
            divideArray(A, a, 0, 0);
            divideArray(A, b, 0, n / 2);
            divideArray(A, c, n / 2, 0);
            divideArray(A, d, n / 2, n / 2);

            // dividing matrix B into 4 parts
            divideArray(B, e, 0, 0);
            divideArray(B, f, 0, n / 2);
            divideArray(B, g, n / 2, 0);
            divideArray(B, h, n / 2, n / 2);

            int[][] p1 = StrassenMultiply(addMatrices(a, d), addMatrices(e, h));
            int[][] p2 = StrassenMultiply(addMatrices(c,d),e);
            int[][] p3 = StrassenMultiply(a, subMatrices(f, h));
            int[][] p4 = StrassenMultiply(d, subMatrices(g, e));
            int[][] p5 = StrassenMultiply(addMatrices(a,b), h);
            int[][] p6 = StrassenMultiply(subMatrices(c, a), addMatrices(e, f));
            int[][] p7 = StrassenMultiply(subMatrices(b, d), addMatrices(g, h));


            int[][] C11 = addMatrices(subMatrices(addMatrices(p1, p4), p5), p7);
            int[][] C12 = addMatrices(p3, p5);
            int[][] C21 = addMatrices(p2, p4);
            int[][] C22 = addMatrices(subMatrices(addMatrices(p1, p3), p2), p6);

            // Merge de las matrices
            copySubArray(C11, res, 0, 0);
            copySubArray(C12, res, 0, n / 2);
            copySubArray(C21, res, n / 2, 0);
            copySubArray(C22, res, n / 2, n / 2);
        }
        return res;
    }


    public static void main(String[] args) throws NumberFormatException, IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Ingresa el tamaño de las matrices (orden):");
        int order = Integer.parseInt(br.readLine());

        int[][] A = new int[order][order];
        int[][] B = new int[order][order];

        int[][] res = new int[order][order];

        // creando la primera matriz
        System.out.println("La primera matriz es:");
        for (int i = 0; i < order; i++) {
            for (int j = 0; j < order; j++) {
                Random rand = new Random();
                A[i][j] = rand.nextInt(10);
            }
        }
        //print matrix A
        int h = A.length;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < h; j++) {
                System.out.print(A[i][j] + "\t");
            }
            System.out.println();
        }
        System.out.println();

        // creando la segunda matriz
        System.out.println("La segunda matriz es:");
        for (int i = 0; i < order; i++) {
            for (int j = 0; j < order; j++) {
                Random rand = new Random();
                B[i][j] = rand.nextInt(10);
            }
        }
        //print matrix B
        int z = B.length;
        for (int i = 0; i < z; i++) {
            for (int j = 0; j < z; j++) {
                System.out.print(B[i][j] + "\t");
            }
            System.out.println();
        }
        System.out.println();

        res = StrassenMultiply(A, B);
        printMatrix(res);
    }

    // helper methods

    // Adding 2 matrices
    public static int[][] addMatrices(int[][] a, int[][] b) {
        int n = a.length;
        int[][] res = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = a[i][j] + b[i][j];
            }
        }
        return res;
    }

    // sacando la diferencia de 2 matrices
    public static int[][] subMatrices(int[][] a, int[][] b) {
        int n = a.length;
        int[][] res = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = a[i][j] - b[i][j];
            }
        }
        return res;
    }

    // print matrix
    public static void printMatrix(int[][] a) {
        int n = a.length;
        System.out.println("Resultant Matrix ");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(a[i][j] + "\t");
            }
            System.out.println();
        }
        System.out.println();
    }

    // dividiendo el array
    public static void divideArray(int[][] P, int[][] C, int iB, int jB)
    {
        for(int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++)
            for(int j1 = 0, j2 = jB; j1 < C.length; j1++, j2++)
                C[i1][j1] = P[i2][j2];
    }

    // copias
    public static void copySubArray(int[][] C, int[][] P, int iB, int jB)
    {
        for(int i1 = 0, i2 = iB; i1 < C.length; i1++, i2++)
            for(int j1 = 0, j2 = jB; j1 < C.length; j1++, j2++)
                P[i2][j2] = C[i1][j1];
    }

}