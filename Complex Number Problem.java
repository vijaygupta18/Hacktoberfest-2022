/*
Sample Input 1 :
4 5
6 7
1

Sample Output 1 :
10 + i12
*/

public class ComplexNumbers {
	// Complete this class
    private int real;
	private int imag;
	
	public ComplexNumbers(int real,int imag) {
		this.real=real;
		this.imag=imag;
	}
	
	public int getImag() {
		return imag;
	}
	
	public int getReal() {
		return real;
	}
	
	public void setImag(int imag) {
		this.imag = imag;
	}
	
	public void setReal(int real) {
		this.real = real;
	}
	
	public void plus(ComplexNumbers c) {
		int real=this.real + c.real;
		int imag=this.imag+c.imag;
		this.real=real;
		this.imag=imag;
	}
	public void multiply(ComplexNumbers c) {
		int real= this.real * c.real - this.imag * c.imag;
		int imag= this.real * c.imag + c.real * this.imag;
		this.real=real;
		this.imag=imag;
	}
	public static ComplexNumbers add(ComplexNumbers c1,ComplexNumbers c2) {
		int real=c1.real + c2.real;
		int imag=c1.imag+c2.imag;
		return new ComplexNumbers(real, imag);
	}
	public static ComplexNumbers multiply(ComplexNumbers c1,ComplexNumbers c2) {
		int real= c1.real * c2.real - c1.imag * c2.imag;
		int imag= c1.real * c2.imag + c2.real * c1.imag;
		return new ComplexNumbers(real, imag);
	}
	public void print() {
		System.out.println(this.real + " + i"+ this.imag);
	}
	public ComplexNumbers conjugate() {
		int imag=-this.imag;
		return new ComplexNumbers(this.real, imag);
	}
	
}
