package com.pintia.codeday2;
//L1-011 A-B
//运行超时，拿不到满分，需优化，下不了手啊啊啊啊
import java.util.Scanner;

public class PTA011 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String a=sc.nextLine();
        String b=sc.nextLine();
        String[] str=a.split(" ");
        for (int i = 0; i < str.length; i++) {
            String resualt="";
            for (int j = 0; j < str[i].length(); j++) {//I
                int k;
                for (k = 0; k < b.length(); k++) {
                    if (str[i].charAt(j) == b.charAt(k)) {
                        if(j+1==str[i].length())
                            resualt+= "";
                        else {
                            resualt+= str[i].charAt(j + 1);
                            j++;
                        }
                        break;
                    }
                }
                if(k==b.length())
                    resualt+=str[i].charAt(j);
            }
            str[i]=resualt;
        }
        for (int i = 0; i < str.length; i++) {
            if(i!=str.length)
                System.out.printf(str[i]+" ");
        }
    }
}
//import java.util.Scanner;
//
//public class Main {
//    public static void main(String[] args) {
//        Scanner scanner = new Scanner(System.in);
//        // 读取输入的字符串 A
//        String strA = scanner.nextLine();
//        // 读取输入的字符串 B
//        String strB = scanner.nextLine();
//        StringBuilder result = new StringBuilder();
//        for (int i = 0; i < strA.length(); i++) {
//            char c = strA.charAt(i);
//            // 判断字符 c 是否存在于 strB 中
//            if (strB.indexOf(c) == -1) {
//                result.append(c);
//            }
//        }
//        System.out.println(result.toString());
//    }
//}
