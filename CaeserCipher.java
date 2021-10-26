import java.io.*;
import java.util.Arrays;
import java.util.HashMap;

class Basic{
    String allChar="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int indexOfChar(char c){
        for(int i=0;i< allChar.length();i++) {
            if(allChar.charAt(i)==c)
                return i;
        }
        return -1;
    }

    char charAtIndex(int pos){
        return allChar.charAt(pos);
    }
}

class Assignment {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Ceaser Cipher\n To Encrypt given plain text enter 1\n To Decrypt given cipher text enter 2\n To Find encryption key using brute force attack enter 3\n To Find encryption key using frequency analysis attack enter 4");
        int n = Integer.parseInt(br.readLine());
        File input = new File("C:\\Users\\Admin\\.IntelliJIdea2019.1\\config\\scratches\\input.txt");
        File output = new File("C:\\Users\\Admin\\.IntelliJIdea2019.1\\config\\scratches\\output.txt");
        //ENCRYPTION
        if (n == 1) {
            //System.out.println("Enter the Plain text to encrypt:");
            BufferedReader br1 = new BufferedReader(new FileReader(input));
            BufferedWriter or = new BufferedWriter(new FileWriter(output));
            String pt = br1.readLine();
            System.out.println("Enter the key to encrypt:");
            int key = Integer.parseInt(br.readLine());
            StringBuffer ct = new StringBuffer();

            for (int i = 0; i < pt.length(); i++) {
                if (pt.charAt(i) == ' '){
                    ct.append(" ");
                }
                if (Character.isUpperCase(pt.charAt(i))) {
                    char ch = (char) (((int) pt.charAt(i) + key - 65) % 26 + 65);
                    ct.append(ch);
                } else if (Character.isLowerCase(pt.charAt(i))) {
                    char ch = (char) (((int) pt.charAt(i) + key - 97) % 26 + 97);
                    ct.append(ch);
                } else if (Character.isDigit(pt.charAt(i))) {
                    char ch = (char) (((int) pt.charAt(i) + key - 48) % 10 + 48);
                    ct.append(ch);
                }
            }
            or.write("Cipher text is: " + ct);
            or.close();
        }

        //DECRYPTION
        else if (n == 2) {
            BufferedReader br1 = new BufferedReader(new FileReader(input));
            BufferedWriter or = new BufferedWriter(new FileWriter(output));
            String ct = br1.readLine();
            System.out.println("Enter the key to decrypt:");
            int key = Integer.parseInt(br.readLine());
            StringBuffer pt = new StringBuffer();

            for (int i = 0; i < ct.length(); i++) {
                if (ct.charAt(i) == ' '){
                    pt.append(" ");
                }
                if (Character.isUpperCase(ct.charAt(i))) {
                    char ch = (char) (((int) ct.charAt(i) - 68) % 26 + 65);
                    pt.append(ch);
                } else if (Character.isLowerCase(ct.charAt(i))) {
                    char ch = (char) (((int) ct.charAt(i) - key - 97) % 26 + 97);
                    pt.append(ch);
                } else if (Character.isDigit(ct.charAt(i))) {
                    char ch = (char) (((int) ct.charAt(i) - key - 48) % 10 + 48);
                    pt.append(ch);
                }
            }
            or.write("Plain text is: " + pt);
            or.close();
        }

        //BRUTEFORCE ATTACK
        else if (n == 3) {
            Basic b = new Basic();
            BufferedReader br1 = new BufferedReader(new FileReader(input));
            BufferedWriter or = new BufferedWriter(new FileWriter(output));
            String ct = br1.readLine();
            ct = ct.toUpperCase();

            for (int k = 0; k < 26; k++) {
                String decryptedText = "";
                int key = k;
                for (int i = 0; i < ct.length(); i++) {
                    int index = b.indexOfChar(ct.charAt(i));

                    if (index == -1) {
                        decryptedText += ct.charAt(i);
                        continue;
                    }
                    if ((index - key) >= 0) {
                        decryptedText += b.charAtIndex(index - key);
                    } else {
                        decryptedText += b.charAtIndex((index - key) + 26);
                    }
                }
                or.write("Decrypted Text Using key" + key + ":" + decryptedText);
                or.newLine();
            }
            or.close();
        }

        //FREQUENCY ANALYSIS ATTACK
        else {
            BufferedReader br1 = new BufferedReader(new FileReader(input));
            BufferedWriter or = new BufferedWriter(new FileWriter(output));
            String ct = br1.readLine();
            String dt = ct;
            int[] arr = new int[26];
            Arrays.fill(arr, 0);
            ct = ct.toLowerCase();
            ct = ct.replaceAll("\\s", "");

            for (int i = 0; i < ct.length(); i++) {
                arr[(ct.charAt(i)) - 'a']++;
            }

            HashMap<Integer, Integer> hm = new HashMap<>();
            for (int i = 0; i < arr.length; i++) {
                if (arr[i] != 0) {
                    if (!hm.containsKey(i)) {
                        hm.put(i, arr[i]);
                    }
                }
            }

            int freq = 4;
            int max = 0;
            int key = 0;
            StringBuffer pt = new StringBuffer();

            int loop = hm.keySet().size();
            for (int i = 0; i < loop; i++) {
                max = maxMap(hm);
                hm.remove(max);
                if (max - freq >= 0) {
                    key = max - freq;
                } else {
                    key = 26 - (freq - max);
                }
                char ch = 'a';
                for (int j = 0; j < dt.length(); j++) {
                    if (dt.charAt(j) == ' '){
                        pt.append(" ");
                    }
                    if (Character.isLowerCase(dt.charAt(j))) {
                        if (key > (int) dt.charAt(j))
                            ch = (char) (((int) dt.charAt(j) - key - 97) % 26 + 97);
                        else
                            ch = (char) (((((int) dt.charAt(j) - key) - 97 + 26) % 26) % 26 + 97);

                        pt.append(ch);
                    }
                }

                or.write("Plain text with key '" + key + "' : " + pt);
                or.newLine();
                pt.delete(0, pt.length());
            }
            or.close();
        }
    }

    static int maxMap(HashMap<Integer, Integer> map) {
        int max = Integer.MIN_VALUE;
        int ret = 0;
        for (int t : map.keySet()) {
            if (map.get(t) > max) {
                max = map.get(t);
                ret = t;
            }
        }
        return ret;
    }
}