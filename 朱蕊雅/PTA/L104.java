package com.pintia.codeday2;

import java.util.Scanner;
//L1-104 九宫格
public class L104 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[] rs=new int[n];
        for (int i = 0; i < n; i++) {
            int temp=0;
            int result=1;
            int[][] arr=new int[9][9];
            for (int j = 0; j < 9; j++) {
                for (int k = 0; k < 9; k++) {
                    arr[j][k] = sc.nextInt();
                    if(arr[j][k]>9||arr[j][k]<1)
                        result=0;
                }
            }
            for (int j = 0; j < 9; j++) {
                for (int k = 0; k < 9; k+=3) {
                    for (int l = 0; l < 9; l+=3) {
                        int sum=0;
                        for (int m = k; m <k+3 ; m++) {//0 3
                            for (int o = l; o <l+3 ; o++) {//0 3
                                sum=sum+arr[m][o];
//                                System.out.println(arr[m][o]);
                            }
                        }
//                        System.out.println(sum);
                        if(sum!=45)
                            temp++;
                    }
                }
                if(temp>0)
                        result=0;
//                System.out.println(result);
                for (int k = 0; k < 9; k++) {
                    for (int l = 0; l < k; l++) {
                        if (arr[j][k] == arr[j][l])
                            result = 0;
                    }
                    for (int l = 0; l < j; l++) {
                        if (arr[j][k] == arr[l][k]) {
                            result = 0;
                        }
                    }
                }
//                System.out.println(result);
            }
            rs[i]=result;
            }

        for (int i = 0; i < n; i++) {
            System.out.println(rs[i]);
        }
    }
}
