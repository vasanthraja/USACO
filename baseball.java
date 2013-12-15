/*
ID: your_id_here
LANG: JAVA
TASK: baseball
*/

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 *
 * @author vasanth
 */

public class baseball {
    
    public static int[] insertion(int[] a) {
        int temp;
        for (int i = 1; i < a.length; i++) {
            int elem = a[i];
            temp = i;
            for (int j = i - 1; j >= 0; j--) {
                if (elem < a[j]) {
                    a[j + 1] = a[j];
                    temp = j;
                }
                else
                    break;
            }
            a[temp] = elem; 
            
        }
        //for (int i = 0; i < a.length; i++) {
        //    int j = a[i];
        //    System.out.print(a[i] +" " );
            
        //}
        return a;
    }
    public static void main(String[] args) throws IOException {
        int count = 0;
        BufferedReader f = new BufferedReader(new FileReader("baseball.in"));
                                                  // input file name goes above
    PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("baseball.out")));
    // Use StringTokenizer vs. readLine/split -- lots faster
    StringTokenizer st = new StringTokenizer(f.readLine());
						  // Get line, break into tokens
    int i1 = Integer.parseInt(st.nextToken());    // first integer
    int position[] = new int[i1];
    int tmp[] = new int[position.length];
        for (int i = 0; i < position.length; i++) {
            st = new StringTokenizer(f.readLine());
            position[i] = Integer.parseInt(st.nextToken());       
        }
        //int res = new USACO().baseball(i1, position, tmp, 0, 0);
        position = new baseball().insertion(position);
        System.out.println("");
        for (int i = 0; i < position.length; i++) {
            
            System.out.print(position[i] +" " );
            
        }
        System.out.println("");
        for (int i = 0; i < position.length - 2 ; i++) {
            for (int j = i + 1; j < position.length - 1; j++) {
                for (int k = j + 1; k < position.length; k++) {
                    if (((Math.abs(position[k] - position[j])) >= Math.abs((position[i] - position[j])) && Math.abs((position[k] - position[j]))<= Math.abs(2 *(position[i] - position[j]))))
                            //System.out.println(position[i] + " "+ position[j] +" "+ position[k] + " ");
                            count++;
                }
            }
        }
        //System.out.println("" + res);
        // second integer
    out.println(count);                           // output result
    out.close();                                  // close the output file
    System.exit(0);                               // don't omit this!
    }
}

