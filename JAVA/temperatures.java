import java.math.*;

class Solution {
    
    static double closestToZero(double[] ts) {
        double t = 5526;
        
        if(ts.length == 0)
            return 0;
        for (double temp:ts){
            if (Math.abs(temp) <= Math.abs(t))
                if (Math.abs(t) - Math.abs(temp) == 0)
                    t = Math.max(t, temp);
                else
                    t = temp;
        }
        return t;
	}
}
