// 313. Super Ugly Number https://leetcode.com/problems/super-ugly-number/
class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int[] idx = new int[primes.length];
        int[] ugly = new int[n];
        ugly[0] = 1;
        
        for (int i = 1; i < n; i++) {
            ugly[i] = Integer.MAX_VALUE;
            for (int j = 0; j < primes.length; j++) {
                ugly[i] = Math.min(ugly[i], ugly[idx[j]] * primes[j]);
            }
            
            for (int j = 0; j < primes.length; j++) {
                while (ugly[idx[j]] * primes[j] <= ugly[i]) idx[j]++;
            }
        }
        
        return ugly[n-1];
    }
}
