package udf;
import java.util.*;
import java.lang.*;
import java.io.*;

import java.io.IOException;
import org.apache.pig.EvalFunc;
import org.apache.pig.data.Tuple;
import org.apache.pig.data.DataBag;
import org.apache.pig.data.DataType;

public class Hfilter extends EvalFunc<String>
{
    String path;
    String fname;
    String hset[];
    ArrayList<Long> lookupset  = new ArrayList<Long>(10000);
    private boolean bsearch(Long element){
        int left = 0;
        int right = lookupset.size() - 1;
        int mid = 0;
        while(left < right){
            mid = (left + right) / 2;
            if((element - lookupset.get(mid)) == 0){
                return true;
            }
            if(element < lookupset.get(mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    } 
    public Hfilter(String path, String fname) {
        this.path = path;
        this.fname = fname;
        FileReader fr = null;
        try {
            fr = new FileReader(path+ "/" + fname);
        }
        catch(Exception e){
            System.out.println("Failed to open file "+ fname);
            System.out.println(e);

        }
        BufferedReader br = new BufferedReader(fr);
        String line;

        try{
            while ((line = br.readLine()) != null) {
                hset = line.split("\t");
            }
            for(String val:hset){
                lookupset.add(Long.parseLong(val));
            }
        }
        catch(Exception e){
            System.out.println("Error while reading and creating hashmap file "+ fname);
            System.out.println(e);

        }

    }

    public String exec(Tuple input) throws IOException {
        if (input == null || input.size() == 0)
            return null;
        try{
            Long id = Long.parseLong(DataType.toString(input.get(0)));
            //System.out.println("Find := "+ id % 1000000);
            return (bsearch(id % 1000000) ? "T" : "F");
        }catch(Exception e){
            throw new IOException("Caught exception processing input row ", e);
        }
    }
}
