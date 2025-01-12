package com.pintia.codeday2;

import java.util.Scanner;
//L1-003 个位数统计
public class L003 {
        public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        char[] chars=sc.nextLine().toCharArray();//使用scanner类的nextline()方法读取一行输入
            // 然后使用toChararray()方法将其转换为字符数组，存储在char数组中
        int[] ints=new int[10];
        for (int i = 0; i < chars.length; i++) {
            ints[chars[i]-'0']++;//一个char类型的数字减去char类型的'0'，就等于int型的数字
        }
        for (int i = 0; i <ints.length; i++) {
            if(ints[i]>0)
                System.out.println(i+":"+ints[i]);
        }

    }
}
