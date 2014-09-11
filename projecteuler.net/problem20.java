/*
 * 	Completed on 4/1/2014
 *  www.projecteuler.net/problem=20 
 *  
 *  This is essentially an exercise on getting familiar with the BigInteger java class 
 *  
 *	"Find the sum of the digits in the number 100!"
 */
import java.math.BigInteger; 

public class problem20 {
	// dummy variables
	public BigInteger temp1 = new BigInteger("0");
	public BigInteger temp2 = new BigInteger("0"); 
	public BigInteger temp3 = new BigInteger("1"); 
	
	public BigInteger factorial(BigInteger n, BigInteger m) {
		if(n.intValue() == m.intValue())
			return n; 
		if(n.intValue() > m.intValue())
			return temp3; 
		else {
			temp2 = n;  //store n in temp2
			temp1 = temp1.subtract(temp1);  // temp = 0
			temp1 = temp1.add(n=n.add(m)); // temp = n+m
			temp1 = temp1.shiftRight(1); // temp = temp/2
			n = temp2; // restore n			
			return factorial(n, temp1).multiply(factorial(temp1 = temp1.add(BigInteger.ONE), m));
		}
	}
	
	public int sum(BigInteger a) {
		String num = a.toString();
		int sum=0; 		
		for(int i=0; i<num.length(); i++) sum += (num.charAt(i) - '0'); 
		return sum; 
	}

	public static void main(String[] args) {
		
		problem20 a = new problem20(); 		 
	    BigInteger start = new BigInteger("1"); 
		BigInteger end = new BigInteger("100"); 	
		System.out.println("SUM = " + a.sum(a.factorial(start, end))); 
	}
}
