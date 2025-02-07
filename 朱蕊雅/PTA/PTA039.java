package com.pintia.codeday2;
// L1-039古风排版
import java.util.Scanner;

public class PTA039 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int i = 0;
        sc.nextLine();
        String str = sc.nextLine();
        int column=(int)Math.ceil(str.length()*1.0/n);
        char[][] result=new char[n][column];
        //必须先给数组初始化，不然最后一行不显示
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < column; k++) {
                result[j][k] = ' ';
            }
        }
        for (int j = column-1; j >=0; j--) {
            for (int k = 0; k < n; k++) {
                if(i<str.length()) {
                    result[k][j]=str.charAt(i);
                    i++;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < column; k++) {
                System.out.print(result[j][k]);
            }
            System.out.println();
        }
    }
}
