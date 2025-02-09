package com.pintia.codeday2;

import java.util.ArrayList;
import java.util.Scanner;

public class PTA049 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int sum=0;
        int[] max=new int[n];
        ArrayList<Integer>[] arr=new ArrayList[n];
        for (int i = 0; i < n; i++) {
            arr[i]=new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            max[i]=sc.nextInt()*10;
            sum+=max[i];
        }
        int id=1,index=0,flag=-1;
        for (int i = 0; i < sum; i++) {
            if(flag==index)
                id++;
            arr[index].add(id++);
            flag=index;
            index=(index+1)%n;
            while (sum-1!=i&&arr[index].size()==max[index])
                index=(index+1)%n;
        }
        for (int i = 0; i < n; i++) {
            System.out.println("#"+(i+1));
            for (int j = 0; j < arr[i].size(); j++) {
                if((j+1)%10==0)
                    System.out.println(arr[i].get(j));
                else System.out.print(arr[i].get(j)+" ");
            }
        }
    }
}
