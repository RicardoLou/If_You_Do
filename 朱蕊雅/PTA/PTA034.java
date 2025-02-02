package com.pintia.codeday2;
//L034 点赞  卡JAVA时间！！待我学成归来优化
import java.util.Scanner;

public class PTA034 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] id = new int[1001];
        for (int i = 1; i < n+1; i++) {
            int num=sc.nextInt();
            for (int j = 0; j < num; j++) {
                id[sc.nextInt()]++;
            }
        }
        int resualt = 0,max=0;
        for (int i = 1; i < id.length; i++) {
            if(id[i]!=0)
                if(max<=id[i]) {
                    max=id[i];
                    resualt = i;
                }
        }
        System.out.println(resualt+" "+id[resualt]);
    }
}
