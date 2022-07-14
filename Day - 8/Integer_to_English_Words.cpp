//T.C -: O(1) S.C -: (log(n))
class Solution {
public:
    string convertToString(int n){
        string ones[20] = 
        {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",                 "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tens[10] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        if(n >= 1000000000) return convertToString(n/1000000000) + " Billion" + convertToString(n % 1000000000);
        if(n >= 1000000) return convertToString(n/1000000) + " Million" + convertToString(n % 1000000);
        if(n >= 1000) return convertToString(n/1000) + " Thousand" + convertToString(n % 1000);
        if(n >= 100) return convertToString(n/100) + " Hundred" + convertToString(n % 100);
        if(n >= 20) return " " + tens[n / 10 - 2 ] + convertToString(n % 10) ;
        if(n >= 1) return " " + ones[n];
        return "";
    }
    
    string numberToWords(int n) {
        if(n == 0) return "Zero";
        return convertToString(n).substr(1);  
    }
};