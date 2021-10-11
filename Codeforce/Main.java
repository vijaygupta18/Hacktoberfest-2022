import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		PrintWriter out = new PrintWriter(System.out);
		InputReader in = new InputReader(System.in);

		// Main Program
		{
			
		}
		// Main Program Ends
		out.close();
	}

	static class InputReader {
		BufferedReader br;
		StringTokenizer to;

		InputReader(InputStream stream) {
			br = new BufferedReader(new InputStreamReader(stream));
			to = new StringTokenizer("");
		}

		String next() {
			while (!to.hasMoreTokens()) {
				try {
					to = new StringTokenizer(br.readLine());
				} catch (IOException e) {
				}
			}
			return to.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		int[] readArray(int n) {
			int array[] = new int[n];
			for (int i = 0; i < array.length; i++)
				array[i] = nextInt();
			return array;
		}
	}
}