//考试时，对java不熟的话就不要尝试用java了，除非是大数这种java方便很多的
import java.util.Arrays;
import java.util.Scanner;

import static java.util.Arrays.sort;

public class Main {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        int t;
        t=scanner.nextInt();
        String n="",m="";
        if(t<10) t=t*1000;
        else if(t<100) t*=100;
        else if(t<1000)t*=10;
        n=Integer.toString(t);
        char tmp[]=n.toCharArray();
        sort(tmp);
        n= new String(tmp);
        for(int i=0;i<n.length();i++){
            m=n.charAt(i)+m;
        }
        int x,y;
        x=Integer.parseInt(n);
        y=Integer.parseInt(m);
        int dev=0;
        if(x==y) System.out.printf("%04d - %04d = 0000",x,x);
        else{
            while(dev!=6174){
                dev=y-x;
                System.out.printf("%04d - %04d = %04d\n",y,x,dev);
                t=dev;
                if(t<10) t=t*1000;
                else if(t<100) t*=100;
                else if(t<1000)t*=10;
                dev=t;
                n=Integer.toString(dev);
                tmp=n.toCharArray();
                sort(tmp);
                n=new String(tmp);
                m="";
                for(int i=0;i<n.length();i++){
                    m=n.charAt(i)+m;
                }
                x=Integer.parseInt(n);
                y=Integer.parseInt(m);
            }
        }
    }
}
