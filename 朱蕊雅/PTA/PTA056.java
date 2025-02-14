package com.pintia.codeday2;

import java.util.Scanner;

public class PTA056 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n= sc.nextInt();
        sc.nextLine();
        String[][] player =new String[n][2];
        int sum=0;
        for (int i = 0; i < n; i++) {
            player[i][0]=sc.next();
            player[i][1]=sc.next();
            sum+=Integer.valueOf(player[i][1]);
        }
        int mid=sum/n/2;
        int win=mid;
        int winner=0;
        for (int i = 0; i < n; i++) {
            int compete=Integer.valueOf(player[i][1]);
            if(win>Math.abs(mid-compete)) {
                win = Math.abs(mid-compete);
                winner=i;
            }
        }
        System.out.println(mid+" "+player[winner][0]);
    }
}
