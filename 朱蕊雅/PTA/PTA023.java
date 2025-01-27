package com.pintia.codeday2;

import java.util.Scanner;

public class PTA023 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int g=0,p=0,l=0,t=0;
        String str=sc.nextLine();
        for (int i = 0; i < str.length(); i++) {
                if(str.charAt(i)=='G'||str.charAt(i)=='G'+32)
                    g++;
                if(str.charAt(i)=='P'||str.charAt(i)=='P'+32)
                    p++;
                if(str.charAt(i)=='L'||str.charAt(i)=='L'+32)
                    l++;
                if(str.charAt(i)=='T'||str.charAt(i)=='T'+32)
                    t++;
        }
        while (g>0||p>0||l>0||t>0){
            if(g>0){
                System.out.print('G');
                g--;
            }
            if(p>0) {
                System.out.print('P');
                p--;
            }
            if(l>0) {
                System.out.print('L');
                l--;
            }
            if(t>0) {
                System.out.print('T');
                t--;
            }
        }
    }
}
