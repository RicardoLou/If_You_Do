package com.pintia.codeday2;

import java.util.Scanner;

public class PTA048 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int aRow=sc.nextInt();
        int aColumn= sc.nextInt();
        int[][] A=new int[aRow][aColumn];
        for (int i = 0; i < aRow; i++) {
            for (int j = 0; j < aColumn; j++) {
                A[i][j]=sc.nextInt();
            }
        }
        int bRow=sc.nextInt();
        int bColumn= sc.nextInt();
        if(aColumn==bRow){
            System.out.println(aRow+" "+bColumn);
            int[][] B=new int[bRow][bColumn];
            for (int i = 0; i < bRow; i++) {
                for (int j = 0; j < bColumn; j++) {
                    B[i][j]=sc.nextInt();
            }
        }
            for (int i = 0; i < aRow; i++) {
                for (int j = 0; j < bColumn; j++) {
                    int sum=0;
                    for (int k = 0; k <bRow ; k++) {
                        sum+=A[i][k]*B[k][j];
                    }
                    if(j+1==bColumn)
                        System.out.print(sum);
                    else System.out.print(sum+" ");
                }
                System.out.println();
            }
        }
        else System.out.println("Error: "+aColumn+" != "+bRow);

    }
}
