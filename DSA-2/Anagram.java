
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Hashtable;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Anagram {

    private static ArrayList<ArrayList<String>> anagram(ArrayList<String> list) {

	Hashtable<Hashtable<Character, Integer>, ArrayList<String>> htable = new Hashtable<>();
        list.forEach((str)->{
            Hashtable<Character, Integer> ht = new Hashtable<>();
            for(int i=0;i<str.length(); i++){
                if(ht.containsKey(str.charAt(i))){
                    int n = ht.get(str.charAt(i));
                    ht.put(str.charAt(i), ++n);
                }else{
                    ht.put(str.charAt(i),1);
                }
            }

            if(htable.containsKey(ht)){
                htable.get(ht).add(str);
            }else{
                ArrayList<String> words = new ArrayList<>();
                words.add(str);
                htable.put(ht, words);
            }
        });

        ArrayList<ArrayList<String>> anag = new ArrayList<>();

        htable.keySet().forEach((temp)->{
	    if(htable.get(temp).size() > 1){
                anag.add(htable.get(temp));
	    }
        });
        return anag;
    }

    public static void main(String[] args) throws FileNotFoundException,IOException{

        ArrayList<String> arr;
        try (Scanner s = new Scanner(new File("wordlist.txt"))){
            arr = new ArrayList<>();

            while(s.hasNext()){
                arr.add(s.next());
                Collections.sort(arr);
            }
        }

        String hash = anagram(arr).toString()
                .replace(",", "")
                .replace("[", "")
                .replace("]", "\n");

        System.out.println(hash);


    }


}