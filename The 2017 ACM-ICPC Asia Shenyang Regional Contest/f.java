import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Main{
  static int N = 130;
  static BigInteger[] x=new BigInteger[N];
  static BigInteger[] y=new BigInteger[N];
  static BigInteger[] t=new BigInteger[N];
  public static void main(String[] args){
    Scanner in=new Scanner(System.in);
    int T; T=in.nextInt();
    x[1]=BigInteger.valueOf(2);
    y[1]=BigInteger.valueOf(1);
    t[1]=BigInteger.valueOf(4);
    for (int i=2;i<=128;i++){
      x[i]=(x[i-1].multiply(x[1])).add(y[1].multiply(y[i-1]).multiply(BigInteger.valueOf(3)));
      y[i]=(x[i-1].multiply(y[1])).add(x[1].multiply(y[i-1]));
      t[i]=x[i].multiply(BigInteger.valueOf(2));
      //System.out.println(t[i]);
    }
    //System.out.println(BigInteger.valueOf(1).compareTo(BigInteger.valueOf(4)));
    while (T>0){
      T--;
      BigInteger n;
      n=in.nextBigInteger();
      //System.out.println(n);
      for (int i=1;i<=128;i++){
        if (n.compareTo(t[i])<=0){
          System.out.println(t[i]);
          break;
        }
      }
    }
  }
}
