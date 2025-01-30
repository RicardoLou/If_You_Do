package com.pintia.codeday2;

import java.util.Scanner;

public class PTA030 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        String[][] stu=new String[n/2][2];
        int k=0;
        for (int i = 0; i < n; i++) {
            String sex=sc.next();
            String name=sc.next();
            if(k < n/2) {
                stu[k][0]=name;
                stu[k][1]=sex;
                k++;
            }
            else{
                for (int j = n/2-1; j >=0; j--) {
                    if((stu[j][1].equals("0")||stu[j][1].equals("1"))&&!stu[j][1].equals(sex)) {
                        stu[j][1] = name;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < n/2; i++) {
            System.out.println(stu[i][0]+" "+stu[i][1]);
        }
    }
}
