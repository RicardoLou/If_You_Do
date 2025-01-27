package com.pintia.codeday2;

import java.util.Scanner;

public class PTA018 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt(),b=sc.nextInt(),n=sc.nextInt();
        int A=a,B=b;
        sc.nextLine();
        int[][] game=new int[n][4];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                game[i][j]=sc.nextInt();
            }
        }
        for (int i = 0; i < n; i++) {
            if(a>=0&&b>=0) {
                    if (game[i][1] == (game[i][0] + game[i][2]) && game[i][3] == (game[i][0] + game[i][2]))
                        continue;
                    if (game[i][1] == (game[i][0] + game[i][2]))
                        a--;
                    else if (game[i][3] == (game[i][0] + game[i][2]))
                        b--;
            }
            else break;
        }
        if(a<0) {
            System.out.println("A");
            System.out.println(B-b);
        }
        else {
            System.out.println("B");
            System.out.println(A-a);
        }
    }
}
