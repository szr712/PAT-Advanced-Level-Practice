import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner scanner=new Scanner(System.in);
        int n;
        n=scanner.nextInt();
        for(int i=0;i<n;i++){
            BigInteger a,b,c;
            a=scanner.nextBigInteger();
            b=scanner.nextBigInteger();
            c=scanner.nextBigInteger();
            a=a.add(b);
            if(a.compareTo(c)==1){
                int tmp=i+1;
                System.out.println("Case #"+tmp+": true");
            }
            else{
                int tmp=i+1;
                System.out.println("Case #"+tmp+": false");
            }
        }
    }
}
