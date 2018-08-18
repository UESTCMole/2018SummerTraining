import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner in=new Scanner(System.in);
    int T=in.nextInt(); 
    while (T>0){
      T--;
      BigInteger a,b,c,d;
      a=in.nextBigInteger();
      b=in.nextBigInteger();
      c=in.nextBigInteger();
      d=in.nextBigInteger();
      b=b.add(a);
      c=c.add(b);
      d=d.add(c);
      System.out.println(d);
    }
  } 
}
