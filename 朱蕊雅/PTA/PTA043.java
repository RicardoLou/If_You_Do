package com.pintia.codeday2;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PTA043 {
    public static void main(String[] args) throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.valueOf(br.readLine());
        int[] books;
        int[] flags;
        for (int i = 0; i < n; i++) {
            books=new int[1001];
            flags=new int[1001];
            int count=0;
            int sumtime=0;
            while (true){
                String[] info=br.readLine().split(" ");
                int num=Integer.valueOf(info[0]);
                String key=info[1];
                int time=toChange(info[2]);
                if(num==0)
                    break;
                if(key.equals("S")){
                    books[num]=time;
                    flags[num]=1;
                }
                else if(flags[num]==1){
                    sumtime+=time-books[num];
                    books[num]=0;
                    flags[num]=0;
                    count++;
                }
            }
            int result=0;
            if(count>0)
                result=(int)(sumtime*1.0/count+0.5);
            System.out.printf("%d %d\n",count,result);
        }
    }
    public static int toChange(String str){
        String[] arr=str.split(":");
        return Integer.valueOf(arr[0])*60+Integer.valueOf(arr[1]);

    }
}
