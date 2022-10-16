import java.util.*;
class dub_has
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter");
        String s = sc.next();
        HashMap<Character,Integer> hm = new HashMap<>();
        char c[] = s.toCharArray();
        for(char i:c)
        {
            if(hm.containsKey(i))
            {
                hm.put(i,hm.get(i)+1);
            }
            else
            {
                hm.put(i,1);
            }
        }
        System.out.println(hm.keySet());
    }
}
