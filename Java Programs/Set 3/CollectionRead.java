// Making A Collection Read Only in Java - 13.

import java.util.*;

public class CollectionRead {
    public static void main(String[] args){
        List<String> originalList = new ArrayList<String>();
        originalList.add("Pranav");
        originalList.add("Mike");
        originalList.add("Harvey");
        originalList.add("Donna");
        originalList.add("Rachel");
        
        System.out.println("=========== Original List ===========");
        System.out.println(originalList);

        // Making a Collection ReadOnly.
        List readOnlyList = Collections.unmodifiableList(originalList);
        System.out.println("=========== Read Only List ===========");
        System.out.println(readOnlyList);

        try{
            readOnlyList.add("AnyName");  
            readOnlyList.remove("Mike");
            readOnlyList.set(1, "NameChanged");
        }
        catch (Exception e){
            System.out.println("====== Modification operations on read only list not allowed ======");
        }
        originalList.add("AnyName");
        originalList.remove("Mike");
        originalList.set(1, "NameChanged");
        System.out.println("====== Modifications to original list are reflected in read only list ======");
        System.out.println("=========== Read Only List ===========");
        System.out.println(readOnlyList);
    }
}



