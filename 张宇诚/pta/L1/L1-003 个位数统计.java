import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.next();
        Map<Character, Integer> map = new TreeMap<>();
        for(int i = 0; i < str.length(); i += 1)
        {
            char c = str.charAt(i);
            if(map.containsKey(c))
            {
                map.put(c, map.get(c) + 1);
            }
            else map.put(c, 1);
        }
        for(Map.Entry<Character, Integer> entry : map.entrySet())
        {
            System.out.println(String.valueOf(entry.getKey()) + ":" + String.valueOf(entry.getValue()));
        }
    }
}