package com.pintia.codeday2;
//答案正确但超时，不是满分答案需优化
//L1-005 考试座位号
import java.util.Scanner;
        public class L005 {
            public static void main(String[] args) {
                Scanner sc=new Scanner(System.in);
                int n=sc.nextInt();
                String[][] test=new String[n+1][2];
                for (int i = 0; i < n; i++) {
                    String id=sc.next();
                    String tryCode=sc.next();
                    String realCode=sc.next();
                    test[Integer.parseInt(tryCode)][0]=id;
                    test[Integer.parseInt(tryCode)][1]=realCode;
                }
                int m= sc.nextInt();
                String[] student=new String[m];
                for (int i = 0; i < m; i++) {
                    int a=sc.nextInt();
                    System.out.println(test[a][0]+" "+test[a][1]);
                }
                for (int i = 0; i < m; i++) {
                    System.out.println(student[i]);
                }
           }
        }
