package com.pintia.codeday2;

import java.util.ArrayList;
import java.util.Scanner;

public class L103 {
        public static void main(String[] args) {
            Scanner sc=new Scanner(System.in);
            int s=sc.nextInt(),e=sc.nextInt(),n1,max=0,count=0;
            ArrayList<Integer> list = new ArrayList<>();
            for (int i = s; i <=e; i++) {
                count=0;
                int x=i;
                n1=i;
                while (n1>=10){
                    n1=1;
                    while (x!=0){
                        n1=n1*(x%10);
                        if(x%10==x){
                            x=n1;
                            count++;
                        }
                        x=x/10;
                    }
                }
                if(count==max){
                    list.add(i);
                }
                else if(count>max){
                    list.clear();
                    list.add(i);
                    max=count;
                }
            }
            System.out.println(max);
            for (int i = 0; i < list.size(); i++) {
                System.out.print(i == list.size() - 1 ? list.get(i) : list.get(i) + " ");
            }

        }
}
